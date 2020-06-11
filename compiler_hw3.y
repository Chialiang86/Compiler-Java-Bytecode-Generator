/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    //#define YYDEBUG 1
    //int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    static FILE * fout;
    static int branch_cnt;
    static int branch_if_cnt[16];
    static int branch_out_cnt[16];

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    table tb;

    /* Id Info API*/
    static void parse_type(const char * typeAddr, char ** type);
    static int parse_addr(const char * typeAddr);
    int store_id;
    char * store_type;
    
    bool print_flag;
    bool if_flag;
    bool for_flag;
    bool left;

    /* Type checking*/
    static char conversion_code(const char * type);
    static void type_checking(const char * type1, const char * type2, const char * op);
    static bool is_add_mul_op(const char * op);
    static bool is_assign_op(const char * op);
    static bool is_logical_op(const char * op);
    static char * type_remove_lit(const char * type);

    static void condition_checking(const char * type);
    
    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static void insert_symbol(char * n, char * t, char * et);
    static bool lookup_symbol(char * s, char ** type);
    static int lookup_addr(char * s);
    static void dump_symbol(); 
    static void initTable(table * src, const unsigned addrMax, const unsigned indexMax);
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    bool b_val;    
}

/* Token without return */
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token NEWLINE
%token PRINT PRINTLN
%token IF ELSE FOR


/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> BOOL_LIT
%token <s_val> IDENTIFIER
%token <s_val> VAR
%token <s_val> INC DEC
%token <s_val> GEQ LEQ EQL NEQ LAND LOR
%token <s_val> INT FLOAT BOOL STRING

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type TypeName ArrayType
%type <s_val> Expression Expression2 Expression3 Expression4 Expression5 
%type <s_val> Condition
%type <s_val> UnaryExpr PrimaryExpr Operand IndexExpr ConversionExpr Literal Identifier
%type <s_val> IncDec
%type <s_val> LOROp LANDOp CpOp AddOp MulOp UnaryOp AssignOp 

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList
    ;

StatementList
    : StatementList Statement
    | Statement
;

Statement
    : DeclarationStmt NEWLINE
    | SimpleStmt NEWLINE
    | Block NEWLINE
    | IfStmt NEWLINE
    | ForStmt NEWLINE
    | PrintStmt NEWLINE
    | NEWLINE
    ;

SimpleStmt
    : AssignmentStmt
    | ExpressionStmt
    ;

DeclarationStmt
    : VAR IDENTIFIER TypeName '=' Expression 
    { 
        insert_symbol($2, $3, NULL);
        if(strcmp("int32", $3) == 0 || strcmp("bool", $3) == 0){
            fprintf(fout, "istore %d\n", lookup_addr($2));
        } else if(strcmp("float32", $3) == 0){
            fprintf(fout, "fstore %d\n", lookup_addr($2));
        } else if(strcmp("string", $3) == 0){
            fprintf(fout, "astore %d\n", lookup_addr($2));
        }
    }
    | VAR IDENTIFIER ArrayType '=' Expression 
    { 
        insert_symbol($2, "array", $3);    
        fprintf(fout, "newarray %s\n", $3);
        fprintf(fout, "astore %d\n", lookup_addr($2));
    }
    | VAR IDENTIFIER TypeName
    { 
        insert_symbol($2, $3, NULL);
        if(strcmp("int32", $3) == 0 || strcmp("bool", $3) == 0){
            fprintf(fout, "ldc 0\n");// initialization
            fprintf(fout, "istore %d\n", lookup_addr($2));
        } else if(strcmp("float32", $3) == 0){
            fprintf(fout, "ldc 0.000000\n");// initialization
            fprintf(fout, "fstore %d\n", lookup_addr($2));
        } else if(strcmp("string", $3) == 0){
            fprintf(fout, "ldc \"\"\n");// initialization
            fprintf(fout, "astore %d\n", lookup_addr($2));
        }
    }
    | VAR IDENTIFIER ArrayType
    { 
        insert_symbol($2, "array", $3);
        fprintf(fout, "newarray %s\n", $3);
        fprintf(fout, "astore %d\n", lookup_addr($2));
    }
    ;

AssignmentStmt 
    : Expression AssignOp 
    { 
        store_type = NULL; 
        parse_type($1, &store_type); 
        store_id = parse_addr($1);
        if(strcmp("ASSIGN", $2) != 0){
            if(strcmp("int32", store_type) == 0){
                fprintf(fout, "iload %d\n", store_id);
            } else if(strcmp("float32", store_type) == 0){
                fprintf(fout, "fload %d\n", store_id);
            }
        }
    } 
      Expression
    {
        left = true;
        char * type;
        parse_type($4, &type);
        printf("Assign %s %s %s\n", $1, $2, $4);
        type_checking(store_type, type, $2);
        if(strcmp("ASSIGN", $2) == 0){
            if(strcmp("int32", store_type) == 0 || strcmp("INT_LIT", store_type) == 0)
                fprintf(fout, "istore %d\n", store_id);
            else if(strcmp("float32", store_type) == 0 || strcmp("FLOAT_LIT", store_type) == 0)
                fprintf(fout, "fstore %d\n", store_id);
            else if(strcmp("string", store_type) == 0 || strcmp("STRING_LIT", store_type) == 0)
                fprintf(fout, "astore %d\n", store_id);
            else if(strcmp("bool", store_type) == 0 || strcmp("BOOL_LIT", store_type) == 0)
                fprintf(fout, "istore %d\n", store_id);
        } else if(strcmp("ADD_ASSIGN", $2) == 0){
            if(strcmp("int32", store_type) == 0 || strcmp("INT_LIT", store_type) == 0){
                fprintf(fout, "iadd\n");
                fprintf(fout, "istore %d\n", store_id);
            } else if(strcmp("float32", store_type) == 0 || strcmp("FLOAT_LIT", store_type) == 0){
                fprintf(fout, "fadd\n");
                fprintf(fout, "fstore %d\n", store_id);
            } 
        } else if(strcmp("SUB_ASSIGN", $2) == 0){
            if(strcmp("int32", store_type) == 0 || strcmp("INT_LIT", store_type) == 0){
                fprintf(fout, "isub\n");
                fprintf(fout, "istore %d\n", store_id);
            } else if(strcmp("float32", store_type) == 0 || strcmp("FLOAT_LIT", store_type) == 0){
                fprintf(fout, "fsub\n");
                fprintf(fout, "fstore %d\n", store_id);
            }
        } else if(strcmp("MUL_ASSIGN", $2) == 0){
            if(strcmp("int32", store_type) == 0 || strcmp("INT_LIT", store_type) == 0){
                fprintf(fout, "imul\n");
                fprintf(fout, "istore %d\n", store_id);
            } else if(strcmp("float32", store_type) == 0 || strcmp("FLOAT_LIT", store_type) == 0){
                fprintf(fout, "fmul\n");
                fprintf(fout, "fstore %d\n", store_id);
            } 
        } else if(strcmp("QUO_ASSIGN", $2) == 0){
            if(strcmp("int32", store_type) == 0 || strcmp("INT_LIT", store_type) == 0){
                fprintf(fout, "idiv\n");
                fprintf(fout, "istore %d\n", store_id);
            } else if(strcmp("float32", store_type) == 0 || strcmp("FLOAT_LIT", store_type) == 0){
                fprintf(fout, "fdiv\n");
                fprintf(fout, "fstore %d\n", store_id);
            }
        } else if(strcmp("REM_ASSIGN", $2) == 0){
            if(strcmp("int32", store_type) == 0 || strcmp("INT_LIT", store_type) == 0){
                fprintf(fout, "irem\n");
                fprintf(fout, "istore %d\n", store_id);
            } else if(strcmp("float32", store_type) == 0 || strcmp("FLOAT_LIT", store_type) == 0){
                fprintf(fout, "frem\n");
                fprintf(fout, "fstore %d\n", store_id);
            }
        } 
        printf("%s\n", $2);
    }
    ;

AssignOp
    : '=' { $$ = "ASSIGN"; left = false;}
    | ADD_ASSIGN { $$ = "ADD_ASSIGN"; left = false;}
    | SUB_ASSIGN { $$ = "SUB_ASSIGN"; left = false;}
    | MUL_ASSIGN { $$ = "MUL_ASSIGN"; left = false;}
    | QUO_ASSIGN { $$ = "QUO_ASSIGN"; left = false;}
    | REM_ASSIGN { $$ = "REM_ASSIGN"; left = false;}
    ;

ExpressionStmt
    : Expression

Block 
    : '{' { create_symbol(); } StatementList '}' { dump_symbol();}
    ;

IfStmt 
    : IfConditionBlock 
    {
        fprintf(fout, "branch_out_%d_%d:\n", tb.levelNum, branch_out_cnt[tb.levelNum]); //false
        branch_out_cnt[tb.levelNum] += 1;
    }
    | IfConditionBlock ELSE IfStmt
    { 
        fprintf(fout, "branch_out_%d_%d:\n", tb.levelNum, branch_out_cnt[tb.levelNum]); //false
        branch_out_cnt[tb.levelNum] += 1;
    }
    | IfConditionBlock ELSE Block
    {
        fprintf(fout, "branch_out_%d_%d:\n", tb.levelNum, branch_out_cnt[tb.levelNum]); //false
        branch_out_cnt[tb.levelNum] += 1;
    }
    ;

IfConditionBlock 
    : IF {if_flag = true;} Condition Block
    {
        if_flag = false;
        fprintf(fout, "goto branch_out_%d_%d\n", tb.levelNum, branch_out_cnt[tb.levelNum]); //false
        fprintf(fout, "branch_if_%d_%d:\n", tb.levelNum, branch_if_cnt[tb.levelNum]); //false
        branch_if_cnt[tb.levelNum] += 1;
    } 
    ;

Condition 
    : Expression 
    { 
        $$ = $1; 
        condition_checking($$);
        fprintf(fout, "ifeq branch_if_%d_%d\n", tb.levelNum, branch_if_cnt[tb.levelNum]); //false
    }
    ;

ForStmt
    : FOR Condition Block
    | FOR ForClause Block
    ;

ForClause
    : InitStmt ';' Condition ';' PostStmt
    ;

InitStmt
    : SimpleStmt
    ;

PostStmt
    : SimpleStmt
    ;

PrintStmt 
    : PRINT {print_flag = true;} '(' Expression ')' 
    {
        print_flag = false;
        char * type;
        parse_type($4, &type);
        if(strcmp("bool", type) != 0 && strcmp("BOOL_LIT", type) != 0){
            fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fout, "swap\n");
            if(strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0)
                fprintf(fout, "invokevirtual java/io/PrintStream/print(I)V\n");
            else if(strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0)
                fprintf(fout, "invokevirtual java/io/PrintStream/print(F)V\n");
            else if(strcmp("string", type) == 0 || strcmp("STRING_LIT", type) == 0)
                fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        } else if(strcmp("bool", type) == 0 || strcmp("BOOL_LIT", type) == 0){
            fprintf(fout, "ifne branch_%d\n", branch_cnt);
            fprintf(fout, "ldc \"false\"\n");
            fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
            fprintf(fout, "branch_%d:\n", branch_cnt);
            fprintf(fout, "ldc \"true\"\n");
            fprintf(fout, "branch_%d:\n", branch_cnt + 1);
            fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fout, "swap\n");
            fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
            branch_cnt += 2;
        }
        printf("PRINT %s\n", type_remove_lit($4));
    }
    | PRINTLN {print_flag = true;} '(' Expression ')'
    {
        print_flag = false;
        char * type;
        if(strcmp("bool", $4) != 0)
            parse_type($4, &type);
        else
            type = strdup("bool");
        if(strcmp("bool", type) != 0 && strcmp("BOOL_LIT", type) != 0){
            fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fout, "swap\n");
            if(strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0)
                fprintf(fout, "invokevirtual java/io/PrintStream/println(I)V\n");
            else if(strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0)
                fprintf(fout, "invokevirtual java/io/PrintStream/println(F)V\n");
            else if(strcmp("string", type) == 0 || strcmp("STRING_LIT", type) == 0)
                fprintf(fout, "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        } else if(strcmp("bool", type) == 0 || strcmp("BOOL_LIT", type) == 0){
            fprintf(fout, "ifne branch_%d\n", branch_cnt);
            fprintf(fout, "ldc \"false\"\n");
            fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
            fprintf(fout, "branch_%d:\n", branch_cnt);
            fprintf(fout, "ldc \"true\"\n");
            fprintf(fout, "branch_%d:\n", branch_cnt + 1);
            fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fout, "swap\n");
            fprintf(fout, "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
            branch_cnt += 2;
        }
        printf("PRINTLN %s\n", type_remove_lit($4));
    }
    ;

Type 
    : TypeName
    | ArrayType
    ;

TypeName
    : INT {$$ = "int32";}
    | FLOAT {$$ = "float32";}
    | STRING {$$ = "string";}
    | BOOL {$$ = "bool";}
    ;

ArrayType
    : '[' Expression ']' Type 
    {
        $$ = $4;
        char * type = NULL;
        if(strcmp("bool", $2) != 0)
            parse_type($2, &type);
        else 
            type = strdup("bool");
        if(strcmp("float32", type) == 0 || strcmp("float32", type) == 0 ||
           strcmp("string", type) == 0 || strcmp("STRING_LIT", type) == 0){
            printf("you put a strange type into the index of an array!!!\n");
        }

    }
    ;

Expression
    : Expression LOROp Expression2 
    {
        printf("%s\n", $2); 
        char * type1 = NULL;
        char * type3 = NULL;
        parse_type($1, &type1);
        parse_type($3, &type3);
        type_checking(type1, type3, $2);
        fprintf(fout, "ior\n");
        $$ = "bool -1";
    }
    | Expression2  
    ;

LOROp
    : LOR { $$ = "LOR";}
    ;

Expression2 
    : Expression2 LANDOp Expression3 
    { 
        char * type1 = NULL;
        char * type3 = NULL;
        parse_type($1, &type1);    
        parse_type($3, &type3);
        type_checking(type1, type3, $2);
        printf("%s\n", $2); 
        fprintf(fout, "iand\n");
        $$ = "bool -1";
    }
    | Expression3
    ;

LANDOp
    : LAND { $$ = "LAND";}
    ;

Expression3
    : Expression3 CpOp Expression4
    { 
        char * type1 = NULL;
        char * type3 = NULL;
        parse_type($1, &type1);
        parse_type($3, &type3);
        printf("%s\n", $2); 
        if(strcmp("GTR", $2) == 0 || strcmp("LEQ", $2) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "isub\n");
                fprintf(fout, "ifgt branch_%d\n", branch_cnt);
                fprintf(fout, strcmp("LEQ", $2) == 0 ? "iconst_1\n" : "iconst_0\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, strcmp("LEQ", $2) == 0 ? "iconst_0\n" : "iconst_1\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            }
            else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
               (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fcmpl\n");
                fprintf(fout, "ifgt branch_%d\n", branch_cnt);
                fprintf(fout, strcmp("LEQ", $2) == 0 ? "iconst_1\n" : "iconst_0\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, strcmp("LEQ", $2) == 0 ? "iconst_0\n" : "iconst_1\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            }
        } else if(strcmp("LSS", $2) == 0 || strcmp("GEQ", $2) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "isub\n");
                fprintf(fout, "iflt branch_%d\n", branch_cnt);
                fprintf(fout, strcmp("LSS", $2) == 0 ? "iconst_0\n" : "iconst_1\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, strcmp("LSS", $2) == 0 ? "iconst_1\n" : "iconst_0\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
               (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fcmpl\n");
                fprintf(fout, "iflt branch_%d\n", branch_cnt);
                fprintf(fout, strcmp("LSS", $2) == 0 ? "iconst_0\n" : "iconst_1\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, strcmp("LSS", $2) == 0 ? "iconst_1\n" : "iconst_0\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            }
        } else if(strcmp("EQL", $2) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "isub\n");
                fprintf(fout, "ifeq branch_%d\n", branch_cnt);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
               (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fcmpl\n"); 
                fprintf(fout, "ifeq branch_%d\n", branch_cnt);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
           } 
        }
        $$ = "bool -1";
    }
    | Expression4 
    ;

CpOp
    : '<' { $$ = "LSS";}
    | '>' { $$ = "GTR";}
    | LEQ { $$ = "LEQ";}
    | GEQ { $$ = "GEQ";}
    | EQL { $$ = "EQL";}
    | NEQ { $$ = "NEQ";}
    ;

Expression4 
    : Expression4 AddOp Expression5
    {
        char * type1 = NULL;
        char * type3 = NULL;
        parse_type($1, &type1);
        parse_type($3, &type3);
        type_checking(type1, type3, $2);
        printf("%s\n", $2);
        if(strcmp("ADD", $2) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "iadd\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fadd\n");
            }
        } else if(strcmp("SUB", $2) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "isub\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fsub\n");
            }
        }
        
    }
    | Expression5
    ;

AddOp
    : '+' { $$ = "ADD";}
    | '-' { $$ = "SUB";}
    ;

Expression5 
    : Expression5 MulOp UnaryExpr 
    {
        char * type1 = NULL;
        char * type3 = NULL;
        parse_type($1, &type1);
        parse_type($3, &type3);
        type_checking(type1, type3, $2);
        printf("%s\n", $2);
        if(strcmp("MUL", $2) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT",type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "imul\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fmul\n");
            }
        } else if(strcmp("QUO", $2) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "idiv\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fdiv\n");
            }
        } else if(strcmp("REM", $2) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "irem\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "frem\n");
            } // frem is legal?
        }
    }
    | UnaryExpr
    ;

MulOp
    : '*' { $$ = "MUL";}
    | '/' { $$ = "QUO";}
    | '%' { $$ = "REM";}
    ;

UnaryExpr 
    : PrimaryExpr
    | UnaryOp UnaryExpr 
    { 
        $$ = $2; 
        char * type = NULL;
        parse_type($2, &type);
        printf("%s\n", $1);
        if(strcmp("NEG", $1) == 0){
            if(strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0){
                fprintf(fout, "ineg\n");
            } else if(strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0){
                fprintf(fout, "fneg\n");
            }
        } else if(strcmp("NOT", $1) == 0){
            if(strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0 ||
               strcmp("bool", type) == 0 || strcmp("BOOL_LIT", type) == 0){
                fprintf(fout, "ixor\n");
            } 
        }
    } 
    | UnaryExpr IncDec 
    { 
        $$ = $1; 
        char * type = NULL;
        parse_type($1, &type);
        printf("%s\n", $2);
        printf("this is : %s\n", type);
        if(strcmp("INC", $2) == 0 &&
          (strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0)){
            fprintf(fout, "iload %d\n", parse_addr($1));
            fprintf(fout, "ldc 1\n");
            fprintf(fout, "iadd\n");
            fprintf(fout, "istore %d\n", parse_addr($1));
        } else if(strcmp("DEC", $2) == 0 &&
          (strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0)){
            fprintf(fout, "iload %d\n", parse_addr($1));
            fprintf(fout, "ldc 1\n");
            fprintf(fout, "isub\n");
            fprintf(fout, "istore %d\n", parse_addr($1));
        } else if(strcmp("INC", $2) == 0 &&
          (strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0)){
            fprintf(fout, "fload %d\n", parse_addr($1));
            fprintf(fout, "ldc 1.000000\n");
            fprintf(fout, "fadd\n");
            fprintf(fout, "fstore %d\n", parse_addr($1));
        } else if(strcmp("DEC", $2) == 0 &&
          (strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0)){
            fprintf(fout, "fload %d\n", parse_addr($1));
            fprintf(fout, "ldc 1.000000\n");
            fprintf(fout, "fsub\n");
            fprintf(fout, "fstore %d\n", parse_addr($1));
        } else
            printf("IncDec error %s %s\n", $1, $2);
    } 
    ;

IncDec
    : INC { $$ = "INC"; }
    | DEC { $$ = "DEC"; }
    ;

UnaryOp
    : '+' {$$ = "POS";}
    | '-' {$$ = "NEG";}
    | '!' {$$ = "NOT"; fprintf(fout, "iconst_1\n"); /*for not operator*/}
    ;

PrimaryExpr 
    : Operand
    | IndexExpr
    | ConversionExpr
    ;

Operand 
    : Literal
    | Identifier 
    | '(' Expression ')' { $$ = $2;}
    ;

Identifier
    : IDENTIFIER
    {
        bool is_array; 
        char * type = NULL;
        char typeAddr[20];
        is_array = lookup_symbol($1, &type);
        sprintf(typeAddr, "%s %d", type, lookup_addr($1));
        if(typeAddr != NULL)
            $$ = typeAddr;
        else
            $$ = strdup("XXX");
        if(print_flag || if_flag || for_flag){
            if(!is_array){
                if(strcmp("string", type) == 0)
                    fprintf(fout, "aload %d\n", parse_addr(typeAddr));
                if(strcmp("int32", type) == 0 || strcmp("bool", type) == 0)
                    fprintf(fout, "iload %d\n", parse_addr(typeAddr));
                if(strcmp("float32", type) == 0)
                    fprintf(fout, "fload %d\n", parse_addr(typeAddr));
            } else {
                fprintf(fout, "aload %d\n", parse_addr(typeAddr));
            }
        } else {
            if(!left){
                if(!is_array){
                    if(strcmp("string", type) == 0)
                        fprintf(fout, "aload %d\n", parse_addr(typeAddr));
                    if(strcmp("int32", type) == 0 || strcmp("bool", type) == 0)
                        fprintf(fout, "iload %d\n", parse_addr(typeAddr));
                    if(strcmp("float32", type) == 0)
                        fprintf(fout, "fload %d\n", parse_addr(typeAddr));
                } else {
                    fprintf(fout, "aload %d\n", parse_addr(typeAddr));
                }
            }
        }
    }
    ;

Literal
    : INT_LIT 
    {
        printf("INT_LIT %d\n", $1);
        fprintf(fout, "ldc %d\n", $1);
        $$ = "INT_LIT -1";
    }
    | FLOAT_LIT 
    {   
        fprintf(fout, "ldc %.6f\n", $1);
        $$ = "FLOAT_LIT -1";
    }
    | '"' STRING_LIT '"' 
    { 
        printf("STRING_LIT %s\n", $2); 
        fprintf(fout, "ldc \"%s\"\n", $2);
        $$ = "STRING_LIT -1";
    }
    | BOOL_LIT 
    {
        if(strcmp($1, "true") == 0){
            printf("TRUE\n");
            fprintf(fout, "iconst_1\n"); // iconst_1
        } else if(strcmp($1, "false") == 0){
            printf("FALSE\n");
            fprintf(fout, "iconst_0\n"); // iconst_0
        } else {
            printf("BOOL_LIT BUG!!\n");
        }
        $$ = "BOOL_LIT -1";
    }
    ;

IndexExpr
    : PrimaryExpr '[' Expression ']' 
    { 
        $$ = $1;
        char * type = NULL;
        parse_type($1, &type);
        if(strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0 ||
           strcmp("string", type) == 0 || strcmp("STRING_LIT", type) == 0){
            printf("you put a strange type into the index of an array!!!\n");
        }
    }
    ;

ConversionExpr 
    : Type '(' Expression ')' 
    { 
        char typeAddr[20];
        char * type3;
        parse_type($3, &type3);
        printf("%c to %c\n", conversion_code(type3), conversion_code($1));
        if((strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0) &&
           (strcmp("float32", $1) == 0 || strcmp("FLOAT_LIT", $1) == 0))
            fprintf(fout, "i2f\n");
        else if((strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0) &&
           (strcmp("int32", $1) == 0 || strcmp("INT_LIT", $1) == 0))
            fprintf(fout, "f2i\n");
        sprintf(typeAddr, "%s %d", $1, parse_addr($3));
        printf("convert-------- typeaddr:%s convertTo:%s \n", typeAddr, type3);
        $$ = strdup(typeAddr);
    }
    ;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    fout = fopen("hw3.j","w");
    if(!fout){
        printf("hw3.j open error!\n");
        exit(0);
    }
    fprintf(fout, ".source hw3.j\n");
    fprintf(fout, ".class public Main\n");
    fprintf(fout, ".super java/lang/Object\n");
    fprintf(fout, ".method public static main([Ljava/lang/String;)V\n");
    fprintf(fout, ".limit stack 100\n");
    fprintf(fout, ".limit locals 100\n");
    
    int i;
    print_flag = false;
    if_flag = false;
    for_flag =  false;
    left = true;
    store_id = -1;
    store_type = strdup("null");
    
    initTable(&tb, 256, 16);
    yylineno = 0;
    branch_cnt = 0;
    for( i = 0; i < 16; ++i) branch_if_cnt[i] = 0;
    for( i = 0; i < 16; ++i) branch_out_cnt[i] = 0;
    
    yyparse();
    dump_symbol();
	printf("Total lines: %d\n", yylineno);
    fprintf(fout, "return\n");
    fprintf(fout, ".end method\n");
    fclose(fout);
    fclose(yyin);
    return 0;
}

static void parse_type(const char * typeAddr, char ** type){
    int nouse = 0;
    *type = (char *)malloc(sizeof(char) * 32);
    sscanf(typeAddr, "%s %d", *type, &nouse);
}

static int parse_addr(const char * typeAddr){
    char nouse[20];
    int addr;
    sscanf(typeAddr, "%s %d", nouse, &addr);
    return addr;
}

static void create_symbol() {
    if(tb.levelNum < 16 && tb.indexNum[tb.levelNum] != 0)
        printf("Create symbol error: init level %d index != 0\n", tb.levelNum);
    else if(tb.levelNum >= 16)
        printf("Out of level num: 16\n");
    tb.levelNum += 1;
}

static void insert_symbol(char * n, char * t, char * et) {
    int i, ln = tb.levelNum - 1, in = tb.indexNum[tb.levelNum - 1], an = tb.addrNum;
    tb.tf[ln][in].level = ln;
    tb.tf[ln][in].index = in;
    tb.tf[ln][in].name = strdup(n);
    tb.tf[ln][in].type = strdup(t);
    tb.tf[ln][in].addr = an;
    tb.tf[ln][in].lineno = yylineno;
    for(i = 0; i < tb.indexNum[ln]; ++i){
        if(strcmp(tb.tf[ln][i].name, n) == 0){
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",
                    yylineno, n,tb.tf[ln][i].lineno);
                    return;
        }
    }
    if(et != NULL)
        tb.tf[ln][in].elementType = strdup(et);
    else 
        tb.tf[ln][in].elementType = strdup("-");
    printf("> Insert {%s} into symbol table (scope level: %d)\n", 
        tb.tf[ln][in].name, tb.tf[ln][in].level);
    tb.indexNum[ln]++;
    tb.addrNum++;
}

static int lookup_addr(char * s){
    int i, j, index;
    int level = tb.levelNum - 1;
    for(i = level; i >= 0; --i){
        index = tb.indexNum[i];
        for(j = 0; j < index; ++j){
            if(strcmp(s, tb.tf[i][j].name) == 0){
                return tb.tf[i][j].addr;
            }
        }
    }
    return -1;
}

static bool lookup_symbol(char * s, char ** type) {
    int i, j, addr, index;
    int level = tb.levelNum - 1;
    for(i = level; i >= 0; --i){
        index = tb.indexNum[i];
        for(j = 0; j < index; ++j){
            if(strcmp(s, tb.tf[i][j].name) == 0){
                addr = tb.tf[i][j].addr;
                printf("IDENT (name=%s, address=%d)\n", s, addr);
                if(strcmp(tb.tf[i][j].type, "array") == 0){
                    *type = strdup(tb.tf[i][j].elementType);
                    return true;
                }
                else{
                    *type = strdup(tb.tf[i][j].type);
                    return false;
                }
                
            }
        }
    }
    type = NULL;
    printf("error:%d: undefined: %s\n", yylineno + 1, s);
    return false;
}

static void dump_symbol() {
    int level = tb.levelNum - 1;
    int index = tb.indexNum[level];
    int i, addr, lineno;
    char * name, * type, * etype;
    printf("> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(i = 0; i < index; ++i){
        name = tb.tf[level][i].name; 
        type = tb.tf[level][i].type; 
        addr = tb.tf[level][i].addr; 
        lineno = tb.tf[level][i].lineno; 
        etype = tb.tf[level][i].elementType; 
        printf("%-10d%-10s%-10s%-10d%-10d%s\n", 
            i, name, type, addr, lineno, etype);
    }
    memset(&tb.tf[level], 0, sizeof(tb.tf[level]));
    tb.indexNum[level] = 0;
    tb.levelNum --;
}

void initTable(table * src, const unsigned addrMax, const unsigned indexMax){
    unsigned * am = (unsigned *)&src->addrMax;
    unsigned * im = (unsigned *)&src->indexMax;
    (*am) = addrMax;
    (*im) = indexMax;
    src->levelNum = 1;
    src->addrNum = 0;
    memset(src->indexNum, 0, sizeof(src->indexNum));
    memset(src->tf, 0, sizeof(src->tf));
}

static char conversion_code(const char * type){
    if(strcmp(type_remove_lit(type), "int32") == 0)
        return 'I';
    else if(strcmp(type_remove_lit(type), "float32") == 0)
        return 'F';
    else
        printf("convertion type error : %s\n", type);
    return 'X';
}

static void type_checking(const char * type1, const char * type2, const char * op){
    if(strcmp(type1, "XXX") == 0 || strcmp(type2, "XXX") == 0)
        return;
    int correct1 = 0, correct2 = 0;
    correct1 = (strcmp(type1, "int32") == 0) + (strcmp(type1, "float32") == 0) + 
                (strcmp(type1, "string") == 0) + (strcmp(type1, "bool") == 0) +
                (strcmp(type1, "INT_LIT") == 0) + (strcmp(type1, "FLOAT_LIT") == 0) + 
                (strcmp(type1, "STRING_LIT") == 0) + (strcmp(type1, "BOOL_LIT") == 0);
    correct2 = (strcmp(type2, "int32") == 0) + (strcmp(type2, "float32") == 0) + 
                (strcmp(type2, "string") == 0) + (strcmp(type2, "bool") == 0) +
                (strcmp(type2, "INT_LIT") == 0) + (strcmp(type2, "FLOAT_LIT") == 0) + 
                (strcmp(type2, "STRING_LIT") == 0) + (strcmp(type2, "BOOL_LIT") == 0);
    if(!correct1){
        printf("error left type : %s\n", type1);
        return;
    }
    if(!correct2){
        printf("error right type : %s\n", type2);
        return;
    }
    if(is_add_mul_op(op) && strcmp(type_remove_lit(type1), type_remove_lit(type2)) != 0){
        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",
                yylineno, op, type_remove_lit(type1), type_remove_lit(type2));
    } else if(strcmp(op, "REM") == 0 || strcmp(op, "REM_ASSIGN") == 0){
        if(strcmp(type_remove_lit(type1), "float32") == 0 || 
            strcmp(type_remove_lit(type1), "string") == 0){
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", 
                yylineno, op, type_remove_lit(type1));
        }
        if(strcmp(type_remove_lit(type2), "float32") == 0 || 
            strcmp(type_remove_lit(type2), "string") == 0){
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", 
                yylineno, op, type_remove_lit(type2));
        }
    } else if(is_assign_op(op)){
        if(strcmp(type_remove_lit(type1), type1) != 0){
            printf("error:%d: cannot assign to %s\n", yylineno, type_remove_lit(type1));
            return;
        }
        if(is_assign_op(op) && strcmp(type_remove_lit(type1), type_remove_lit(type2)) != 0){
            printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",
                yylineno, op, type_remove_lit(type1), type_remove_lit(type2));
        }
    } else if(is_logical_op(op)){
        if(strcmp(type_remove_lit(type1), "bool") != 0){
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n",
                    yylineno, op, type_remove_lit(type1));
        } else if(strcmp(type_remove_lit(type2), "bool") != 0){
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n",
                    yylineno, op, type_remove_lit(type2));
        }
    }
    
}

static bool is_add_mul_op(const char * op){
    return (strcmp(op, "ADD") == 0) || (strcmp(op, "SUB") == 0) ||
           (strcmp(op, "MUL") == 0) || (strcmp(op, "QUO") == 0);
}

static bool is_assign_op(const char * op){
    return (strcmp(op, "ASSIGN") == 0) || (strcmp(op, "ADD_ASSIGN") == 0) || 
           (strcmp(op, "SUB_ASSIGN") == 0) || (strcmp(op, "MUL_ASSIGN") == 0); 
}

static bool is_logical_op(const char * op){
    return (strcmp(op, "LAND") == 0) || (strcmp(op, "LOR") == 0);
}

static char * type_remove_lit(const char * type){
    char * ans;
    if(strcmp(type, "INT_LIT") == 0){
        ans = strdup("int32");
        return ans;
    } else if(strcmp(type, "FLOAT_LIT") == 0){
        ans = strdup("float32");
        return ans;
    } else if(strcmp(type, "STRING_LIT") == 0){
        ans = strdup("string");
        return ans;
    } else if(strcmp(type, "BOOL_LIT") == 0){
        ans = strdup("bool");
        return ans;
    } else {
        ans = strdup(type);
        return ans;
    }
}

static void condition_checking(const char * type){
    if(strcmp(type, "XXX") == 0)
        return;
    if(strcmp(type_remove_lit(type), "bool") != 0){
        printf("error:%d: non-bool (type %s) used as for condition\n",
            yylineno + 1, type_remove_lit(type));
    }
}

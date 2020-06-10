/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    //#define YYDEBUG 1
    //int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    static FILE * fout;
    static int branch_cnt;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    table tb;

    /* Id Info API*/
    static void parse_type(const char * typeAddr, char ** type);
    static int parse_addr(const char * typeAddr);
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

#line 109 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD_ASSIGN = 258,
    SUB_ASSIGN = 259,
    MUL_ASSIGN = 260,
    QUO_ASSIGN = 261,
    REM_ASSIGN = 262,
    NEWLINE = 263,
    PRINT = 264,
    PRINTLN = 265,
    IF = 266,
    ELSE = 267,
    FOR = 268,
    INT_LIT = 269,
    FLOAT_LIT = 270,
    STRING_LIT = 271,
    BOOL_LIT = 272,
    IDENTIFIER = 273,
    VAR = 274,
    INC = 275,
    DEC = 276,
    GEQ = 277,
    LEQ = 278,
    EQL = 279,
    NEQ = 280,
    LAND = 281,
    LOR = 282,
    INT = 283,
    FLOAT = 284,
    BOOL = 285,
    STRING = 286
  };
#endif
/* Tokens.  */
#define ADD_ASSIGN 258
#define SUB_ASSIGN 259
#define MUL_ASSIGN 260
#define QUO_ASSIGN 261
#define REM_ASSIGN 262
#define NEWLINE 263
#define PRINT 264
#define PRINTLN 265
#define IF 266
#define ELSE 267
#define FOR 268
#define INT_LIT 269
#define FLOAT_LIT 270
#define STRING_LIT 271
#define BOOL_LIT 272
#define IDENTIFIER 273
#define VAR 274
#define INC 275
#define DEC 276
#define GEQ 277
#define LEQ 278
#define EQL 279
#define NEQ 280
#define LAND 281
#define LOR 282
#define INT 283
#define FLOAT 284
#define BOOL 285
#define STRING 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 50 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    bool b_val;    

#line 218 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    48,     2,     2,    46,     2,     2,
      36,    37,    44,    42,     2,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      40,    32,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    94,    95,    99,   100,   101,   102,   103,
     104,   105,   109,   110,   114,   125,   131,   143,   152,   217,
     218,   219,   220,   221,   222,   226,   230,   230,   234,   235,
     236,   240,   244,   245,   249,   253,   257,   261,   261,   291,
     291,   324,   325,   329,   330,   331,   332,   336,   353,   370,
     374,   378,   395,   399,   403,   480,   484,   485,   486,   487,
     488,   489,   493,   522,   526,   527,   531,   565,   569,   570,
     571,   575,   576,   595,   628,   629,   633,   634,   635,   639,
     640,   641,   645,   646,   670,   674,   680,   685,   691,   707,
     723
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "QUO_ASSIGN", "REM_ASSIGN", "NEWLINE", "PRINT", "PRINTLN", "IF", "ELSE",
  "FOR", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "BOOL_LIT", "IDENTIFIER",
  "VAR", "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ", "LAND", "LOR", "INT",
  "FLOAT", "BOOL", "STRING", "'='", "'{'", "'}'", "';'", "'('", "')'",
  "'['", "']'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "'\"'", "$accept", "Program", "StatementList", "Statement", "SimpleStmt",
  "DeclarationStmt", "AssignmentStmt", "AssignOp", "ExpressionStmt",
  "Block", "$@1", "IfStmt", "Condition", "ForStmt", "ForClause",
  "InitStmt", "PostStmt", "PrintStmt", "$@2", "$@3", "Type", "TypeName",
  "ArrayType", "Expression", "LOROp", "Expression2", "LANDOp",
  "Expression3", "CpOp", "Expression4", "AddOp", "Expression5", "MulOp",
  "UnaryExpr", "IncDec", "UnaryOp", "PrimaryExpr", "Operand", "Literal",
  "IndexExpr", "ConversionExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    61,   123,   125,    59,    40,    41,    91,    93,
      60,    62,    43,    45,    42,    47,    37,    33,    34
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      98,   -46,   -46,   -46,   133,   133,   -46,   -46,   -46,   -46,
      -6,   -46,   -46,   -46,   -46,   -46,   133,   133,   -46,   -46,
     -46,    23,    44,    98,   -46,    65,    66,   -46,   -46,    69,
      75,    77,    80,    17,   -46,   -46,    57,    70,    46,    -9,
      35,    26,   133,    27,   -46,   -46,   -46,   -46,    59,    64,
      72,    83,   -46,    72,    72,    67,    24,    63,    98,    15,
     -20,    71,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     133,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   133,   133,
     -46,   133,   -46,   -46,   -46,   -46,   -46,   -46,   133,   -46,
     -46,   133,   -46,   -46,   -46,   133,   -46,   -46,   -46,    26,
     133,   133,   133,   102,   -46,   -46,   133,    86,    88,     7,
     -46,    63,   -46,    21,    83,    70,    46,    -9,    35,    26,
     -16,    39,    45,    -1,    89,   133,   133,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   133,    83,    83,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    37,    39,     0,     0,    85,    86,    88,    83,
       0,    43,    44,    46,    45,    26,     0,     0,    76,    77,
      78,     0,     0,     2,     4,     0,     0,    12,    13,     0,
       0,     0,     0,     0,    41,    42,    25,    49,    52,    55,
      63,    67,     0,    71,    79,    82,    80,    81,     0,     0,
       0,    31,    35,     0,     0,     0,    25,     0,     0,     0,
       0,     0,     1,     3,     6,     5,     7,     8,     9,    10,
       0,    20,    21,    22,    23,    24,    50,    19,     0,     0,
      53,     0,    59,    58,    60,    61,    56,    57,     0,    64,
      65,     0,    68,    69,    70,     0,    74,    75,    73,    72,
       0,     0,     0,    28,    32,    33,     0,    16,    17,     0,
      84,     0,    87,     0,    18,    48,    51,    54,    62,    66,
       0,     0,     0,     0,     0,     0,     0,    27,    47,    90,
      89,    38,    40,    30,    29,     0,    14,    15,    36,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,    74,   -19,    -5,   -46,   -46,   -46,   -46,   -45,
     -46,     2,    -2,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
      10,    76,    78,    -3,   -46,    58,   -46,    61,   -46,    50,
     -46,    48,   -46,   -36,   -46,   -46,   -46,   -46,   -46,   -46,
     -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,    78,    28,    29,
      58,    30,    50,    31,    54,    55,   139,    32,    48,    49,
      33,    34,    35,    36,    79,    37,    81,    38,    88,    39,
      91,    40,    95,    41,    98,    42,    43,    44,    45,    46,
      47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    51,    56,    53,    63,   103,    99,    76,   104,   105,
       4,    76,    57,    59,    60,     1,     2,     3,     4,   111,
       5,     6,     7,   130,     8,     9,    10,    71,    72,    73,
      74,    75,    15,    89,    90,    11,    12,    13,    14,    61,
      15,   127,    76,    16,    62,    17,    96,    97,    76,    18,
      19,    76,   110,    70,    20,    21,    77,   -31,   129,   119,
      71,    72,    73,    74,    75,   100,    76,   113,    82,    83,
      84,    85,    76,    64,    65,   114,   131,    66,   133,    92,
      93,    94,   132,    67,    76,    68,    86,    87,    69,    77,
      63,    11,    12,    13,    14,   101,    80,   120,   121,   122,
     102,    17,   106,    51,   124,    15,     1,     2,     3,     4,
      76,     5,     6,     7,   123,     8,     9,    10,   125,   112,
     126,   128,   136,   137,   135,   134,    11,    12,    13,    14,
     138,    15,   109,   107,    16,   108,    17,   115,   117,   118,
      18,    19,   116,     0,     0,    20,    21,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,     0,     0,     0,     0,    16,
       0,    17,     0,     0,     0,    18,    19,     0,     0,     0,
      20,    21
};

static const yytype_int16 yycheck[] =
{
       5,     4,     5,     5,    23,    50,    42,    27,    53,    54,
      11,    27,    18,    16,    17,     8,     9,    10,    11,    39,
      13,    14,    15,    39,    17,    18,    19,     3,     4,     5,
       6,     7,    33,    42,    43,    28,    29,    30,    31,    16,
      33,    34,    27,    36,     0,    38,    20,    21,    27,    42,
      43,    27,    37,    36,    47,    48,    32,    33,    37,    95,
       3,     4,     5,     6,     7,    38,    27,    70,    22,    23,
      24,    25,    27,     8,     8,    78,    37,     8,   123,    44,
      45,    46,    37,     8,    27,     8,    40,    41,     8,    32,
     109,    28,    29,    30,    31,    36,    26,   100,   101,   102,
      36,    38,    35,   106,   106,    33,     8,     9,    10,    11,
      27,    13,    14,    15,    12,    17,    18,    19,    32,    48,
      32,   111,   125,   126,    35,   123,    28,    29,    30,    31,
     135,    33,    58,    57,    36,    57,    38,    79,    88,    91,
      42,    43,    81,    -1,    -1,    47,    48,    14,    15,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    13,    14,    15,    17,    18,
      19,    28,    29,    30,    31,    33,    36,    38,    42,    43,
      47,    48,    50,    51,    52,    53,    54,    55,    57,    58,
      60,    62,    66,    69,    70,    71,    72,    74,    76,    78,
      80,    82,    84,    85,    86,    87,    88,    89,    67,    68,
      61,    72,    53,    61,    63,    64,    72,    18,    59,    72,
      72,    16,     0,    52,     8,     8,     8,     8,     8,     8,
      36,     3,     4,     5,     6,     7,    27,    32,    56,    73,
      26,    75,    22,    23,    24,    25,    40,    41,    77,    42,
      43,    79,    44,    45,    46,    81,    20,    21,    83,    82,
      38,    36,    36,    58,    58,    58,    35,    70,    71,    51,
      37,    39,    48,    72,    72,    74,    76,    78,    80,    82,
      72,    72,    72,    12,    61,    32,    32,    34,    69,    37,
      39,    37,    37,    58,    60,    35,    72,    72,    53,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    54,    54,    55,    56,
      56,    56,    56,    56,    56,    57,    59,    58,    60,    60,
      60,    61,    62,    62,    63,    64,    65,    67,    66,    68,
      66,    69,    69,    70,    70,    70,    70,    71,    72,    72,
      73,    74,    74,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      81,    82,    82,    82,    83,    83,    84,    84,    84,    85,
      85,    85,    86,    86,    86,    87,    87,    87,    87,    88,
      89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     5,     5,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     3,     5,
       5,     1,     3,     3,     5,     1,     1,     0,     5,     0,
       5,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     1,     4,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 14:
#line 115 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        insert_symbol((yyvsp[-3].s_val), (yyvsp[-2].s_val), NULL);
        if(strcmp("int32", (yyvsp[-2].s_val)) == 0 || strcmp("bool", (yyvsp[-2].s_val)) == 0){
            fprintf(fout, "istore %d\n", lookup_addr((yyvsp[-3].s_val)));
        } else if(strcmp("float32", (yyvsp[-2].s_val)) == 0){
            fprintf(fout, "fstore %d\n", lookup_addr((yyvsp[-3].s_val)));
        } else if(strcmp("string", (yyvsp[-2].s_val)) == 0){
            fprintf(fout, "astore %d\n", lookup_addr((yyvsp[-3].s_val)));
        }
    }
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 126 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        insert_symbol((yyvsp[-3].s_val), "array", (yyvsp[-2].s_val));    
        fprintf(fout, "newarray %s\n", (yyvsp[-2].s_val));
        fprintf(fout, "astore %d\n", lookup_addr((yyvsp[-3].s_val)));
    }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 132 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        insert_symbol((yyvsp[-1].s_val), (yyvsp[0].s_val), NULL);
        fprintf(fout, "ldc 0\n");// initialization
        if(strcmp("int32", (yyvsp[0].s_val)) == 0 || strcmp("bool", (yyvsp[0].s_val)) == 0){
            fprintf(fout, "istore %d\n", lookup_addr((yyvsp[-1].s_val)));
        } else if(strcmp("float32", (yyvsp[0].s_val)) == 0){
            fprintf(fout, "fstore %d\n", lookup_addr((yyvsp[-1].s_val)));
        } else if(strcmp("string", (yyvsp[0].s_val)) == 0){
            fprintf(fout, "astore %d\n", lookup_addr((yyvsp[-1].s_val)));
        }
    }
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        insert_symbol((yyvsp[-1].s_val), "array", (yyvsp[0].s_val));
        fprintf(fout, "newarray %s\n", (yyvsp[0].s_val));
        fprintf(fout, "astore %d\n", lookup_addr((yyvsp[-1].s_val)));
    }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 153 "compiler_hw3.y" /* yacc.c:1646  */
    {
        left = true;
        char * type1 = NULL;
        char * type3 = NULL;
        if(strcmp("bool", (yyvsp[-2].s_val)) != 0)
            parse_type((yyvsp[-2].s_val), &type1);
        else 
            type1 = strdup("bool");
        if(strcmp("bool", (yyvsp[0].s_val)) != 0)
            parse_type((yyvsp[0].s_val), &type3);
        else 
            type3 = strdup("bool");
        type_checking(type1, type3, (yyvsp[-1].s_val));
        if(strcmp("ASSIGN", (yyvsp[-1].s_val)) == 0){
            if(strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0)
                fprintf(fout, "istore %d\n", parse_addr((yyvsp[-2].s_val)));
            else if(strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0)
                fprintf(fout, "fstore %d\n", parse_addr((yyvsp[-2].s_val)));
        } else if(strcmp("ADD_ASSIGN", (yyvsp[-1].s_val)) == 0){
            if(strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0){
                fprintf(fout, "iadd\n");
                fprintf(fout, "istore %d\n", parse_addr((yyvsp[-2].s_val)));
            } else if(strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0){
                fprintf(fout, "fadd\n");
                fprintf(fout, "fstore %d\n", parse_addr((yyvsp[-2].s_val)));
            } 
        } else if(strcmp("SUB_ASSIGN", (yyvsp[-1].s_val)) == 0){
            if(strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0){
                fprintf(fout, "isub\n");
                fprintf(fout, "istore %d\n", parse_addr((yyvsp[-2].s_val)));
            } else if(strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0){
                fprintf(fout, "fsub\n");
                fprintf(fout, "fstore %d\n", parse_addr((yyvsp[-2].s_val)));
            }
        } else if(strcmp("MUL_ASSIGN", (yyvsp[-1].s_val)) == 0){
            if(strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0){
                fprintf(fout, "imul\n");
                fprintf(fout, "istore %d\n", parse_addr((yyvsp[-2].s_val)));
            } else if(strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0){
                fprintf(fout, "fmul\n");
                fprintf(fout, "fstore %d\n", parse_addr((yyvsp[-2].s_val)));
            } 
        } else if(strcmp("QUO_ASSIGN", (yyvsp[-1].s_val)) == 0){
            if(strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0){
                fprintf(fout, "idiv\n");
                fprintf(fout, "istore %d\n", parse_addr((yyvsp[-2].s_val)));
            } else if(strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0){
                fprintf(fout, "fdiv\n");
                fprintf(fout, "fstore %d\n", parse_addr((yyvsp[-2].s_val)));
            }
        } else if(strcmp("REM_ASSIGN", (yyvsp[-1].s_val)) == 0){
            if(strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0){
                fprintf(fout, "irem\n");
                fprintf(fout, "istore %d\n", parse_addr((yyvsp[-2].s_val)));
            } else if(strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0){
                fprintf(fout, "frem\n");
                fprintf(fout, "fstore %d\n", parse_addr((yyvsp[-2].s_val)));
            }
        } 
        printf("%s\n", (yyvsp[-1].s_val));
    }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 217 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "ASSIGN"; left = false;}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 218 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "ADD_ASSIGN"; left = false;}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 219 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "SUB_ASSIGN"; left = false;}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 220 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "MUL_ASSIGN"; left = false;}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 221 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "QUO_ASSIGN"; left = false;}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 222 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "REM_ASSIGN"; left = false;}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 230 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 230 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol();}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 240 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); condition_checking((yyval.s_val));}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 261 "compiler_hw3.y" /* yacc.c:1646  */
    {left = false;}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 262 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char * type;
        if(strcmp("bool", (yyvsp[-1].s_val)) != 0)
            parse_type((yyvsp[-1].s_val), &type);
        else
            type = strdup("bool");
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
        printf("PRINT %s\n", type_remove_lit((yyvsp[-1].s_val)));
    }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 291 "compiler_hw3.y" /* yacc.c:1646  */
    {left = false;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 292 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char * type;
        if(strcmp("bool", (yyvsp[-1].s_val)) != 0)
            parse_type((yyvsp[-1].s_val), &type);
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
        printf("PRINTLN %s\n", type_remove_lit((yyvsp[-1].s_val)));
    }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 329 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "int32";}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 330 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "float32";}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 331 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "string";}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 332 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "bool";}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 337 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = (yyvsp[0].s_val);
        char * type = NULL;
        if(strcmp("bool", (yyvsp[-2].s_val)) != 0)
            parse_type((yyvsp[-2].s_val), &type);
        else 
            type = strdup("bool");
        if(strcmp("float32", type) == 0 || strcmp("float32", type) == 0 ||
           strcmp("string", type) == 0 || strcmp("STRING_LIT", type) == 0){
            printf("you put a strange type into the index of an array!!!\n");
        }

    }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 354 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("%s\n", (yyvsp[-1].s_val)); 
        char * type1 = NULL;
        char * type3 = NULL;
        if(strcmp("bool", (yyvsp[-2].s_val)) != 0)
            parse_type((yyvsp[-2].s_val), &type1);
        else 
            type1 = strdup("bool");
        if(strcmp("bool", (yyvsp[0].s_val)) != 0)
            parse_type((yyvsp[0].s_val), &type3);
        else 
            type3 = strdup("bool");
        type_checking(type1, type3, (yyvsp[-1].s_val));
        fprintf(fout, "ior\n");
        (yyval.s_val) = "bool";
    }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 374 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "LOR";}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 379 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        char * type1 = NULL;
        char * type3 = NULL;
        if(strcmp("bool", (yyvsp[-2].s_val)) != 0)
            parse_type((yyvsp[-2].s_val), &type1);
        else 
            type1 = strdup("bool");
        if(strcmp("bool", (yyvsp[0].s_val)) != 0)
            parse_type((yyvsp[0].s_val), &type3);
        else 
            type3 = strdup("bool");
        type_checking(type1, type3, (yyvsp[-1].s_val));
        printf("%s\n", (yyvsp[-1].s_val)); 
        fprintf(fout, "iand\n");
        (yyval.s_val) = "bool";
    }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 399 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "LAND";}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 404 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        char * type1 = NULL;
        char * type3 = NULL;
        parse_type((yyvsp[-2].s_val), &type1);
        parse_type((yyvsp[0].s_val), &type3);
        printf("%s\n", (yyvsp[-1].s_val)); 
        if(strcmp("GTR", (yyvsp[-1].s_val)) == 0 || strcmp("LEQ", (yyvsp[-1].s_val)) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "isub\n");
                fprintf(fout, "ifgt branch_%d\n", branch_cnt);
                fprintf(fout, strcmp("LEQ", (yyvsp[-1].s_val)) == 0 ? "iconst_1\n" : "iconst_0\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, strcmp("LEQ", (yyvsp[-1].s_val)) == 0 ? "iconst_0\n" : "iconst_1\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            }
            else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
               (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fsub\n");
                fprintf(fout, "ifgt branch_%d\n", branch_cnt);
                fprintf(fout, strcmp("LEQ", (yyvsp[-1].s_val)) == 0 ? "iconst_1\n" : "iconst_0\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, strcmp("LEQ", (yyvsp[-1].s_val)) == 0 ? "iconst_0\n" : "iconst_1\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            }
        } else if(strcmp("LSS", (yyvsp[-1].s_val)) == 0 || strcmp("GEQ", (yyvsp[-1].s_val)) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "isub\n");
                fprintf(fout, "iflt branch_%d\n", branch_cnt);
                fprintf(fout, strcmp("LSS", (yyvsp[-1].s_val)) == 0 ? "iconst_0\n" : "iconst_1\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, strcmp("LSS", (yyvsp[-1].s_val)) == 0 ? "iconst_1\n" : "iconst_0\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
               (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fsub\n");
                fprintf(fout, "iflt branch_%d\n", branch_cnt);
                fprintf(fout, strcmp("LSS", (yyvsp[-1].s_val)) == 0 ? "iconst_0\n" : "iconst_1\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, strcmp("LSS", (yyvsp[-1].s_val)) == 0 ? "iconst_1\n" : "iconst_0\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
            }
        } else if(strcmp("EQL", (yyvsp[-1].s_val)) == 0){
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
                fprintf(fout, "fsub\n");
                fprintf(fout, "ifeq branch_%d\n", branch_cnt);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto branch_%d\n", branch_cnt + 1);
                fprintf(fout, "branch_%d:\n", branch_cnt);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "branch_%d:\n", branch_cnt + 1);
                branch_cnt += 2;
           } 
        }
        (yyval.s_val) = "bool";
    }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 484 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "LSS";}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 485 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "GTR";}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 486 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "LEQ";}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 487 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "GEQ";}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 488 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "EQL";}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 489 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "NEQ";}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 494 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char * type1 = NULL;
        char * type3 = NULL;
        printf("good %s %s\n", (yyvsp[-2].s_val), (yyvsp[0].s_val));
        parse_type((yyvsp[-2].s_val), &type1);
        parse_type((yyvsp[0].s_val), &type3);
        type_checking(type1, type3, (yyvsp[-1].s_val));
        printf("%s\n", (yyvsp[-1].s_val));
        printf("--------%s %s-----------------------\n", type1, type3);
        if(strcmp("ADD", (yyvsp[-1].s_val)) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "iadd\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fadd\n");
            }
        } else if(strcmp("SUB", (yyvsp[-1].s_val)) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "isub\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fsub\n");
            }
        }
        
    }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 526 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "ADD";}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 527 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "SUB";}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 532 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char * type1 = NULL;
        char * type3 = NULL;
        parse_type((yyvsp[-2].s_val), &type1);
        parse_type((yyvsp[0].s_val), &type3);
        type_checking(type1, type3, (yyvsp[-1].s_val));
        printf("%s\n", (yyvsp[-1].s_val));
        if(strcmp("MUL", (yyvsp[-1].s_val)) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT",type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "imul\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fmul\n");
            }
        } else if(strcmp("QUO", (yyvsp[-1].s_val)) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "idiv\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "fdiv\n");
            }
        } else if(strcmp("REM", (yyvsp[-1].s_val)) == 0){
            if((strcmp("int32", type1) == 0 || strcmp("INT_LIT", type1) == 0) &&
               (strcmp("int32", type3) == 0 || strcmp("INT_LIT", type3) == 0)){
                fprintf(fout, "irem\n");
            } else if((strcmp("float32", type1) == 0 || strcmp("FLOAT_LIT", type1) == 0) &&
                      (strcmp("float32", type3) == 0 || strcmp("FLOAT_LIT", type3) == 0)){
                fprintf(fout, "frem\n");
            } // frem is legal?
        }
    }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 569 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "MUL";}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 570 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "QUO";}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 571 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "REM";}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 577 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.s_val) = (yyvsp[0].s_val); 
        char * type = NULL;
        parse_type((yyvsp[0].s_val), &type);
        printf("%s\n", (yyvsp[-1].s_val));
        if(strcmp("NEG", (yyvsp[-1].s_val)) == 0){
            if(strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0){
                fprintf(fout, "ineg\n");
            } else if(strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0){
                fprintf(fout, "fneg\n");
            }
        } else if(strcmp("NOT", (yyvsp[-1].s_val)) == 0){
            if(strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0 ||
               strcmp("bool", type) == 0 || strcmp("BOOL_LIT", type) == 0){
                fprintf(fout, "ixor\n");
            } 
        }
    }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 596 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.s_val) = (yyvsp[-1].s_val); 
        char * type = NULL;
        parse_type((yyvsp[-1].s_val), &type);
        printf("%s\n", (yyvsp[0].s_val));
        printf("this is : %s\n", type);
        if(strcmp("INC", (yyvsp[0].s_val)) == 0 &&
          (strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0)){
            fprintf(fout, "ldc 1\n");
            fprintf(fout, "iadd\n");
            fprintf(fout, "istore %d\n", parse_addr((yyvsp[-1].s_val)));
        } else if(strcmp("DEC", (yyvsp[0].s_val)) == 0 &&
          (strcmp("int32", type) == 0 || strcmp("INT_LIT", type) == 0)){
            fprintf(fout, "ldc 1\n");
            fprintf(fout, "isub\n");
            fprintf(fout, "istore %d\n", parse_addr((yyvsp[-1].s_val)));
        } else if(strcmp("INC", (yyvsp[0].s_val)) == 0 &&
          (strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0)){
            fprintf(fout, "ldc 1.000000\n");
            fprintf(fout, "fadd\n");
            fprintf(fout, "fstore %d\n", parse_addr((yyvsp[-1].s_val)));
        } else if(strcmp("DEC", (yyvsp[0].s_val)) == 0 &&
          (strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0)){
            fprintf(fout, "ldc 1.000000\n");
            fprintf(fout, "fsub\n");
            fprintf(fout, "fstore %d\n", parse_addr((yyvsp[-1].s_val)));
        } else
            printf("IncDec error %s %s\n", (yyvsp[-1].s_val), (yyvsp[0].s_val));
    }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 628 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "INC";}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 629 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "DEC";}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 633 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "POS";}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 634 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "NEG";}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 635 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "NOT"; fprintf(fout, "iconst_1\n"); /*for not operator*/}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 647 "compiler_hw3.y" /* yacc.c:1646  */
    {
        bool is_array; 
        char * type = NULL;
        is_array = lookup_symbol((yyvsp[0].s_val), &type);
        char typeAddr[20];
        sprintf(typeAddr, "%s %d", type, lookup_addr((yyvsp[0].s_val)));
        if(typeAddr != NULL)
            (yyval.s_val) = typeAddr;
        else
            (yyval.s_val) = strdup("XXX");
        if(left == false){
            if(!is_array){
                if(strcmp("string", type) == 0)
                    fprintf(fout, "aload %d\n", parse_addr(typeAddr));
                if(strcmp("int32", type) == 0 || strcmp("bool", type) == 0)
                    fprintf(fout, "iload %d\n", parse_addr(typeAddr));
                if(strcmp("float32", type) == 0)
                    fprintf(fout, "fload %d\n", parse_addr(typeAddr));
            } else {
                fprintf(fout, "aload %d\n", lookup_addr(typeAddr));
            }
        }
    }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 670 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-1].s_val);}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 675 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        fprintf(fout, "ldc %d\n", (yyvsp[0].i_val));
        (yyval.s_val) = "INT_LIT -1";
    }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 681 "compiler_hw3.y" /* yacc.c:1646  */
    {   
        fprintf(fout, "ldc %f\n", (yyvsp[0].f_val));
        (yyval.s_val) = "FLOAT_LIT -1";
    }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 686 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("STRING_LIT %s\n", (yyvsp[-1].s_val)); 
        fprintf(fout, "ldc %s\n", (yyvsp[-1].s_val));
        (yyval.s_val) = "STRING_LIT -1";
    }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 692 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[0].s_val), "true") == 0){
            printf("TRUE\n");
            fprintf(fout, "iconst_1\n"); // iconst_1
        } else if(strcmp((yyvsp[0].s_val), "false") == 0){
            printf("FALSE\n");
            fprintf(fout, "iconst_0\n"); // iconst_0
        } else {
            printf("BOOL_LIT BUG!!\n");
        }
        (yyval.s_val) = "BOOL_LIT -1";
    }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 708 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.s_val) = (yyvsp[-3].s_val);
        char * type = NULL;
        if(strcmp("bool", (yyvsp[-3].s_val)) != 0)
            parse_type((yyvsp[-3].s_val), &type);
        else 
            type = strdup("bool");
        if(strcmp("float32", type) == 0 || strcmp("FLOAT_LIT", type) == 0 ||
           strcmp("string", type) == 0 || strcmp("STRING_LIT", type) == 0){
            printf("you put a strange type into the index of an array!!!\n");
        }
    }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 724 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.s_val) = (yyvsp[-3].s_val);
        char * type;
        parse_type((yyvsp[-1].s_val), &type);
        printf("%c to %c\n", conversion_code(type), conversion_code((yyvsp[-3].s_val)));
    }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2187 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 732 "compiler_hw3.y" /* yacc.c:1906  */


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
    left = true;
    initTable(&tb, 256, 16);
    yylineno = 0;
    branch_cnt = 0;
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

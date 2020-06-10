/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 50 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *s_val;
    bool b_val;    

#line 123 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

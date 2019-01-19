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
    ATTR = 258,
    LE = 259,
    GE = 260,
    NE = 261,
    LT = 262,
    GT = 263,
    EQ = 264,
    AND = 265,
    ARRAY = 266,
    BEGINN = 267,
    BOOLEAN = 268,
    DO = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    END = 273,
    INTEGER = 274,
    NOT = 275,
    OF = 276,
    OR = 277,
    PROCEDURE = 278,
    PROGRAM = 279,
    READ = 280,
    REAL = 281,
    VAR = 282,
    FOR = 283,
    WRITE = 284,
    TRUE = 285,
    FALSE = 286,
    NUMBER = 287,
    ID = 288,
    TYPE = 289,
    TO = 290,
    ADD = 291,
    SUB = 292,
    MULT = 293,
    DIVV = 294,
    MOD = 295,
    BLOCK = 296,
    EXPR = 297,
    STMTS = 298,
    UMINUS = 299,
    NO_ELSE = 300
  };
#endif
/* Tokens.  */
#define ATTR 258
#define LE 259
#define GE 260
#define NE 261
#define LT 262
#define GT 263
#define EQ 264
#define AND 265
#define ARRAY 266
#define BEGINN 267
#define BOOLEAN 268
#define DO 269
#define IF 270
#define THEN 271
#define ELSE 272
#define END 273
#define INTEGER 274
#define NOT 275
#define OF 276
#define OR 277
#define PROCEDURE 278
#define PROGRAM 279
#define READ 280
#define REAL 281
#define VAR 282
#define FOR 283
#define WRITE 284
#define TRUE 285
#define FALSE 286
#define NUMBER 287
#define ID 288
#define TYPE 289
#define TO 290
#define ADD 291
#define SUB 292
#define MULT 293
#define DIVV 294
#define MOD 295
#define BLOCK 296
#define EXPR 297
#define STMTS 298
#define UMINUS 299
#define NO_ELSE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

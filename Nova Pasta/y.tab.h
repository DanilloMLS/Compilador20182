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
    NUMBER = 258,
    ATTR = 259,
    LE = 260,
    GE = 261,
    NE = 262,
    LT = 263,
    GT = 264,
    EQ = 265,
    AND = 266,
    ARRAY = 267,
    BEGINN = 268,
    DIV = 269,
    DO = 270,
    ID = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    END = 275,
    EXPR = 276,
    MOD = 277,
    NOT = 278,
    OF = 279,
    OR = 280,
    PROCEDURE = 281,
    PROGRAM = 282,
    READ = 283,
    VAR = 284,
    TIPOBOOL = 285,
    TIPOINT = 286,
    TIPOREAL = 287,
    TIPO = 288,
    WHILE = 289,
    WRITE = 290
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define ATTR 259
#define LE 260
#define GE 261
#define NE 262
#define LT 263
#define GT 264
#define EQ 265
#define AND 266
#define ARRAY 267
#define BEGINN 268
#define DIV 269
#define DO 270
#define ID 271
#define IF 272
#define THEN 273
#define ELSE 274
#define END 275
#define EXPR 276
#define MOD 277
#define NOT 278
#define OF 279
#define OR 280
#define PROCEDURE 281
#define PROGRAM 282
#define READ 283
#define VAR 284
#define TIPOBOOL 285
#define TIPOINT 286
#define TIPOREAL 287
#define TIPO 288
#define WHILE 289
#define WRITE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

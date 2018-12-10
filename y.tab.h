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
    INTNUMBER = 258,
    REALNUMBER = 259,
    ID = 260,
    AND = 261,
    OR = 262,
    NOT = 263,
    BEGINN = 264,
    END = 265,
    VAR = 266,
    PROCEDURE = 267,
    PROGRAM = 268,
    ARRAY = 269,
    OF = 270,
    IF = 271,
    ELSE = 272,
    THEN = 273,
    WHILE = 274,
    DO = 275,
    REAL = 276,
    INTEGER = 277,
    WRITE = 278,
    READ = 279,
    DIV = 280,
    MOD = 281,
    ADD = 282,
    SUB = 283,
    MULT = 284,
    ATTR = 285,
    LE = 286,
    LT = 287,
    EQ = 288,
    NE = 289,
    GE = 290,
    GT = 291,
    COMMA = 292,
    DOT = 293,
    COLON = 294,
    SEMICOMMA = 295,
    LBRACKETS = 296,
    RBRACKETS = 297,
    LPARENTESIS = 298,
    RPARENTESIS = 299,
    LCOMMENT = 300,
    RCOMMENT = 301
  };
#endif
/* Tokens.  */
#define INTNUMBER 258
#define REALNUMBER 259
#define ID 260
#define AND 261
#define OR 262
#define NOT 263
#define BEGINN 264
#define END 265
#define VAR 266
#define PROCEDURE 267
#define PROGRAM 268
#define ARRAY 269
#define OF 270
#define IF 271
#define ELSE 272
#define THEN 273
#define WHILE 274
#define DO 275
#define REAL 276
#define INTEGER 277
#define WRITE 278
#define READ 279
#define DIV 280
#define MOD 281
#define ADD 282
#define SUB 283
#define MULT 284
#define ATTR 285
#define LE 286
#define LT 287
#define EQ 288
#define NE 289
#define GE 290
#define GT 291
#define COMMA 292
#define DOT 293
#define COLON 294
#define SEMICOMMA 295
#define LBRACKETS 296
#define RBRACKETS 297
#define LPARENTESIS 298
#define RPARENTESIS 299
#define LCOMMENT 300
#define RCOMMENT 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

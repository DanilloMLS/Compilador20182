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
#line 1 "sintatico.y" /* yacc.c:339  */

#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
#include "tabela.h"
#include "tabela.c"
#include "tabNumero.h"
#include "arvore.h"
#include "arvore.c"

pilha_contexto *pilha;
char* cod_ids[100];
int count_ids;
no_arvore *no;

void yyerror(const char *str){
	fprintf(stderr,"error: %s\n",str);
}

main(){
	pilha = NULL;
	count_ids = 0;
	yyparse();
	return 0;
}

#line 94 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
    IFELSE = 299,
    UMINUS = 300,
    NO_ELSE = 301
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
#define IFELSE 299
#define UMINUS 300
#define NO_ELSE 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,     2,     2,    52,     2,    47,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    58,    62,    63,    64,    68,    72,    73,
      74,    78,    95,    99,   104,   112,   116,   120,   121,   125,
     126,   127,   132,   136,   136,   155,   161,   168,   169,   170,
     171,   176,   189,   202,   209,   220,   230,   240,   250,   256,
     266,   268,   277,   282,   290,   298,   311,   317,   323,   329,
     335,   341,   347,   353,   359
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTR", "LE", "GE", "NE", "LT", "GT",
  "EQ", "AND", "ARRAY", "BEGINN", "BOOLEAN", "DO", "IF", "THEN", "ELSE",
  "END", "INTEGER", "NOT", "OF", "OR", "PROCEDURE", "PROGRAM", "READ",
  "REAL", "VAR", "FOR", "WRITE", "TRUE", "FALSE", "NUMBER", "ID", "TYPE",
  "TO", "ADD", "SUB", "MULT", "DIVV", "MOD", "BLOCK", "EXPR", "STMTS",
  "IFELSE", "UMINUS", "NO_ELSE", "'.'", "';'", "':'", "'['", "']'", "','",
  "'('", "')'", "$accept", "programa", "cabecalho", "declaracoes",
  "declidentificadores", "listasident", "listavar", "listaarray",
  "listaids", "declprocedimentos", "cabecalhoproc", "argumentos",
  "listaargs", "corpoproc", "bloco", "$@1", "comandos", "comando",
  "atribuicao", "expressao", "condicao", "repeticao", "atribuicaofor",
  "expressaobool", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    46,    59,    58,
      91,    93,    44,    40,    41
};
# endif

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -12,   -25,    10,   -43,   -32,   -43,   -27,   -43,   -43,   -43,
      -6,   -43,   -11,   -43,   -43,   -43,   -43,    43,   -29,    22,
     -43,    14,    11,   -43,    16,    34,    29,    80,   -43,   -43,
     -43,   -43,    22,    36,   -43,    37,    49,     7,   -43,    33,
      67,    98,    68,   -28,   -28,   -43,     8,   -41,   -43,   -43,
     -43,    -8,    69,   -28,   -43,   -43,   -28,   -28,    41,    52,
      53,   -28,    76,    51,    75,    82,    22,   -43,    59,   -43,
     -43,    -9,   -43,    56,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   101,    70,    -9,
     105,    72,   -43,   -43,    89,   -43,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,    35,    35,   -43,   -43,   -43,    73,
     -43,    77,   -43,    78,   -43,   -43,    81,     6,    79,    92,
     -43,   -43,   -43,    83,    84,   108,   -43,    96,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    23,     0,     1,     0,     6,     3,     2,
       0,    26,     0,    10,     4,     5,    23,     0,    18,     7,
      15,     0,     0,    24,     0,     0,     0,     0,    25,    27,
      28,    29,    21,     0,    14,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,    20,     0,     0,    16,     8,
       9,     0,     0,     0,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,    11,
      13,    48,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,    32,    19,     0,    40,    50,    52,    54,    49,
      51,    53,    46,    47,    35,    36,    37,    38,    39,     0,
      31,     0,    30,     0,    23,    23,     0,     0,     0,     0,
      23,    42,    44,     0,     0,     0,    43,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -43,   -43,   -43,   -43,   -14,   -43,   112,   -43,
     -43,   -43,   -43,   -43,   -16,   -43,   -43,   -43,   -43,   -42,
     -43,   -43,   -43,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    19,    35,    36,    46,    15,
      16,    33,    47,    20,     6,     7,    17,    28,    29,    58,
      30,    31,    42,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      21,    63,    64,    68,    54,    55,    11,    66,     4,    56,
       5,    71,     1,    67,    72,    73,     8,    12,    45,    89,
       9,    13,    18,   120,    32,    57,    69,    82,    83,    84,
      85,    86,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    74,    75,    76,    77,    78,
      79,    80,    93,    53,   121,    34,    51,    65,    22,    52,
      52,    23,    38,    81,    39,    54,    55,    41,    24,    40,
      56,    25,    26,    84,    85,    86,    27,    82,    83,    84,
      85,    86,    43,    44,    48,    49,    57,    82,    83,    84,
      85,    86,    82,    83,    84,    85,    86,    50,   117,   118,
      60,    61,    70,    62,   124,    91,    87,    88,    90,    94,
      95,    82,    83,    84,    85,    86,    69,   109,   110,   111,
     112,   113,   114,    92,   123,   116,   115,   122,   119,   127,
     128,    37,   126,     0,   125
};

static const yytype_int8 yycheck[] =
{
      16,    43,    44,    11,    32,    33,    12,    48,    33,    37,
       0,    53,    24,    54,    56,    57,    48,    23,    32,    61,
      47,    27,    33,    17,    53,    53,    34,    36,    37,    38,
      39,    40,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     4,     5,     6,     7,     8,
       9,    10,    66,    20,    48,    33,    49,    49,    15,    52,
      52,    18,    48,    22,    53,    32,    33,    33,    25,    53,
      37,    28,    29,    38,    39,    40,    33,    36,    37,    38,
      39,    40,    53,     3,    48,    48,    53,    36,    37,    38,
      39,    40,    36,    37,    38,    39,    40,    48,   114,   115,
      33,     3,    33,    35,   120,    54,    54,    54,    32,    50,
      54,    36,    37,    38,    39,    40,    34,    16,    48,    14,
      48,    32,    49,    48,    32,    47,    49,    48,    47,    21,
      34,    19,    48,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    56,    57,    33,     0,    69,    70,    48,    47,
      58,    12,    23,    27,    59,    64,    65,    71,    33,    60,
      68,    69,    15,    18,    25,    28,    29,    33,    72,    73,
      75,    76,    53,    66,    33,    61,    62,    63,    48,    53,
      53,    33,    77,    53,     3,    61,    63,    67,    48,    48,
      48,    49,    52,    20,    32,    33,    37,    53,    74,    78,
      33,     3,    35,    74,    74,    49,    48,    54,    11,    34,
      33,    74,    74,    74,     4,     5,     6,     7,     8,     9,
      10,    22,    36,    37,    38,    39,    40,    54,    54,    74,
      32,    54,    48,    61,    50,    54,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    16,
      48,    14,    48,    32,    49,    49,    47,    69,    69,    47,
      17,    48,    48,    32,    69,    51,    48,    21,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    58,    58,    58,    59,    60,    60,
      60,    61,    62,    63,    63,    64,    65,    66,    66,    67,
      67,    67,    68,    70,    69,    71,    71,    72,    72,    72,
      72,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    76,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     0,     2,     3,     3,
       0,     3,    11,     3,     1,     2,     4,     3,     0,     3,
       1,     0,     2,     0,     5,     2,     0,     1,     1,     1,
       5,     5,     4,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     8,    10,     8,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3
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
        case 2:
#line 54 "sintatico.y" /* yacc.c:1646  */
    {imprimir_arvore((no_arvore*)(yyvsp[-1]));}
#line 1403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 79 "sintatico.y" /* yacc.c:1646  */
    {
		for(int i = 0; i < count_ids; i++){
			simbolo* s = localizar_simbolo_no_contexto_atual(topo_pilha(pilha), cod_ids[i]);
			if(s == NULL && topo_pilha(pilha) != NULL){
				s = criar_simbolo(cod_ids[i], (yyvsp[0]));
				printf("simbolo %s",s->lexema);
				inserir_simbolo(topo_pilha(pilha), s);
			}else{
				yyerror("O identificador já existe!");
			}
		}
		count_ids = 0;
	}
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 100 "sintatico.y" /* yacc.c:1646  */
    {
		cod_ids[count_ids] = (char*)(yyvsp[0]);
		count_ids++;
	}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 105 "sintatico.y" /* yacc.c:1646  */
    {
		cod_ids[count_ids] = (char*)(yyvsp[0]);
		count_ids++;
	}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 136 "sintatico.y" /* yacc.c:1646  */
    {	//coloca o contexto (o bloco) em uma pilha
		tabela * contexto = criar_contexto(topo_pilha(pilha));
		pilha = empilhar_contexto(pilha, contexto);
		//imprimir_contexto(contexto);
	}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "sintatico.y" /* yacc.c:1646  */
    {
		if(topo_pilha(pilha) != NULL) { //imprime o contexto e desempilha
			//imprimir_contexto(topo_pilha(pilha));
		    	desempilhar_contexto(&pilha);
		}
		no_arvore* n = criar_no_bloco((void*)(yyvsp[-1]));//cria um nó do tipo bloco na árvore
		(yyval) = (long int)n;
	}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_stmts((void*)(yyvsp[-1]), (no_arvore*)(yyvsp[0]));
		(yyval) = (long int)n;
	}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore* n = criar_no_stmts(NULL, NULL);
        	(yyval) = (long int)n;
	}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 172 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_write((void*)(yyvsp[-2]));
		(yyval) = (long int)n;
	}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 177 "sintatico.y" /* yacc.c:1646  */
    {
		simbolo* s = localizar_simbolo_no_contexto_atual(topo_pilha(pilha), (char*) (yyvsp[-2]));
		if(s == NULL){
			yyerror("Identificador não declarado");
		}else{
			no_arvore *n = criar_no_read(s);
			(yyval) = (long int)n;
		}
	}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 190 "sintatico.y" /* yacc.c:1646  */
    {
		simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) (yyvsp[-3]));
		if(s == NULL)
			yyerror("Identificador não declarado");
		else  {
			no_arvore *n = criar_no_atribuicao(s, (void *) (yyvsp[-1]));
			(yyval) = (long int) n;
		}
	}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 203 "sintatico.y" /* yacc.c:1646  */
    {
		numero *num = (numero*)(yyvsp[0]);
		no_arvore *n = criar_no_expressao(NUMBER, (void *) (yyvsp[0]), NULL);
		n->dado.expr->tipo = num->tipo;
		(yyval) = (long int) n;
	}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 210 "sintatico.y" /* yacc.c:1646  */
    {
		simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) (yyvsp[0]));
		if(s == NULL)
			yyerror("Identificador não declarado");
		else  {
			no_arvore *n = criar_no_expressao(ID, (simbolo*)(yyvsp[0]), NULL);
			n->dado.expr->tipo = s->tipo;
			(yyval) = (long int) n;
		}
	}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 221 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(ADD, (void *) (yyvsp[-2]), (void *) (yyvsp[0])); 
		if(((no_arvore*)(yyvsp[-2]))->dado.expr->tipo == REAL || ((no_arvore*)(yyvsp[0]))->dado.expr->tipo == REAL){
			n->dado.expr->tipo = REAL;
		}else{
			n->dado.expr->tipo = INTEGER;
		}
		(yyval) = (long int) n;
	}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 231 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(SUB, (void *) (yyvsp[-2]), (void *) (yyvsp[0])); 
		if(((no_arvore*)(yyvsp[-2]))->dado.expr->tipo == REAL || ((no_arvore*)(yyvsp[0]))->dado.expr->tipo == REAL){
			n->dado.expr->tipo = REAL;
		}else{
			n->dado.expr->tipo = INTEGER;
		}
		(yyval) = (long int) n;
	}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 241 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(SUB, (void *) (yyvsp[-2]), (void *) (yyvsp[0])); 
		if(((no_arvore*)(yyvsp[-2]))->dado.expr->tipo == REAL || ((no_arvore*)(yyvsp[0]))->dado.expr->tipo == REAL){
			n->dado.expr->tipo = REAL;
		}else{
			n->dado.expr->tipo = INTEGER;
		}
		(yyval) = (long int) n;
	}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 251 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(DIVV, (void *) (yyvsp[-2]), (void *) (yyvsp[0])); 
		n->dado.expr->tipo = REAL;
		(yyval) = (long int) n;
	}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 257 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(SUB, (void *) (yyvsp[-2]), (void *) (yyvsp[0])); 
		if(((no_arvore*)(yyvsp[-2]))->dado.expr->tipo == REAL || ((no_arvore*)(yyvsp[0]))->dado.expr->tipo == REAL){
			n->dado.expr->tipo = REAL;
		}else{
			n->dado.expr->tipo = INTEGER;
		}
		(yyval) = (long int) n;
	}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 267 "sintatico.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 269 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(UMINUS, NULL, (void *) (yyvsp[0])); 
		n->dado.expr->tipo = ((no_arvore*)(yyvsp[0]))->dado.expr->tipo;
		(yyval) = (long int) n;
	}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 278 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_ifelse((void*)(yyvsp[-5]), (void*)(yyvsp[-1]), NULL);
		(yyval) = (long int) n;
	}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_ifelse((void*)(yyvsp[-7]), (void*)(yyvsp[-3]), (void*)(yyvsp[-1]));
		(yyval) = (long int) n;
	}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 291 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_for((void*)(yyvsp[-6]),(numero*)(yyvsp[-4]),(void*)(yyvsp[-1]));
		(yyval) = (long int) n;
	}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 299 "sintatico.y" /* yacc.c:1646  */
    {
		simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) (yyvsp[-2]));
		if(s == NULL)
			yyerror("Identificador não declarado");
		else  {
			no_arvore *n = criar_no_atribuicao(s, (void *) (yyvsp[0]));
			(yyval) = (long int) n;
		}
	}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 312 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(AND, (void*)(yyvsp[-2]), (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 318 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(OR, (void*)(yyvsp[-2]), (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 324 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(NOT, NULL, (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 330 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(LT, (void*)(yyvsp[-2]), (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 336 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(LE, (void*)(yyvsp[-2]), (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 342 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(GT, (void*)(yyvsp[-2]), (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 348 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(GE, (void*)(yyvsp[-2]), (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 354 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(EQ, (void*)(yyvsp[-2]), (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 360 "sintatico.y" /* yacc.c:1646  */
    {
		no_arvore *n = criar_no_expressao(NE, (void*)(yyvsp[-2]), (void *)(yyvsp[0])); 
		n->dado.expr->tipo = BOOLEAN;
		(yyval) = (long int) n;
	}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1760 "y.tab.c" /* yacc.c:1646  */
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

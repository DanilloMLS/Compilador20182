%{
#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
#include "tabela.h"
#include "arvore.h"
int yylex(void);
void yyerror(char *);
pilha_contexto *pilha;
%}

%token INTNUMBER REALNUMBER ID
%token AND OR NOT
%token BEGINN END VAR PROCEDURE PROGRAM
%token ARRAY OF
%token IF ELSE THEN
%token WHILE DO
%token REAL INTEGER
%token WRITE READ
%token DIV MOD ADD SUB MULT

%token ATTR
%token LE LT EQ NE GE GT
%token COMMA DOT COLON SEMICOMMA
%token LBRACKETS RBRACKETS
%token LPARENTESIS RPARENTESIS
%token LCOMMENT RCOMMENT

%left OR AND NOT
%left LE GE NE LT GT EQ
%left ADD SUB MOD DIV MULT

%nonassoc THEN
%nonassoc ELSE

%%
/*definicao de programa*/

program:
	cabecalho declaracoes bloco DOT 
	;

cabecalho:
	PROGRAM ID SEMICOMMA
	;

declaracoes:
	declaracao_variaveis declaracao_subprogramas
	;

declaracao_subprogramas:
	declaracao_subprogramas declaracao_procedimento
	|
	;


/*definicao de variaveis*/

declaracao_variaveis:
	VAR bloco_tipos
	|
	;

bloco_tipos:
	bloco_variaveis
	| bloco_arrays
	| bloco_variaveis bloco_arrays
	;

bloco_variaveis:
	lista_variaveis
	| bloco_variaveis lista_variaveis
	;

lista_variaveis:
	lista_identificadores COLON tipo SEMICOMMA
	;

bloco_arrays:
	lista_arrays
	| bloco_arrays lista_arrays
	;

lista_arrays:
	lista_identificadores COLON ARRAY LBRACKETS INTNUMBER DOT DOT INTNUMBER RBRACKETS OF tipo
	;

lista_identificadores:
	ID
	| lista_identificadores COMMA ID
	;

tipo:
	INTEGER
	| REAL
	;


/*definicao de procedimentos*/

declaracao_procedimento:
	cabecalho_procedimento declaracao_variaveis bloco SEMICOMMA
	;

cabecalho_procedimento:
	PROCEDURE ID argumentos SEMICOMMA
	;

argumentos:
	LPARENTESIS lista_identificadores COLON tipo RPARENTESIS
	|
	;


/*definicao de comandos*/

bloco:
	BEGINN comando_bloco END
	;

comando_bloco:
	lista_comandos
	|
	;

lista_comandos:
	comandos SEMICOMMA
	| lista_comandos comandos
	;

comandos:
	ID ATTR expressao
	| ID LPARENTESIS expressao RPARENTESIS
	| WHILE LPARENTESIS expressao RPARENTESIS DO comandos
	| READ LPARENTESIS ID RPARENTESIS
	| WRITE LPARENTESIS expressao RPARENTESIS
	| IF expressao THEN comandos ELSE comandos /*%prec PRECELSE*/
	| IF expressao THEN comandos
	;


/*definicao de expressao*/

expressao:
	expressao_aritmetica
	| expressao EQ expressao_aritmetica
	| expressao LT expressao_aritmetica
	| expressao GT expressao_aritmetica
	| expressao NE expressao_aritmetica
	| expressao GE expressao_aritmetica
	| expressao LE expressao_aritmetica
	;

expressao_aritmetica:
	termo
	| expressao_aritmetica ADD termo
	| expressao_aritmetica SUB termo
	| expressao_aritmetica OR termo
	;

termo:
	fator
	| termo MULT fator
	| termo DIV fator
	| termo MOD fator
	| termo AND fator
	;

fator:
	ID
	| INTNUMBER
	| REALNUMBER
	| LPARENTESIS expressao RPARENTESIS
	| NOT fator
	| SUB fator
	;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(void) {
	pilha = NULL;
	yyparse();
	return 0;
}

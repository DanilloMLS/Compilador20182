%{
#include <stdio.h>
#include "tabela.h"
#include "arvore.h"
int yylex(void);
void yyerror(char *);
pilha_contexto *pilha;
%}

%token INTNUMBER REALNUMBER ID
%token AND OR NOT
%token BEGIN END VAR PROCEDURE PROGRAM
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
	identificador
	| lista_identificadores COMMA identificador
	;


/*definicao de procedimentos*/

declaracao_procedimentos:
	cabecalho_procedimento declaracoes_variaveis bloco SEMICOMMA
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
	BEGIN comando_bloco END
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
	variavel ATTR expressao
	| procedimento_nome
	| procedimento_nome LPARENTESIS expressao RPARENTESIS
	| WHILE LPARENTESIS expressao RPARENTESIS DO comandos
	| READ LPARENTESIS parametro RPARENTESIS
	| WRITE LPARENTESIS parametro RPARENTESIS
	| IF expressao THEN comandos ELSE
	| IF expressão THEN comandos
	;

parametro:
	
	;


/*definicao de expressao*/

expressao:
	expressao_aritmetica
	| expressao EQ expressao_aritmetica
	| expressao LT expressao_artimetica
	| expressao GT expressao_artimetica
	| expressao NE expressao_artimetica
	| expressao GE expressao_artimetica
	| expressao LE expressao_artimetica
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
	variavel
	| INTEGERNUMBER
	| REALNUMBER
	| LPARENTESIS expressao RPARENTESIS
	| NOT fator
	| SUB fator
	;

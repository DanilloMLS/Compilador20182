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

//variavel inicial
program:
	cabecalho declaracoes// bloco DOT
	;

//1ª parte: cabeçalho
cabecalho:
	PROGRAM ID SEMICOMMA
	{printf ("\n programa %s\n",$2);}
	;

//2ª parte: declarações
declaracoes:
	declaracoes declaracao// declaracao_subprogramas
	|
	;

declaracao:
	declaracoes_variaveis
	|declaracoes_subprogramas
	;

//declaração de variáveis (primitivas e estruturadas)
declaracoes_variaveis:
	VAR bloco_variaveis
	{printf ("declaracao\n");}
	//|declaracoes_variaveis bloco_tipos
	;

bloco_variaveis:
	lista_variaveis
	|bloco_variaveis lista_variaveis
	;	

lista_variaveis:
	lista_identificadores COLON tipo SEMICOMMA
	;

lista_identificadores:
	ID
	| lista_identificadores COMMA ID
	;

tipo:
	tipo_primitivo
	{printf(" variáveis %s\n",$1);}
	|tipo_estruturado
	{printf(" arrays %s\n",$1);}
	;

tipo_primitivo:
	INTEGER
	{printf(" inteiro");}
	|REAL
	{printf(" real");}
	;

tipo_estruturado:
	ARRAY dimensao OF tipo_primitivo
	{printf(" estruturado");}
	;


dimensao:
	LBRACKETS INTNUMBER DOT DOT INTNUMBER RBRACKETS
	;

//declaração de um procedimento
declaracoes_subprogramas:
	cabecalho_procedimento variaveis_procedimento bloco SEMICOMMA
	;

cabecalho_procedimento:
	PROCEDURE ID parametros SEMICOMMA
	{printf("procedimento %s\n",$2);}
	;

//parâmetros de um procedimento
parametros:
	LPARENTESIS listas_parametros RPARENTESIS
	|
	;

listas_parametros:
	lista_parametro
	|listas_parametros SEMICOMMA lista_parametro
	;

lista_parametro:
	lista_identificadores COLON tipo_primitivo
	;

variaveis_procedimento:
	VAR bloco_variaveis
	{printf(" variável de procedimento ");}
	|
	;

//3ª parte - blocos
bloco:
	BEGINN END

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

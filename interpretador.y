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

declaracoes:
	declaracoes declaracao// declaracao_subprogramas
	|
	;

declaracao:
	declaracoes_variaveis
	|declaracoes_subprogramas
	;

declaracoes_subprogramas:
	PROCEDURE
	{printf("procedimento\n");}
	;

//2ª parte: declarações
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

dimensao:
	LBRACKETS INTNUMBER DOT DOT INTNUMBER RBRACKETS
	;

lista_identificadores:
	ID
	| lista_identificadores COMMA ID
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

tipo:
	tipo_primitivo
	{printf(" variáveis %s\n",$1);}
	|tipo_estruturado
	{printf(" arrays %s\n",$1);}
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

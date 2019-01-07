%{
#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
#include "tabela.h"
#include "tabela.c"
#include "arvore.h"
int yylex(void);
void yyerror(char *);
pilha_contexto *pilha;
char* cod_ids[20];
int count_ids;
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
	cabecalho declaracoes bloco DOT
	;

//1ª parte: cabeçalho
cabecalho:
	PROGRAM ID SEMICOMMA
	{printf ("\n programa %s\n",$2);}
	;

//2ª parte: declarações
declaracoes:
	declaracoes declaracao
	|
	;

declaracao:
	declaracoes_variaveis
	|declaracoes_subprogramas
	;

//declaração de variáveis (primitivas e estruturadas)
declaracoes_variaveis:
	VAR
	{printf ("declaracao - VAR\n");}
	bloco_variaveis
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
	//{printf(" primitivos %s\n",$1);}
	|tipo_estruturado
	//{printf(" arrays %s\n",$1);}
	;

tipo_primitivo:
	INTEGER
	|REAL
	;

tipo_estruturado:
	ARRAY dimensao OF tipo_primitivo
	;


dimensao:
	LBRACKETS INTNUMBER DOT DOT INTNUMBER RBRACKETS
	;

//declaração de um procedimento
declaracoes_subprogramas:
	cabecalho_procedimento variaveis_procedimento bloco SEMICOMMA
	;

cabecalho_procedimento:
	PROCEDURE ID
	{printf("procedimento %s\n",$2);}	
	parametros SEMICOMMA
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
	VAR
	{printf(" variáveis de procedimento\n");}
	bloco_variaveis
	|
	;

//3ª parte - blocos
bloco:
	BEGINN
	{printf("bloco\n");}
	comandos END
	|
	;

comandos:
	comando SEMICOMMA
	|comandos comando SEMICOMMA
	;

comando:
	atribuicao
	|chamada_procedimento
	|leitura //read
	|repeticao //while
	|escrita //write
	|condicao //if then else
	;

atribuicao:
	variavel ATTR expressao
	;

chamada_procedimento:
	ID LPARENTESIS lista_identificadores RPARENTESIS
	;

leitura:
	READ LPARENTESIS variavel RPARENTESIS
	{printf(" leitura de %s ",$3);}
	;

expressao:
	expressao_simples
	|expressao relop expressao_simples
	;

relop:
	EQ
	|NE
	|LT
	|LE
	|GE
	|GT
	;

expressao_simples:
	termo
	|expressao_simples addop termo
	|
	;

addop:
	ADD
	|SUB
	|OR
	;

termo:
	fator
	|termo multop fator
	;

multop:
	MULT
	|DIV
	|AND
	;

fator:
	variavel
	|INTNUMBER
	|REALNUMBER
	|LPARENTESIS expressao RPARENTESIS
	|NOT fator
	;

variavel:
	indexada
	|ID
	;

indexada:
	ID LBRACKETS INTNUMBER RBRACKETS
	;

repeticao:
	WHILE expressao DO COLON bloco
	;

escrita:
	WRITE expressao
	{printf("write\n");}
	;

condicao:
	IF expressao THEN bloco ELSE bloco
	{printf("if them else\n");}
	|IF expressao THEN bloco
	{printf("if then\n");}
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

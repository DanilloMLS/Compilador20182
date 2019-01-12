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
char* cod_ids[100];
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
	//{printf ("declaracao - VAR\n");}
	bloco_variaveis
	;

bloco_variaveis:
	lista_variaveis
	|bloco_variaveis lista_variaveis
	;	

lista_variaveis:
	//não funciona
	lista_identificadores COLON tipo SEMICOMMA
	{
		for(int i = 0; i < count_ids; i++){
			simbolo* s = localizar_simbolo_no_contexto_atual (topo_pilha(pilha),cod_ids[i]);
			if(s == NULL && topo_pilha(pilha) != NULL){
				s = addTypeID(cod_ids[i], $3);
				inserir_simbolo(topo_pilha(pilha), s);
			}else{
				yyerror("Identificador já foi declarado nesse escopo");
			}
		}
		count_ids = 0;
	}
	;

lista_identificadores:
	ID
	{
		printf("entrou identf sozinho %s \n",$1);
		cod_ids[count_ids] = (char*)$1;
		count_ids++; 
	}
	| lista_identificadores COMMA ID
	{
		printf("entrou lista de identf %s \n",$3);
		cod_ids[count_ids] = (char*)$3;
		count_ids++; 
	}
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
	//{printf(" variáveis de procedimento\n");}
	bloco_variaveis
	|
	;

//3ª parte - blocos
bloco:
	{
		tabela * contexto = criar_contexto(topo_pilha(pilha));
		pilha = empilhar_contexto(pilha, contexto);
	}
	BEGINN
	{printf("bloco\n");}
	comandos END
	{
		imprimir_contexto(topo_pilha(pilha));
		desempilhar_contexto(&pilha);
	}
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
	//{printf(" leitura de %s ",$3);}
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
	|MOD
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
	//{printf("write\n");}
	;

condicao:
	IF expressao THEN bloco ELSE bloco
	//{printf("if them else\n");}
	|IF expressao THEN bloco
	//{printf("if then\n");}
	;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

simbolo* addTypeID(char* lexema, int type){
	simbolo* s = criar_simbolo(lexema, type);
	return s;
}

void setTipoExp(no_arvore *n, no_arvore* expr1, no_arvore* expr2){
    
   if(expr1->dado.expr->tipo == REALNUMBER || expr2->dado.expr->tipo == REALNUMBER)
        n->dado.expr->tipo = REALNUMBER;
   else
        n->dado.expr->tipo = INTNUMBER; 
    
   //printf("tipo da expressão--%d ", n->dado.expr->tipo);
}

int main(void) {
	pilha = NULL;
	yyparse();
	return 0;
}

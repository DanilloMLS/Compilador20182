%{
#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
#include "tabela.h"
#include "arvore.h"
#include "tabNumero.h"
int yylex(void);
void yyerror(char *);
pilha_contexto *pilha;
char* cod_ids[100];
int count_ids;
%}

%token	NUMBER
%token	ATTR
%token	LE GE NE LT GT EQ

%token	AND ARRAY BEGINN
%token	DIV DO ID
%token	IF THEN ELSE
%token	END EXPR MOD
%token	NOT OF OR
%token	PROCEDURE PROGRAM
%token	READ VAR
%token	TIPOBOOL TIPOINT TIPOREAL TIPO
%token	WHILE WRITE

%%
/*definicao de programa*/
program:
	PROGRAM ID ';'
	;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}


int main(void) {
	pilha = NULL;
	count_ids = 0;
	yyparse();
	return 0;
}

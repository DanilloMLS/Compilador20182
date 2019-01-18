%{
#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
#include "tabNumero.h"

void yyerror(const char *str){
	fprintf(stderr,"error: %s\n",str);
}

int yywrap(){
	return 1;
}

main(){
	yyparse();
}
%}

%token		ATTR LE GE NE LT GT EQ
%token		AND ARRAY BEGINN BOOLEAN
%token		DO IF THEN ELSE END INTEGER
%token		NOT OF OR PROCEDURE
%token		PROGRAM READ REAL VAR
%token		FOR WRITE TRUE FALSE
%token		NUMBER ID TYPE TO
%token		ADD SUB MULT DIVV MOD

%left ADD SUB
%left MOD DIVV MULT
%left OR
%left AND
%left NOT

%nonassoc UMINUS
%nonassoc ELSE
%nonassoc NO_ELSE

%%

programa:
	cabecalho declaracoes blocoprincipal
	;

cabecalho:
	PROGRAM ID ';'
	;

declaracoes:
	declaracoes declidentificadores
	|declaracoes declprocedimentos
	|
	;

declidentificadores:
	VAR listasident
	;

listasident://cada linha de variaveis/arrays em VAR
	listasident listavar ';'
	|listasident listaarray ';'
	|
	;

listavar://tabela
	listaids ':' TYPE
	;

listaarray://tabela
	listaids ':' ARRAY '['NUMBER '.''.' NUMBER']' OF TYPE
	;

listaids://tabela
	listaids ',' ID
	|ID
	;

declprocedimentos:
	cabecalhoproc declproc blocoproc
	;

cabecalhoproc:
	PROCEDURE ID argumentos';'
	;

argumentos:
	'('listaargs')'
	|
	;

listaargs:
	listaargs ';' listavar
	|listavar
	|
	;

declproc:
	VAR listasident
	|
	;

blocoproc:
	bloco';'
	;

blocoprincipal:
	bloco'.'
	;

bloco:
	BEGINN comandos END
	;

comandos:
	comandos comando
	|
	;

comando:
	atribuicao
	|condicao
	|repeticao
	|WRITE'('expressao')'';'
	|READ'('ID')'';'
	;

atribuicao:
	ID ATTR expressao';'
	;

expressao:
	NUMBER
	|ID
	|expressao ADD expressao
	|expressao SUB expressao
	|expressao MULT expressao
	|expressao DIVV expressao
	|expressao MOD expressao
	|'('expressao')'
	|SUB expressao %prec UMINUS
	;

condicao:
	IF '('expressaobool')' THEN ':' bloco ';' %prec NO_ELSE
	|IF '('expressaobool')' THEN ':' bloco ELSE bloco ';'
	;

repeticao:
	FOR atribuicaofor TO NUMBER DO ':' bloco ';'
	;

atribuicaofor:
	ID ATTR expressao
	;

expressaobool:
	TRUE
	|FALSE
	|BOOLEAN
	|expressao AND expressao
	|expressao OR expressao
	|NOT expressao
	|expressao LT expressao
	|expressao LE expressao
	|expressao GT expressao
	|expressao GE expressao
	|expressao EQ expressao
	|expressao NE expressao
	;

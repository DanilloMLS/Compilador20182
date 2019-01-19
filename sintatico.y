%{
#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
#include "tabela.h"
#include "tabela.c"//eu não sei pq raios só funciona assim
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
%}

%token		ATTR LE GE NE LT GT EQ
%token		AND ARRAY BEGINN BOOLEAN
%token		DO IF THEN ELSE END INTEGER
%token		NOT OF OR PROCEDURE
%token		PROGRAM READ REAL VAR
%token		FOR WRITE TRUE FALSE
%token		NUMBER ID TYPE TO
%token		ADD SUB MULT DIVV MOD

%token BLOCK EXPR STMTS

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
	cabecalho blocoprincipal'.'
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
	{
		for(int i = 0; i < count_ids; i++){
			simbolo* s = localizar_simbolo_no_contexto_atual(topo_pilha(pilha), cod_ids[i]);
			if(s == NULL && topo_pilha(pilha) != NULL){
				s = criar_simbolo(cod_ids[i], $3);
				inserir_simbolo(topo_pilha(pilha), s);
			}else{
				yyerror("O identificador já existe!");
			}
		}
		count_ids = 0;
	}
	;

listaarray://tabela
	listaids ':' ARRAY '['NUMBER '.''.' NUMBER']' OF TYPE
	;

listaids://tabela
	listaids ',' ID
	{
		cod_ids[count_ids] = (char*)$3;
		count_ids++;
	}
	|ID
	{
		cod_ids[count_ids] = (char*)$1;
		count_ids++;
	}
	;

declprocedimentos:
	cabecalhoproc corpoproc
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

corpoproc:
	//bloco';'
	blocoproc ';'
	;

blocoproc:
	{	//coloca o contexto (o bloco) em uma pilha
		tabela * contexto = criar_contexto(topo_pilha(pilha));
		pilha = empilhar_contexto(pilha, contexto);
		//imprimir_contexto(contexto);
	}

	declaracoes BEGINN comandos END

	{
		if(topo_pilha(pilha) != NULL) { //imprime o contexto e desempilha
			imprimir_contexto(topo_pilha(pilha));
		    	desempilhar_contexto(&pilha);}
		no_arvore* n = criar_no_bloco((void*)$4);//cria um nó do tipo bloco na árvore
		//no_arvore* p = ((no_arvore*)$4);
		$$ = (long int)n;
	}
	;

blocoprincipal:
	{	//coloca o contexto (o bloco) em uma pilha
		tabela * contexto = criar_contexto(topo_pilha(pilha));
		pilha = empilhar_contexto(pilha, contexto);
		//imprimir_contexto(contexto);
	}

	declaracoes BEGINN comandos END

	{
		if(topo_pilha(pilha) != NULL) { //imprime o contexto e desempilha
			imprimir_contexto(topo_pilha(pilha));
		    	desempilhar_contexto(&pilha);}
		no_arvore* n = criar_no_bloco((void*)$4);//cria um nó do tipo bloco na árvore
		//no_arvore* p = ((no_arvore*)$4);
		$$ = (long int)n;
	}
	;

bloco:
	{	//coloca o contexto (o bloco) em uma pilha
		tabela * contexto = criar_contexto(topo_pilha(pilha));
		pilha = empilhar_contexto(pilha, contexto);
		//imprimir_contexto(contexto);
	}

	BEGINN comandos END

	{
		if(topo_pilha(pilha) != NULL) { //imprime o contexto e desempilha
			imprimir_contexto(topo_pilha(pilha));
		    	desempilhar_contexto(&pilha);}
		no_arvore* n = criar_no_bloco((void*)$4);//cria um nó do tipo bloco na árvore
		$$ = (long int)n;
	}
	;

comandos:
	comandos comando
	{
		no_arvore *n = criar_no_stmts((void*)$1, (no_arvore*)$2);
		$$ = (long int)n;
	}
	|
	;

comando:
	atribuicao
	|condicao
	|repeticao
	|WRITE'('expressao')'';'
	{
		no_arvore *n = criar_no_write((void*)$3);
		$$ = (long int)n;
	}
	|READ'('ID')'';'
	{
		simbolo* s = localizar_simbolo_no_contexto_atual(topo_pilha(pilha), (char*) $3);
		if(s != NULL){
			no_arvore *n = criar_no_read($3);
			$$ = (long int)n;
		}else{
			yyerror("Identificador nao encontrado");
		}
	}
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

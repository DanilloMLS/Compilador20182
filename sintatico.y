%{
#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
#include "tabela.h"
#include "tabela.c"
#include "tabNumero.h"
#include "arvore.h"
#include "arvore.c"
#include "codigo_intermediario.h"
#include "codigo_intermediario.c"

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

%token BLOCK EXPR STMTS IFELSE CHAMADA

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
	cabecalho bloco'.'
	{imprimir_arvore((no_arvore*)$2);}
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
				//printf("simbolo %s",s->lexema);
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
	
	PROCEDURE ID argumentos ';' bloco ';'
	{
		simbolo* s = localizar_simbolo_no_contexto_atual(topo_pilha(pilha), (char*)$2);
		if(s == NULL && topo_pilha(pilha) != NULL){
			s = criar_simbolo((char*)$2, 0);
			//printf("simbolo %s",s->lexema);
			inserir_simbolo(topo_pilha(pilha), s);
			no_arvore* n = criar_no_procedure((simbolo*)s, (void*)$3, (void*)$5);
			$$ = (long int)n;
			imprimir_arvore((no_arvore*)$5);
		}else{
			yyerror("O identificador já existe!");
		}
	}
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

bloco:
	{	//coloca o contexto (o bloco) em uma pilha
		tabela * contexto = criar_contexto(topo_pilha(pilha));
		pilha = empilhar_contexto(pilha, contexto);
		//imprimir_contexto(contexto);
	}

	declaracoes BEGINN comandos END

	{
		if(topo_pilha(pilha) != NULL) { //imprime o contexto e desempilha
			imprimir_contexto(topo_pilha(pilha));
		    	desempilhar_contexto(&pilha);
		}
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
	{
		no_arvore* n = criar_no_stmts(NULL, NULL);
        	$$ = (long int)n;
	}
	;

comando:
	atribuicao
	{gerar_codigo((no_arvore *) $1);}
	|condicao
	//{gerar_codigo((no_arvore *) $1);}
	|repeticao
	|chamadafuncao
	|WRITE'('expressao')'';'
	{
		no_arvore *n = criar_no_write((void*)$3);
		$$ = (long int)n;
	}
	|READ'('ID')'';'
	{
		simbolo* s = localizar_simbolo_no_contexto_atual(topo_pilha(pilha), (char*) $3);
		if(s == NULL){
			yyerror("Identificador não declarado");
		}else{
			no_arvore *n = criar_no_read(s);
			$$ = (long int)n;
		}
	}
	;

atribuicao:
	ID ATTR expressao';'
	{
		simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) $1);
		no_arvore* expr = (no_arvore*)$3;
		if(s == NULL)
			yyerror("Identificador não declarado");
		else  {
			if((s->tipo != expr->dado.expr->tipo) && (s->tipo == INTEGER)){
				yyerror("Tipos incompatíveis");
			}else{
				no_arvore *n = criar_no_atribuicao(s, (void *) $3);
				$$ = (long int) n;
			}
		}
	}
	;

expressao:
	NUMBER
	{
		numero *num = (numero*)$1;
		no_arvore *n = criar_no_expressao(NUMBER, (void *) $1, NULL);
		n->dado.expr->tipo = num->tipo;
		$$ = (long int) n;
	}
	|ID
	{
		simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) $1);
		if(s == NULL)
			yyerror("Identificador não declarado");
		else  {
			no_arvore *n = criar_no_expressao(ID, (simbolo*)$1, NULL);
			n->dado.expr->tipo = s->tipo;
			$$ = (long int) n;
		}
	}
	|ID '['NUMBER']'
	{
		simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) $1);
		if(s == NULL)
			yyerror("Identificador não declarado");
		else{
			numero *num = (numero*)$3;
			no_arvore *n = criar_no_expressao(NUMBER, (void *) $3, NULL);
			n->dado.expr->tipo = num->tipo;
			$$ = (long int) n;

			if(num->tipo == REAL){
				yyerror("Valor de índice deve ser integer");
			}
		}
	}
	|expressao ADD expressao
	{
		no_arvore *n = criar_no_expressao(ADD, (void *) $1, (void *) $3); 
		if(((no_arvore*)$1)->dado.expr->tipo == REAL || ((no_arvore*)$3)->dado.expr->tipo == REAL){
			n->dado.expr->tipo = REAL;
		}else{
			n->dado.expr->tipo = INTEGER;
		}
		$$ = (long int) n;
	}
	|expressao SUB expressao
	{
		no_arvore *n = criar_no_expressao(SUB, (void *) $1, (void *) $3); 
		if(((no_arvore*)$1)->dado.expr->tipo == REAL || ((no_arvore*)$3)->dado.expr->tipo == REAL){
			n->dado.expr->tipo = REAL;
		}else{
			n->dado.expr->tipo = INTEGER;
		}
		$$ = (long int) n;
	}
	|expressao MULT expressao
	{	printf("multip");
		no_arvore *n = criar_no_expressao(MULT, (void *) $1, (void *) $3); 
		if(((no_arvore*)$1)->dado.expr->tipo == REAL || ((no_arvore*)$3)->dado.expr->tipo == REAL){
			n->dado.expr->tipo = REAL;
		}else{
			n->dado.expr->tipo = INTEGER;
		}
		$$ = (long int) n;
	}
	|expressao DIVV expressao
	{
		no_arvore *n = criar_no_expressao(DIVV, (void *) $1, (void *) $3); 
		n->dado.expr->tipo = REAL;
		$$ = (long int) n;
	}
	|expressao MOD expressao
	{
		no_arvore *n = criar_no_expressao(MOD, (void *) $1, (void *) $3); 
		n->dado.expr->tipo = INTEGER;
		$$ = (long int) n;
	}
	|'('expressao')'
	{$$ = $2;}
	|SUB expressao %prec UMINUS
	{
		no_arvore *n = criar_no_expressao(UMINUS, NULL, (void *) $2); 
		n->dado.expr->tipo = ((no_arvore*)$2)->dado.expr->tipo;
		$$ = (long int) n;
	}
	;

expressaobool:
	expressao AND expressao
	{
		no_arvore *n = criar_no_expressao(AND, (void*)$1, (void *)$3); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	|expressao OR expressao
	{
		no_arvore *n = criar_no_expressao(OR, (void*)$1, (void *)$3); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	|NOT expressao
	{
		no_arvore *n = criar_no_expressao(NOT, NULL, (void *)$2); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	|expressao LT expressao
	{
		no_arvore *n = criar_no_expressao(LT, (void*)$1, (void *)$3); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	|expressao LE expressao
	{
		no_arvore *n = criar_no_expressao(LE, (void*)$1, (void *)$3); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	|expressao GT expressao
	{
		no_arvore *n = criar_no_expressao(GT, (void*)$1, (void *)$3); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	|expressao GE expressao
	{
		no_arvore *n = criar_no_expressao(GE, (void*)$1, (void *)$3); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	|expressao EQ expressao
	{
		no_arvore *n = criar_no_expressao(EQ, (void*)$1, (void *)$3); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	|expressao NE expressao
	{
		no_arvore *n = criar_no_expressao(NE, (void*)$1, (void *)$3); 
		n->dado.expr->tipo = BOOLEAN;
		$$ = (long int) n;
	}
	;

condicao:
	IF '('expressaobool')' THEN ':' bloco ';' %prec NO_ELSE
	{
		no_arvore *n = criar_no_ifelse((void*)$3, (void*)$7, NULL);
		$$ = (long int) n;
	}
	|IF '('expressaobool')' THEN ':' bloco ELSE bloco ';'
	{
		no_arvore *n = criar_no_ifelse((void*)$3, (void*)$7, (void*)$9);
		$$ = (long int) n;
	}
	;

repeticao:
	FOR atribuicaofor TO NUMBER DO ':' bloco ';'
	{
		no_arvore *n = criar_no_for((void*)$2,(numero*)$4,(void*)$7);
		$$ = (long int) n;
	}
	;

atribuicaofor:
	ID ATTR expressao
	{
		simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) $1);
		if(s == NULL)
			yyerror("Identificador não declarado");
		else  {
			no_arvore *n = criar_no_atribuicao(s, (void *) $3);
			$$ = (long int) n;
		}
	}
	;

chamadafuncao:
	ID '('listapar')'';'
	{
		simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) $1);
		if(s == NULL)
			yyerror("Procedimento não declarado");
		else  {
			no_arvore *n = criar_no_chamada((simbolo*)s, (void*)$3);
			$$ = (long int) n;
		}
	}
	;

listapar:
	args
	|
	;

args:
	args ',' expressao
	|expressao
	;

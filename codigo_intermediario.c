#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "codigo_intermediario.h"
#include "y.tab.h"

int temp_ctr = 1;

char * gerar_temp() {
	char buffer[256];
	sprintf(buffer, "t%d", temp_ctr++);
	return strdup(buffer);
}


void gerar_codigo(no_arvore * raiz) {
	if(raiz != NULL) {
		switch(raiz->tipo) {
			case EXPR: 
				gerar_codigo_expr(raiz);
				break;
			case ATTR:
				gerar_codigo_attr(raiz);
				return;
			case IFELSE:
				//printf("entrou em expr");
				gerar_codigo_cond(raiz);
				return;
			/*case BOOLEAN:
				gerar_codigo_bool(raiz);
				break;*/
			/*case READ:
				gerar_codigo_read(raiz);
				return;*/
		}

	}
}

char * gerar_codigo_expr(no_arvore *raiz) {
	char buffer[256];
	char *addr1, *addr2, *addr3;
	if(raiz != NULL) {
		simbolo *s;
		t_expr * dado = raiz->dado.expr;
		//printf("juqwewqhiuhwqiu");
		switch (dado->op) {
			case NUMBER: 
				sprintf(buffer, "%d", (int) dado->dir);
				return strdup(buffer);
			case ID:
				s = (simbolo *) dado->dir;
				return s->lexema;

			case ADD:
				addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				addr2 = gerar_codigo_expr((no_arvore *) dado->esq);
				addr3 = gerar_temp(); 				
				printf("%s = %s '+' %s\n", addr3, addr1, addr2);
				return addr3;

			case SUB:
				addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				addr2 = gerar_codigo_expr((no_arvore *) dado->esq);
				addr3 = gerar_temp(); 				
				printf("%s = %s '-' %s\n", addr3, addr1, addr2);
				return addr3;
			
			case MULT:
				addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				addr2 = gerar_codigo_expr((no_arvore *) dado->esq);
				addr3 = gerar_temp(); 				
				printf("%s = %s '*' %s\n", addr3, addr1, addr2);
				return addr3;

			case DIVV:
				addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				addr2 = gerar_codigo_expr((no_arvore *) dado->esq);
				addr3 = gerar_temp(); 				
				printf("%s = %s '/' %s\n", addr3, addr1, addr2);
				return addr3;

			case MOD:
				addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				addr2 = gerar_codigo_expr((no_arvore *) dado->esq);
				addr3 = gerar_temp(); 				
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;
			
			

		}
	}	
}



void gerar_codigo_attr(no_arvore *raiz) {
	t_attr * dado = raiz->dado.attr;	
	char * addr = gerar_codigo_expr(dado->expressao);
	simbolo *s = (simbolo *) dado->resultado;
	printf("%s = %s\n", s->lexema, addr);
}

void gerar_codigo_cond(no_arvore *raiz) {
	//printf("juqwewqhiuhwqiu");
	t_ifelse * dado = raiz->dado.ifelse;
	char * addr = gerar_codigo_bool(dado->expbool_if);
	printf("if_false %s jump L2", addr);
}

char * gerar_codigo_read(no_arvore *raiz) {
	char buffer[256];
	char *addr1;
	simbolo *s;
	t_read * dado = raiz->dado.read;
	s = (simbolo *) dado->id;
	addr1 = s->lexema;
	printf("read %s",addr1);
}

char * gerar_codigo_bool(no_arvore *raiz) {
	char buffer[256];
	char *addr1, *addr2, *addr3; 		
	if(raiz != NULL) {
		simbolo *s;
		t_expr * dado = raiz->dado.expr;
		no_arvore *no1 = (no_arvore *) dado->dir;
		no_arvore *no2 = (no_arvore *) dado->esq;
		switch (dado->op) {
			case NUMBER: 
				sprintf(buffer, "%d", (int) dado->dir);
				return strdup(buffer);
			case ID:
				s = (simbolo *) dado->dir;
				return s->lexema;
			case AND:
				if(no1->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				}
				
				if(no2->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->esq);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->esq);
				}
				//addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				addr3 = gerar_temp();
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;

			case OR:
				if(no1->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				}
				
				if(no2->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->esq);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->esq);
				}
				//addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				addr3 = gerar_temp();
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;
			
			case NOT:
				addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				//addr2 = gerar_codigo_expr((no_arvore *) dado->esq);
				addr3 = gerar_temp(); 				
				printf("%s = %c %s\n", addr3, dado->op, addr1);
				return addr3;

			case GE:
				if(no1->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				}
				
				if(no2->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->esq);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->esq);
				}
				//addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				addr3 = gerar_temp();
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;

			case LE:
				if(no1->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				}
				
				if(no2->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->esq);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->esq);
				}
				//addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				addr3 = gerar_temp();
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;

			case GT:
				if(no1->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				}
				
				if(no2->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->esq);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->esq);
				}
				//addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				addr3 = gerar_temp();
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;

			case LT:
				if(no1->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				}
				
				if(no2->tipo == BOOLEAN){
					addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				}else{
					addr2 = gerar_codigo_expr((no_arvore *) dado->esq);
				}
				//addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				addr3 = gerar_temp();
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;

			case EQ:
				if(no1->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				}
				
				if(no2->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->esq);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->esq);
				}
				//addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				addr3 = gerar_temp();
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;

			case NE:
				if(no1->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->dir);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->dir);
				}
				
				if(no2->tipo == BOOLEAN){
					addr1 = gerar_codigo_bool((no_arvore *) dado->esq);
				}else{
					addr1 = gerar_codigo_expr((no_arvore *) dado->esq);
				}
				//addr2 = gerar_codigo_bool((no_arvore *) dado->esq);
				addr3 = gerar_temp();
				printf("%s = %s %c %s\n", addr3, addr1, dado->op, addr2);
				return addr3;
		}
	}	
}

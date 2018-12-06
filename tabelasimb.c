#include "tabelasimb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializar(tabela_simbolo *tabela) {
	tabela->primeiro = NULL;
	tabela->ultimo = NULL;
	tabela->proximo_codigo = 1;
}


void inserir_simbolo(tabela_simbolo *tabela, simbolo *s) {
	no_tabela *novo = (no_tabela *) malloc(sizeof(struct no_tabela));	
	novo->proximo = NULL;
	novo->dado = s;
	novo->dado->cod = tabela->proximo_codigo++;

	if(tabela->primeiro == NULL) {
			tabela->primeiro = tabela->ultimo = novo;
	} else {
			tabela->ultimo->proximo = novo;
			tabela->ultimo = novo;
	}
}

simbolo * criar_simbolo(int cod, char *lexema, int tipo) {
	simbolo *s = (simbolo *) malloc(sizeof(struct simbolo));
	s->cod = cod;
	s->lexema = strdup(lexema);
	s->tipo = tipo;
	return s;
}


void exibir_tabela(tabela_simbolo *tabela){
	no_tabela * temp = tabela->primeiro;
	printf("\n\n");

	while(temp != NULL) {
			printf("%d %s \n", temp->dado->cod, temp->dado->lexema);
			temp = temp->proximo;
	}
}

simbolo * localizar_simbolo(tabela_simbolo *tabela, char *lexema){
	no_tabela *no;
	
	for(no = tabela->primeiro; no != NULL; no = no->proximo){
		if(strcmp(no->dado->lexema, lexema) == 0){
			return no->dado;
		}
	}
	
	return NULL;
}

int instalar_simbolo(tabela_simbolo *tabela, char *lexema) {
	simbolo *s = localizar_simbolo(tabela, lexema);
	
	if(s == NULL){
		s = criar_simbolo(tabela->proximo_codigo, lexema, 1);
		inserir_simbolo(tabela, s);
		tabela->proximo_codigo = tabela->proximo_codigo + 1;
		
		return s->cod;
	}else{
		return s->cod;
	}
}


#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
#include "y.tab.h"

//expressão
no_arvore * criar_no_expressao(int op, void *dir, void *esq) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = EXPR;
	novo->dado.expr =  criar_expressao(op, dir, esq);
	return novo;
}

t_expr * criar_expressao(int op, void *dir, void *esq) {
	t_expr * novo = (t_expr *) malloc(sizeof(t_expr));
	novo->op = op;
	novo->dir = dir;
	novo->esq = esq;
	return novo;
}

//atribuição
no_arvore * criar_no_atribuicao(simbolo *resultado, void *expressao) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = ATTR;
	novo->dado.attr =  criar_atribuicao(resultado, expressao);
	return novo;
}

t_attr * criar_atribuicao(simbolo *resultado, void *expressao){ 
	t_attr * novo = (t_attr *) malloc(sizeof(t_attr));
	novo->resultado = resultado;
	novo->expressao = expressao;
	return novo;
}

//blocos
no_arvore * criar_no_bloco(void* stmts){
	no_arvore *novo = (no_arvore*) malloc(sizeof(no_arvore));
	novo->tipo = BLOCK;
	novo->dado.bloco = criar_bloco(stmts);
	return novo;  
}

t_bloco * criar_bloco(void* stmts){
	t_bloco *novo = (t_bloco*) malloc(sizeof(t_bloco));
	novo->stmts = stmts;
	return novo;
}

//comandos
t_stmts * criar_stmts(void* stmts, no_arvore* stmt){
	t_stmts *novo = (t_stmts*) malloc(sizeof(t_stmts));
	novo->stmt = stmt;
	novo->stmts = stmts;
	return novo;
}

no_arvore * criar_no_stmts(void* stmts, no_arvore* stmt){
	no_arvore *novo = (no_arvore*) malloc(sizeof(no_arvore));
	novo->tipo = STMTS;
	novo->dado.stmts = criar_stmts(stmts, stmt);
	return novo;
}

//write
t_write * criar_write(void* expressao){
	t_write* novo = (t_write*) malloc(sizeof(t_write));
	novo->expressao = expressao;
	return novo;
}

no_arvore * criar_no_write(void* expressao){
	no_arvore *novo = (no_arvore*) malloc(sizeof(no_arvore));
	novo->tipo = WRITE;
	novo->dado.write = criar_write(expressao);
	return novo;
}

//read
t_read * criar_read(simbolo* id){
	t_read* novo = (t_read*) malloc(sizeof(t_read));
	novo->id = id;
	return novo;
}

no_arvore * criar_no_read(simbolo* id){
	no_arvore *novo = (no_arvore*) malloc(sizeof(no_arvore));
	novo->tipo = READ;
	novo->dado.read = criar_read(id);
	return novo;
}

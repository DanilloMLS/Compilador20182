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

//ifelse
t_ifelse * criar_ifelse(void* expbool_if, void* bloco_if, void* bloco_else){
	t_ifelse *novo = (t_ifelse*) malloc(sizeof(t_ifelse));
	novo->expbool_if = expbool_if;
	novo->bloco_if = bloco_if;
	novo->bloco_else = bloco_else;
	return novo;
}

no_arvore * criar_no_ifelse(void* expbool_if, void* bloco_if, void* bloco_else){
	no_arvore *novo = (no_arvore*) malloc(sizeof(no_arvore));
	novo->tipo = IFELSE;
	novo->dado.ifelse = criar_ifelse(expbool_if, bloco_if, bloco_else);
	return novo;
}

//for
t_for * criar_for(void* attrfor, numero* limite, void* bloco){
	t_for *novo = (t_for*) malloc(sizeof(t_for));
	novo->attrfor = attrfor;
	novo->limite = limite;
	novo->bloco = bloco;
	return novo;
}

no_arvore * criar_no_for(void* attrfor, numero* limite, void* bloco){
	no_arvore *novo = (no_arvore*) malloc(sizeof(no_arvore));
	novo->tipo = FOR;
	novo->dado.forr = criar_for(attrfor, limite, bloco);
	return novo;
}

void imprimir_arvore(no_arvore *no){
    if (no != NULL){

        switch (no->tipo){
            case BLOCK:
                imprimir_arvore(no->dado.stmts->stmt);
                printf("Bloco\n"); 
                break;
            
            case STMTS:           
                imprimir_arvore(no->dado.stmts->stmt);
                imprimir_arvore((no_arvore*)no->dado.stmts->stmts);           
                printf("Stmts\n"); 
                break;
            
            case ATTR:
                imprimir_arvore((no_arvore*)no->dado.attr->expressao); 
                printf("ATTR\n");
                break;
        
            case EXPR:
                if(no->dado.expr->op != NUMBER && no->dado.expr->op != ID){              
                    imprimir_arvore((no_arvore*)no->dado.expr->dir);
                    if(no->dado.expr->esq != NULL)
                        imprimir_arvore((no_arvore*)no->dado.expr->esq);
                }
                printf("EXPR\n");
                break;
            
            case WRITE:
                imprimir_arvore((no_arvore*)no->dado.write->expressao);
                printf("WRITE\n");                
                break;
                    
            case READ:
                printf("Read %s\n", no->dado.read->id->lexema);
                break;           
            
	    case IFELSE:
                printf("++++++++++++++++++++++++++++++++++++++++++++++\n");                
                
                
                imprimir_arvore((no_arvore*)no->dado.ifelse->bloco_if);
                imprimir_arvore((no_arvore*)no->dado.ifelse->expbool_if);
                printf("IF\n");

                if(no->dado.ifelse->bloco_else != NULL){
                    imprimir_arvore((no_arvore*)no->dado.ifelse->bloco_else);
                    printf("ELSE\n");
                } 
                
                printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
                break;

	    case FOR:
                printf("++++++++++++++++++++++++++++++++++++++++++++++\n");

                imprimir_arvore((no_arvore*)no->dado.forr->bloco);
                printf("limite máximo %d\n", no->dado.forr->limite->val.ival); 
                imprimir_arvore((no_arvore*)no->dado.forr->attrfor);
                printf("FOR\n");
                
                printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
                break;
            
            default:
                printf("Tipo inexistente -- Tipo %d\n", no->tipo);           
        }
        
        //printf("no --%d\n", no->tipo);       

    } //else {printf("NO vazio");}
}

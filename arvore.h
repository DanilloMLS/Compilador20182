#ifndef ARVORE_H
#define ARVORE_H

#include <string.h>
#include "tabela.h"
#include "y.tab.h"

typedef struct t_expr {
	int op; // + - / * UMINUS ID NUMERO
	int tipo; //float ou int
	void *dir, *esq;
	valor valor; // somente para interpretador
} t_expr;

//Cada construção da linguagem que será 
//compilada deverá ter um struct
typedef struct t_attr {
	simbolo *resultado;
	void *expressao;
} t_attr;

typedef struct t_bloco {
	void *stmts;
}t_bloco;

typedef struct t_stmts {
	struct no_arvore* stmt;
	void *stmts;
} t_stmts;

typedef struct t_write {
	void *expressao;
}t_write;

typedef struct t_read {
	simbolo *id;
}t_read;

typedef struct t_ifelse {
	void *expbool_if;
	void *bloco_if;
	void *bloco_else;
}t_ifelse;

typedef struct t_for{
	void* attrfor;
	numero* limite;
	void* bloco;
}t_for;

typedef struct t_procedure{
	simbolo *id;
	void *atributos;
	void *bloco;
}t_procedure;

typedef struct t_chamada{
	simbolo *id;
	void *argumentos;
}t_chamada;

typedef struct t_array{
	simbolo *id;
	int *indice;
}t_array;

//Simula a superclasse abstrata 
typedef union valor_sintatico {
	t_expr *expr;
	t_attr *attr;
	t_bloco *bloco;
	t_stmts *stmts;
	t_write *write;
	t_read *read;
	t_ifelse *ifelse;
	t_for *forr;
	t_procedure *procedure;
	t_chamada *chamada;
	t_array *array;
} valor_sintatico;

typedef struct no_arvore {
	int tipo; //expr, attr, stmt, ...
	valor_sintatico dado;
	//ponteiro para tabela de símbolos
} no_arvore;

no_arvore * criar_no_expressao(int op, void *dir, void *esq);
t_expr * criar_expressao(int op, void *dir, void *esq);

no_arvore * criar_no_atribuicao(simbolo *resultado, void *expressao);
t_attr * criar_atribuicao(simbolo *resultado, void *expressao);

t_bloco * criar_bloco(void *stmts);
no_arvore * criar_no_bloco(void *stmts);

t_stmts * criar_stmts(void *stmts, no_arvore* stmt);
no_arvore * criar_no_stmts(void *stmts, no_arvore* stmt);

t_write * criar_writeln(void *expressao);
no_arvore * criar_no_write(void *expressao);

t_read * criar_read(simbolo* id);
no_arvore * criar_no_read(simbolo* id);

t_ifelse * criar_ifelse(void* expbool_if, void* bloco_if, void* bloco_else);
no_arvore * criar_no_ifelse(void* expbool_if, void* bloco_if, void* bloco_else);

no_arvore * criar_no_for(void* attrfor, numero* limite, void* bloco);
t_for * criar_for(void* attrfor, numero* limite, void* bloco);

t_procedure * criar_procedure(simbolo* id, void* atributos, void* bloco);
no_arvore * criar_no_procedure(simbolo* id, void* atributos, void* bloco);

t_chamada * criar_chamada(simbolo* id, void* argumentos);
no_arvore * criar_no_chamada(simbolo* id, void* argumentos);

#endif

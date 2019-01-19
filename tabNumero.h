#ifndef TABELA_N_H
#define TABELA_N_H

typedef union valorNum {
	int ival;
	float fval;
} valorNum;

typedef struct numero {
	int tipo;
	valorNum val;
} numero;

numero *  criar_numero (valorNum val, int tipo);


#endif

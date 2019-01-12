#ifndef TABELA_N_H
#define TABELA_N_H

typedef union valor {
	int ival;
	float fval;
} valor;

typedef struct numero {
	int tipo;
	valor val;
} numero;

numero *  criar_numero (valor val, int tipo);


#endif

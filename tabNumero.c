#include <stdlib.h>
#include <stdio.h>
#include "tabNumero.h"

numero *  criar_numero (valor val, int tipo) {
	numero *novo = (numero *) malloc(sizeof(numero));
	novo->tipo = tipo;
	novo->val = val;
	return novo;
}

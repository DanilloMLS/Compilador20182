%{
#include <stdio.h>
#include "tabelasimb.h"

tabela_simbolo tab;
%}

delim		[ \t\n]
ws		{delim}+
letra		[a-zA-Z]
digito		[0-9]
numeroInteiro	-?{digito}+
id		({letra}|_)(_|{letra}|{digito})*
numeroReal	-?{digito}+(\.{digito}+)?(E[+-]?{digito}+)?
comentario	({})
divisor		(/)
subtracao	(-)
multiplicacao	([+])
adicao		([*])


lt		(<)
gt		(>)
ne		(<>)
eq		(=)
le		(<=)
ge		(>=)

%%

{ws} ;

and	{
	return AND;
}

array	{
	return ARRAY;
}

begin	{
	return BEGIN;
}

div	{
	return DIV;
}

do {
	return DO;
}

else	{
	return ELSE;
}

end	{
	return END;
}

for	{
	return FOR;
}

if	{
	return IF;
}

integer	{
	return yylval = T_INT;
	return TYPE;
}

mod	{
	return MOD;
}

not	{
	return NOT;
}

of	{
	return OF;
}

or	{
	return OR;
}

procedure	{
	return PROCEDURE;
}

program	{
	return PROGRAM;
}

read	{
	return READ;
}

then	{
	return THEN;
}

var	{
	return VAR;
}

while	{
	return WHILE;
}

write	{
	return WRITE;
}

:=	{ //Ver pq esse tem que ir
	return ATTR;
}

{adicao}	{
	return ADD;
}

{subtracao}	{
	return SUB;
}

{multiplicacao}	{
	return MULT;
}

{divisor}	{
	return DIVIS;
}

{comentario}	{
	//printf("%s",  yytext);
}

{lt}	{
	return LT;
}

gt		(>)
ne		(<>)
eq		(=)
le		(<=)
ge		(>=)

%%
: atribuição
; separação de instruções
< operador relacional
(>) operador relacional
[ índices do array
] índices do array
{ comentário
} comentário
- operação
+ operação
* operação
/ operação
= atribuição, comparação
( parênteses
) parênteses
, vírgula
. ponto final

int yywrap() {
	return 1;
}

int main(int argc, char * argv[]) {
	inicializar(&tab);
	yylex();
	exibir_tabela(&tab);
}


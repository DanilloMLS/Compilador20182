%{
#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
void yyerror(char *);
#include "tabela.h"
#include "y.tab.h"
#include "tabNumero.h"

extern tabela *tab;
%}

delim		[ \t\n]
ws		{delim}+
letra		[a-zA-Z_]
digito		[0-9]
numeroInteiro 	{digito}+
id		{letra}({letra}|{digito})*
numeroReal	{digito}+"."{digito}+

%%

{ws}		{}

{numeroInteiro}	{valor v;
		v.ival = atoi(yytext);
		yylval = (long long) criar_numero(v, TIPOINT);
		return NUMBER;}

{numeroReal}	{valor v;
		v.fval = atof(yytext);
		yylval = (long long) criar_numero(v, TIPOREAL);
		return NUMBER;}

":="		return ATTR;
"["		return *yytext;
"]"		return *yytext;
"<="		return LE;
">="		return GE;
"<>"		return NE;
"<"		return LT;
">"		return GT;
"="		return EQ;


and		return AND;
array		return ARRAY;
begin		return BEGINN;
boolean		{yylval = TIPOBOOL; return TIPO;}
div		return DIV;
do		return DO;
if		return IF;
then		return THEN;
else		return ELSE;
end		return END;
integer		{yylval = TIPOINT; return TIPO;}
mod		return MOD;
not		return NOT;
of		return OF;
or		return OR;
procedure	return PROCEDURE;
program		return PROGRAM;
read		return READ;
real		{yylval = TIPOREAL; return TIPO;}
var		return VAR;
while		return WHILE;
write		return WRITE;
true		{yyval = 0; return TRUE;}
false		{yyval = 1; return FALSE;}

[-+*;,.:(/)]	return *yytext;

{id}		{yylval = (long int) strdup(yytext);
		return ID;}
. 		yyerror("invalid character");

%%

int yywrap(void) {
	return 1;
}




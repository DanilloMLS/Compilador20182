%{
#include <stdio.h>
#include "tabelasimb.h"

tabela_simbolo tab;
%}

delim		[ \t\n]
ws		{delim}+
letra		[a-zA-Z_]
digito		[0-9]
numeroInteiro 	[0-9]*
id		{letra}({letra}|{digito})*
numeroReal	{digito}+(\.{digito}+)?(E[+-]?{digito}+)?

%%

{ws}		{}

{numeroReal}	yylval.real = atof(yytext); return REALNUMBER;
{numeroInteiro}	yylval.integer = atoi(yytext); return INTEGERNUMBER;
":="		return ATTR;
"<="		return LE;
"<"		return LT;
"="		return EQ;
"<>"		return NE;
">="		return GE;
">"		return GT;
"+"		return ADD;
"-"		return SUB;
"*"		return MULT;
"/"		return DIV;
","		return COMMA;
"."		return DOT;
":"		return COLON;
";"		return SEMICOMMA;
"["		return LBRACKETS;
"]"		return RBRACKETS;
"("		return LPARENTESIS;
")"		return RPARENTESIS;
"{"		return LCOMMENT;
"}"		return RCOMMENT;

and		return AND;
array		return ARRAY;
begin		return BEGIN;
div		return DIV;
do		return DO;
if		return IF;
then		return THEN;
else		return ELSE;
end		return END;
integer		return INTEGER;
mod		return MOD;
not		return NOT;
of		return OF;
or		return OR;
procedure	return PROCEDURE;
program		return PROGRAM;
read		return READ;
real		return REAL;
var		return VAR;
while		return WHILE;
write		return WRITE;

{id}		yylval.id = (char *) strdup( yytext ); return ID;


%%

int yywrap() {
	return 1;
}

int main(int argc, char * argv[]) {
	inicializar(&tab);
	yylex();
	exibir_tabela(&tab);
}



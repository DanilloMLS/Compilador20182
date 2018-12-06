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

{numeroInteiro}	{printf("<integer, %s>", yytext);}
{numeroReal}	{printf("<real, %s>", yytext);}
":="		{printf("<op, ATTR>");}
"<"		{printf("<relop, LT>");}
"<="		{printf("<relop, LE>");}
"="		{printf("<relop, EQ>");}
"<>"		{printf("<relop, NE>");}
">"		{printf("<relop, GT>");}
">="		{printf("<relop, GE>");}
"+"		{printf("<op, ADD>");}
"-"		{printf("<op, SUB>");}
"*"		{printf("<op, MULT>");}
"/"		{printf("<op, DIV>");}
","		{printf("<char, COMMA>");}
"."		{printf("<char, DOT>");}
":"		{printf("<char, TWODOTS>");}
";"		{printf("<char, SEMICOMMA>");}
"["		{printf("<schar, LBRACKETS>");}
"]"		{printf("<schar, RBRACKETS>");}
"("		{printf("<schar, LPARENTESIS>");}
")"		{printf("<schar, RPARENTESIS>");}
"{"		{printf("<schar, LCOMMENT>");}
"}"		{printf("<schar, RCOMMENT>");}

and		{printf("<log, AND>");}
array		{printf("<type, ARRAY>");}
begin		{printf("<command, BEGIN>");}
div		{printf("<op, DIV>");}
do		{printf("<command, DO>");}
if		{printf("<condition, IF>");}
then		{printf("<condition, THEN>");}
else		{printf("<condition, ELSE>");}
end		{printf("<command, END>");}
integer		{printf("<type, INTEGER>");}
mod		{printf("<op, MOD>");}
not		{printf("<log, NOT>");}
of		{printf("<command, OF>");}
or		{printf("<log, OR>");}
procedure	{printf("<procedure, PROCEDURE>");}
program		{printf("<statement, PROGRAM>");}
read		{printf("<command, READ>");}
real		{printf("<type, REAL>");}
var		{printf("<statement, VAR>");}
while		{printf("<command, WHILE>");}
write		{printf("<command, WRITE>");}

{id}		{int cod = instalar_simbolo(&tab,yytext);
		printf("<ID, %d>", cod);}


%%

int yywrap() {
	return 1;
}

int main(int argc, char * argv[]) {
	inicializar(&tab);
	yylex();
	exibir_tabela(&tab);
}



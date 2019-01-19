%{
#ifndef YYSTYPE
#define YYSTYPE long int
#endif
#include <stdio.h>
#include "y.tab.h"
#include "tabela.h"
#include "tabNumero.h"
#include "tabNumero.c"

void yyerror(char *);
extern tabela *tab;
%}

delim		[ \t\n]
ws		{delim}+
letra		[a-zA-Z_]
digito		[0-9]
numeroInteiro	{digito}+
numeroReal	{digito}+"."{digito}+
id		{letra}({letra}|{digito})*

%%

ws		{}
[,.;:()]	{return *yytext;}
\[		{return *yytext;}
\]		{return *yytext;}

\+		{return ADD;}
\-		{return SUB;}
\*		{return MULT;}
\/		{return DIVV;}
\%		{return MOD;}

":="		{return ATTR;}
"<="		{return LE;}
">="		{return GE;}
"<>"		{return NE;}
"<"		{return LT;}
">"		{return GT;}
"="		{return EQ;}

and		{return AND;}
array		{return ARRAY;}
begin		{return BEGINN;}
boolean		{return BOOLEAN;}
do		{return DO;}
for		{return FOR;}
if		{return IF;}
then		{return THEN;}
else		{return ELSE;}
end		{return END;}
integer		{yylval = INTEGER;
		return TYPE;}
not		{return NOT;}
of		{return OF;}
or		{return OR;}
procedure	{return PROCEDURE;}
program		{return PROGRAM;}
read		{return READ;}
real		{yylval = REAL;
		return TYPE;}
var		{return VAR;}
write		{return WRITE;}
to		{return TO;}
true		{yylval = 1;return TRUE;}
false		{yylval = 0;return FALSE;}

{numeroInteiro}	{valorNum v;
		v.ival = atoi(yytext);
		yylval = (long int) criar_numero(v, INTEGER);
		return NUMBER;}
{numeroReal}	{valorNum v;
		v.fval = atof(yytext);
		yylval = (long int) criar_numero(v, REAL);
		return NUMBER;}
{id}		{yylval = (long int) strdup(yytext);
		return ID;}


%%

int yywrap(){
	return 1;
}
/*lex example4.l
yacc -d example4.y
cc lex.yy.c y.tab.c -o example4
*/

all:	analisadorlexico

analisadorlexico:	lex.yy.c tabelasimb.c
	gcc -o analisadorlexico lex.yy.c tabelasimb.c -ll

lex.yy.c:	lexico.l
	lex lexico.l

clean: 
	rm analisadorlexico

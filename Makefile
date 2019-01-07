all: compilador
compilador: y.tab.c lex.yy.c tabela.c
	cc lex.yy.c y.tab.c -o compilador
y.tab.c: interpretador.y
	yacc -d interpretador.y
lex.yy.c: lexico.l
	lex lexico.l
clean:
	rm compilador
test: compilador entrada
	./compilador < entrada

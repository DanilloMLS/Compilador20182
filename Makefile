all: compilador
compilador: y.tab.c lex.yy.c tabela.c
	cc lex.yy.c y.tab.c -o compilador
y.tab.c: sintatico.y
	yacc -d sintatico.y
lex.yy.c: lexico.l
	lex lexico.l
clean:
	rm compilador
test: compilador entrada
	./compilador < entrada

all:flex yacc gcc

flex:lego.l
	flex -l lego.l

yacc:lego.y
	yacc -vd lego.y

gcc:y.tab.c
	gcc -o lego.out y.tab.c -ly -ll

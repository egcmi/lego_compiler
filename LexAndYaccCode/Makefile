all:flex yacc gcc

flex:strings.l
	flex -l strings.l

yacc:strings.y
	yacc -vd strings.y

gcc:y.tab.c
	gcc -o strings.out y.tab.c -ly -ll

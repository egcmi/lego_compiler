all:flex yacc gcc

flex:strings.l
	flex strings.l

yacc:strings.y
	yacc -d strings.y

gcc:y.tab.c
	cc lex.yy.c y.tab.c

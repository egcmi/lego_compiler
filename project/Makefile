all:yacc flex gcc

yacc:lego.y
	yacc -vd lego.y

flex:lego.l
	flex -l lego.l

gcc:y.tab.c
	gcc -o lego.out y.tab.c -ly -ll

run:
	./lego.out

clean:
	rm lego.out

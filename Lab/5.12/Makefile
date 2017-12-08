flex -l calc-file-lex.l
yacc -vd calc-file-yacc.y
    -v: generates the DFA
    -d: generate the y.tab.h file
gcc y.tab.c -ly -ll


*To read from an input file (called e.g. in-file.txt) run the command
./a.out < in-file.txt
%option noyywrap
%{
    #include <stdio.h>
    int TokenCont=0;
%}

digit  [0-9]
letter [a-zA-Z]
digits {digit}+
stringconst \"({letter}|{digit})+\"

%%
[ \t\n] {}

{letter}+ {printf("%d Word \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{digits} {printf("%d Number \"%d\" Lenght = %d\n",++TokenCont,atoi(yytext),yyleng);}

{stringconst} {printf("%d Str-Const \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}
%%

main()
{
    yylex();
}

%option noyywrap
%{
    #include <stdio.h>
    int TokenCont=0;
%}

op 		[+-<>]
digit   [0-9]
letter  [a-zA-Z]
key     (if|else|while|do|for)
int     {digit}+
real    {digit}*\.{digit}+
maths	({int}|{real})[ ]?{op}[ ]?({int}|{real})
id      ({letter}|_)({letter}|{digit})+
stringconst \"({letter}|{digit})+\"
error	(.*?)
%%
[ \t\n] {}

{key} {printf("%d Keyword \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{maths} {printf("%d Mathematical operation \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{real} {printf("%d Real number \"%f\" Lenght = %d\n",++TokenCont,atof(yytext),yyleng);}

{int} {printf("%d Integer \"%d\" Lenght = %d\n",++TokenCont,atoi(yytext),yyleng);}

{id}  {printf("%d Identifier \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{stringconst} {printf("%d Str-Const \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{error}	{printf("%d Not recognised \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

%%

main()
{
    yylex();
}

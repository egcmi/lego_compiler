%option noyywrap

%{
    #include <stdio.h>
    int TokenCont=0;
%}

eq			=
gr 			>
low			<
show 		SHOW
num			[0-9]
coord 		\({num}+\,{num}+\)
new			grid\ {num}+\ {num}+
dir			(left|right|up|down)
var			[A-Z]{num}{1,2}
height 		height\ ({coord}|{var})
fits 		fits\ {var}\ {coord}
bool 		({fits}|{height}\ ({eq}|{gr}|{low})\ {num})
set 		{var}\ {eq}\ place\ {coord}\ at\ {coord}
move 		move\ {var}\ ({dir}\ {num}|at\ {coord})
del 		delete\ ({var}|all|grid)
opt 		({move}|{set}|{del})
if 			if\ {bool}\ then\n{opt}(\nelse\n{opt})?
while		while\ {bool}\ do\n{opt}
error		(.*?)

%%
[ \t\n] {}

{new} {printf("%d Grid \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{coord} {printf("%d Coord \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{dir} {printf("%d Direction \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{var} {printf("%d Variable \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{height} {printf("%d Height \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{fits} {printf("%d Fits \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{set} {printf("%d Set \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{del} {printf("%d Delete \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{move} {printf("%d Move \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{bool} {printf("%d Bool \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{if} {printf("%d If \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{while} {printf("%d While \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

{error}	{printf("%d Not recognised \"%s\" Lenght = %d\n",++TokenCont,yytext,yyleng);}

%%

main()
{
    yylex();
}

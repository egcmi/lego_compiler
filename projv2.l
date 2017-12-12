%option noyywrap

%{
    #include <stdio.h>
    int TokenCont=0;
%}

show 		show
grid 		grid
num			[0-9]
coord 		\({num}+\,{num}+\)
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

{show}	{return SHOW;}
{grid}	{return GRID;}
{num}	{return NUM;}
{coord}	{return COORD;}
{dir}	{return DIR;}
{var}	{return VARIABLE};
{error}	{return ERROR;}

"="		return EQ;
">"		return GR;
"<"		retun LOW;

%%

main()
{
    yylex();
}

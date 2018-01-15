%option noyywrap

%{
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
	void yyerror(char *);
%}

num			[0-9]+
dir			(left|right|up|down)
var			[a-z]{num}{1,2}
gvar		[A-Z]{num}{1,2}

%%
[ \t\n]+ 	{/* do we need to skip blanks? */}

{num}		{yylval.value = atoi(yytext);
			 return NUM;}
{dir}		{yylval.lexeme = strdup(yytext);
			 return DIR;}
{var}		{yylval.lexeme = strdup(yytext);
			return VAR;}
{gvar}		{yylval.lexeme = strdup(yytext);
			return GVAR;}

[-()<>=+*/;{},] {return *yytext;}

"exit"		{return EXIT;}
"switch"	{return SWITCH;}
"show"		{return SHOW;}
"matrix"	{return MATRIX;}
"array"		{return ARRAY;}
"pyramid"	{return PYRAMID;}
"dome"		{return DOME;}
"grid"		{return GRID;}
"height"	{return HEIGHT;}
"fits"		{return FITS;}
"place"		{return PLACE;}
"delete"	{return DELETE;}
"all"		{return ALL;}
"at"		{return AT;}
"if"		{return IF;}
"then"		{return THEN;}
"else"		{return ELSE;}
"move"		{return MOVE;}
"and"		{return AND;}
"or"		{return OR;}
"=="		{return EQ;}

.			{yyerror("Unknown character");}

%%

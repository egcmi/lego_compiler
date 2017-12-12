%option noyywrap

%{
    #include <stdio.h>
    int TokenCont=0;
%}

num			[0-9]
dir			(left|right|up|down)
var			[A-Z]{num}{1,2}
error		(.*?)

%%
[ \t\n] {/* do we need to skip blanks? */}

{num}		{yylval.value = atoi(yytext);
			 return NUM;}
{dir}		{yylval.lexeme = strdup(yytext);
			 return DIR;}
{var}		{yylval.lexeme = strdup(yytext);
			return VAR;}
{error}		{return ERROR;}
"show"		{return SHOW;}
"grid"		{return GRID;}
"height"	{return HEIGHT;}
"fits"		{return FITS;}
"place"		{return PLACE};}
"delete"	{return DELETE};}
"all"		{return ALL};}
"if"		{return IF};}
"then"		{return THEN;}
"while"		{return WHILE;}
"do"		{return DO}
"else"		{return ELSE;}
"move"		{return MOVE;}
"and"		{return AND};}
"or"		{return OR};}
"=="		{return EQ;}
"="			{return ASSIGN;}
">"			{return GR;}
"<"			{return LOW;}

%%
%option noyywrap

%{
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    void yyerror(char *);
%}

num         [0-9]+
dir         (left|right|up|down)
type        (dome|pyramid|matrix) 
var         [a-z]{num}{1,2}
gvar        [A-Z]{num}{1,2}

%%
[ \t\n]+    {}

{num}       {yylval.value = atoi(yytext);
             return NUM;}
{dir}       {yylval.lexeme = strdup(yytext);
             return DIR;}
{var}       {yylval.lexeme = strdup(yytext);
            return VAR;}
{gvar}      {yylval.lexeme = strdup(yytext);
            return GVAR;}

{type}      {yylval.lexeme = strdup(yytext);
            return TYPE;}

[:(),=]     {return *yytext;}

"exit"      {return EXIT;}
"switch"    {return SWITCH;}
"show"      {return SHOW;}
"grid"      {return GRID;}
"height"    {return HEIGHT;}
"fits"      {return FITS;}
"place"     {return PLACE;}
"delete"    {return DELETE;}
"all"       {return ALL;}
"at"        {return AT;}
"if"        {return IF;}
"then"      {return THEN;}
"possible"  {return POSSIBLE;}
"while"     {return WHILE;}
"rotate"    {return ROTATE;}
"move"      {return MOVE;}

.           {yyerror("unknown character"); exit(EXIT_FAILURE);}

%%

%{
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
%}


%union {
       char* lexeme;			//identifier
       double value;			//value of an identifier of type NUM
       }

%token <value>    NUM
%token <lexeme>   DIR
%token SHOW
%token MATRIX
%token ARRAY
%token PYRAMID
%token DOME
%token GRID
%token HEIGHT
%token FITS
%token PLACE
%token DELETE
%token ALL
%token IF
%token THEN
%token ELSE
%token MOVE
%token AND
%token OR
%token EQ
%token AT
%token <lexeme> VAR

%type <lexeme> matrix
%type <lexeme> array
%type <lexeme> pyramid
%type <lexeme> dome
%type <value> expr

%left '='
%left EQ '>' '<'

%start line

%%
line  : expr '\n'                   {printf("Result: %f\n");}
      | expr line                   {}
      ;

expr  : '+' NUM NUM                 {printf("grid has size %d %d \n", $2, $3);}
      | VAR '=' types               {}
      | PLACE VAR AT coo            {}
      | MOVE VAR mopt               {}
      | HEIGHT hopt                 {}
      | DELETE dopt                 {}
      | FITS VAR coo                {}
      ;

types : matrix                      {}
      | array                       {}
      | pyramid                     {}
      | dome                        {}
      ;

matrix : MATRIX NUM NUM             {}
      ;

array : ARRAY NUM                   {}
      ;

dome  : DOME NUM NUM                {}
      ;

pyramid : PYRAMID NUM NUM           {}
      ;

mopt  : DIR NUM                     {}
      | AT coo                      {}
      ;

hopt  : coo                         {}
      | VAR                         {}
      ;

dopt  : VAR                         {}
      | ALL                         {}
      | GRID                        {}
      ;

coo   : '(' NUM ',' NUM ')'         {}
      ;

%%

#include "lex.yy.c"

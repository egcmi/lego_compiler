%{
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "src/block.h"
#include "src/grid.h"
#include "lex.yy.c"
#include "src/grid_handling.c"
#include "src/block_handling.c"
%}


%union {
       char* lexeme;			//identifier
       double value;			//value of an identifier of type NUM
       }

%token <value>    NUM
%token <lexeme>   DIR
%token <lexeme>   TYPE
%token SHOW
%token EXIT
%token SWITCH
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
%token <lexeme> GVAR

%type <lexeme> stmt


%left '='
%left EQ '>' '<'

%start line

%%
line  : stmt '\n'                   {printf("Result: %f\n");}
      | stmt line                   {}
      ;

stmt  : EXIT                              {exit(EXIT_SUCCESS);}
      | SWITCH GRID GVAR                  {printf("%d\n",switch_grid(grid_list,$3));}
      | GVAR '=' GRID '(' NUM ',' NUM ')' {printf("%d\n",add_grid(grid_list,$1,$5,$7));}
      | VAR '=' TYPE '(' NUM ',' NUM ')'  {printf("%d\n",add(default_grid,$1,$5,$7,$3,-1,-1));}
      | PLACE VAR AT '(' NUM ',' NUM ')'  {printf("%d\n",update(default_grid,0,$2,$5,$7));}
      | SHOW GVAR                         {printf("%d\n",show(grid_list,$2));}
      | MOVE mopt                         {;}
      | HEIGHT hopt                       {;}
      | DELETE dopt                       {;}
      | FITS VAR '(' NUM ',' NUM ')'      {printf("%d\n",fits(default_grid,$2,$4,$6));} 
      | IF FITS VAR AT '(' NUM ',' NUM ')' THEN PLACE              {printf("%d\n",update(default_grid,0,$3,$6,$8));}
      | IF FITS VAR AT '(' NUM ',' NUM ')' THEN MOVE               {printf("%d\n",update(default_grid,1,$3,$6,$8));}
      ;

      ;
mopt  : VAR DIR NUM                       {printf("%d\n",update_dir(default_grid,$1,$2,$3));}
      | VAR AT '(' NUM ',' NUM ')'        {printf("%d\n",update(default_grid,1,$1,$4,$6));}
      ;

hopt  : '(' NUM ',' NUM ')'         	  	{printf("%d\n",height(default_grid,$2,$4));}
      | VAR                         	  	{printf("%d\n",height_var(default_grid,$1));}
      ;

dopt  : VAR                               {printf("%d\n",delete_block(default_grid,$1));}
      | ALL                               {printf("%d\n",delete_all(default_grid));}
      | GRID GVAR                         {printf("%d\n",delete_grid(grid_list,$2));}
      ;

%%

int main (void) {
  grid_list = create_list();
  return yyparse ( );
}
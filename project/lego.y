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
       int value;			//value of an identifier of type NUM
       }

%token <value>    NUM
%token <lexeme>   DIR
%token <lexeme>   TYPE
%token <lexeme>   VAR
%token <lexeme>   GVAR
%token SHOW
%token EXIT
%token SWITCH
%token ROTATE
%token POSSIBLE
%token WHILE
%token GRID
%token HEIGHT
%token FITS
%token PLACE
%token DELETE
%token ALL
%token IF
%token THEN
%token MOVE
%token AT

%type <lexeme> stmt

%start line

%%
line  : stmt '\n'                                         {}
      | stmt line                                         {}
      | '\n'                                              {}
      ;

stmt  : EXIT                                              {exit(EXIT_SUCCESS);}
      | SWITCH GRID GVAR                                  {switch_grid(grid_list,$3);}
      | GVAR '=' GRID '(' NUM ',' NUM ')'                 {add_grid(grid_list,$1,$5,$7);}
      | VAR '=' TYPE '(' NUM ',' NUM ')'                  {add(default_grid,$1,$5,$7,$3,-1,-1);}
      | PLACE VAR AT '(' NUM ',' NUM ')'                  {update(default_grid,0,$2,$5,$7);}
      | SHOW GVAR                                         {show(grid_list,$2);}
      | MOVE mopt                                         {}
      | ROTATE VAR                                        {rotate(default_grid, $2);}
      | HEIGHT hopt                                       {}
      | DELETE dopt                                       {}
      | FITS VAR '(' NUM ',' NUM ')'                      {fits(default_grid,$2,$4,$6);} 
      | IF FITS VAR AT '(' NUM ',' NUM ')' THEN PLACE     {update(default_grid,0,$3,$6,$8);}
      | IF FITS VAR AT '(' NUM ',' NUM ')' THEN MOVE      {update(default_grid,1,$3,$6,$8);}
      | WHILE POSSIBLE ':' MOVE VAR DIR NUM               {while_move(default_grid,$5,$6,$7);}
      ;

mopt  : VAR DIR NUM                                       {update_dir(default_grid,$1,$2,$3);}
      | VAR AT '(' NUM ',' NUM ')'                        {update(default_grid,1,$1,$4,$6);}
      ;

hopt  : '(' NUM ',' NUM ')'         	  	                {printf("The height of the coordinate (%d,%d) is: %d\n", $2, $4, height(default_grid,$2,$4));}
      | VAR                         	  	                {printf("The height of the block %s is: %d\n", $1, height_var(default_grid,$1));}
      ;

dopt  : VAR                                               {delete_block(default_grid,$1);}
      | ALL                                               {delete_all(default_grid);}
      | GRID GVAR                                         {delete_grid(grid_list,$2);}
      ;

%%

int main (void) {
  grid_list = create_list();
  return yyparse ( );
}
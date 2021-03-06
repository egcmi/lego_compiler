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
  char* lexeme;
  int value;
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

%start line

%%
line  : stmt '\n'                                         {}
      | stmt line                                         {}
      ;

stmt  : EXIT                                              { exit(EXIT_SUCCESS); }
      | SWITCH GRID GVAR                                  {
                                                            if ( switch_grid(grid_list,$3) )
                                                              printf("Switched to grid %s\n", $3);
                                                          }
      | GVAR '=' GRID '(' NUM ',' NUM ')'                 { if ( add_grid(grid_list,$1,$5,$7) )
                                                              printf("Created grid %s and switched to grid %s\n", $1, $1);
                                                          }
      | VAR '=' TYPE '(' NUM ',' NUM ')'                  {
                                                            if( add(default_grid,$1,$5,$7,$3,-1,-1) )
                                                              printf("Created lego %s\n", $1);
                                                          }
      | PLACE VAR AT '(' NUM ',' NUM ')'                  {
                                                            int u = update(default_grid,0,$2,$5,$7);
                                                            switch(u){
                                                              case 1:
                                                                printf("Placed %s at (%d,%d)\n", $2, $5, $7);
                                                                break;
                                                              case -1:
                                                                printf("Error in line %d: cell out of bounds\n", yylineno);
                                                                break;
                                                              case -2:
                                                                printf("Error in line %d: cannot place on top of dome or pyramid\n", yylineno);
                                                                break;
                                                              case -3:
                                                                printf("Error in line %d: cannot place on blocks of different heights\n", yylineno);
                                                                break;
                                                            }
                                                          }
      | SHOW GVAR                                         { show(grid_list,$2); }
      | MOVE mopt                                         {}
      | ROTATE VAR                                        { rotate(default_grid, $2); }
      | HEIGHT hopt                                       {}
      | DELETE dopt                                       {}
      | FITS VAR AT '(' NUM ',' NUM ')'                   {
                                                            int f = fits(default_grid,$2,$5,$7);
                                                            switch(f){
                                                              case 1:
                                                                printf("TRUE\n");
                                                                break;
                                                              case -1:
                                                                printf("Error in line %d: cell out of bounds\n", yylineno);
                                                                break;
                                                              case -2:
                                                              case -3:
                                                              case -4:
                                                                printf("FALSE\n");
                                                                break;
                                                            }
                                                          }
      | IF FITS VAR AT '(' NUM ',' NUM ')' THEN PLACE     {
                                                            if ( update(default_grid,0,$3,$6,$8) == 1)
                                                              printf("Placed %s at (%d,%d)\n", $3, $6, $8);
                                                            else printf("Cannot place %s at (%d,%d)\n", $3, $6, $8);
                                                          }
      | IF FITS VAR AT '(' NUM ',' NUM ')' THEN MOVE      {
                                                            if ( update(default_grid,1,$3,$6,$8) == 1)
                                                              printf("Moved %s to (%d,%d)\n", $3, $6, $8);
                                                            else printf("Cannot move %s to (%d,%d)\n", $3, $6, $8);
                                                          }
      | WHILE POSSIBLE ':' MOVE VAR DIR NUM               { while_move(default_grid,$5,$6,$7); }
      ;

mopt  : VAR DIR NUM                                       {
                                                            int u = update_dir(default_grid,$1,$2,$3);
                                                            switch(u){
                                                              case 1:
                                                                printf("Moved %s %s by %d\n", $1, $2, $3);
                                                                break;
                                                              case -1:
                                                                printf("Error in line %d: cell out of bounds\n", yylineno);
                                                                break;
                                                              case -2:
                                                                printf("Error in line %d: cannot place on top of dome or pyramid\n", yylineno);
                                                                break;
                                                              case -3:
                                                                printf("Error in line %d: cannot place on blocks of different heights\n", yylineno);
                                                                break;
                                                            }
                                                          }
      | VAR AT '(' NUM ',' NUM ')'                        {
                                                            int u = update(default_grid,1,$1,$4,$6);
                                                            switch(u){
                                                              case 1:
                                                                printf("Moved %s to (%d,%d)\n", $1,$4,$6);
                                                                break;
                                                              case -1:
                                                                printf("Error in line %d: cell out of bounds\n", yylineno);
                                                                break;
                                                              case -2:
                                                                printf("Error in line %d: cannot place on top of dome or pyramid\n", yylineno);
                                                                break;
                                                              case -3:
                                                                printf("Error in line %d: cannot place on blocks of different heights\n", yylineno);
                                                                break;
                                                            }
                                                         }
      ;

hopt  : '(' NUM ',' NUM ')'                               { 
                                                            int h = height(default_grid,$2,$4);
                                                            if(h > 0)
                                                              printf("Height of cell (%d,%d): %d\n", $2, $4, h);
                                                          }
      | VAR                                               { 
                                                            int h = height_var(default_grid,$1);
                                                            if(h > 0)
                                                              printf("Height of lego %s: %d\n", $1, h);
                                                          }
      ;

dopt  : VAR                                               {
                                                            if ( delete_block(default_grid,$1) )
                                                              printf("Deleted lego %s\n", $1);
                                                          }
      | ALL                                               {
                                                            if ( delete_all(default_grid) )
                                                            printf("Deleted all legos on grid %s\n", default_grid->id);
                                                          }
      | GRID GVAR                                         {
                                                            if ( delete_grid(grid_list,$2) )
                                                            printf("Deleted grid %s", $2);
                                                          (default_grid->id==NULL)? printf("\n"):printf(" and switched to grid %s\n", default_grid->id);

                                                          }
      ;

%%

int main (void) {
  grid_list = create_grid_list();
  return yyparse ( );
}
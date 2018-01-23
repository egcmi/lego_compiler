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

%type <lexeme> stmt

%start line

%%
line	:	stmt '\n'																					{}
			|	stmt line																					{}
			;

stmt  : EXIT																							{ exit(EXIT_SUCCESS); }
			| SWITCH GRID GVAR																	{
																														if ( switch_grid(grid_list,$3) )
																															printf("Switched to grid %s\n", $3);
																													}
			| GVAR '=' GRID '(' NUM ',' NUM ')'									{ if ( add_grid(grid_list,$1,$5,$7) )
																															printf("Created grid %s and switched to grid %s\n", $1, $1);
																													}
			| VAR '=' TYPE '(' NUM ',' NUM ')'									{
																														if( add(default_grid,$1,$5,$7,$3,-1,-1) )
																															printf("Created lego %s\n", $1);
																													}
			| PLACE VAR AT '(' NUM ',' NUM ')'									{
																														if ( update(default_grid,0,$2,$5,$7) )
																															printf("Placed %s at (%d,%d)\n", $2, $5, $7);
																													}
			| SHOW GVAR																					{ show(grid_list,$2); }
			| MOVE mopt																					{}
			| ROTATE VAR																				{ rotate(default_grid, $2); }
			| HEIGHT hopt																				{}
			| DELETE dopt																				{}
			| FITS VAR AT '(' NUM ',' NUM ')'											{
																														if ( fits(default_grid,$2,$5,$7))
																															printf("TRUE\n");
																														else
																															printf("FALSE\n");
																													} 
			| IF FITS VAR AT '(' NUM ',' NUM ')' THEN PLACE			{
																														if ( update(default_grid,0,$3,$6,$8) )
																															printf("Placed %s at (%d,%d)\n", $3, $6, $8);
																														else printf("Could not place %s at (%d,%d)\n", $3, $6, $8);
																													}
			| IF FITS VAR AT '(' NUM ',' NUM ')' THEN MOVE			{
																														if ( update(default_grid,1,$3,$6,$8) )
																															printf("Moved %s to (%d,%d)\n", $3, $6, $8);
																														else printf("Could not move %s to (%d,%d)\n", $3, $6, $8);
																													}
			| WHILE POSSIBLE ':' MOVE VAR DIR NUM								{ while_move(default_grid,$5,$6,$7); }
			;

mopt  : VAR DIR NUM																				{
																														if ( update_dir(default_grid,$1,$2,$3) )
																															printf("Moved %s %s by %d", $1, $2, $3);
																													}
			| VAR AT '(' NUM ',' NUM ')'												{
																														if ( update(default_grid,1,$1,$4,$6) )
																														printf("Moved %s to (%d,%d)\n", $1,$4,$6);
																												 }
			;

hopt  : '(' NUM ',' NUM ')'																{	
																														int h = height(default_grid,$2,$4);
																														if(h > 0)
																															printf("Height of cell (%d,%d): %d\n", $2, $4, h);
																													}
			| VAR																								{	
																														int h = height_var(default_grid,$1);
																														if(h > 0)
																															printf("Height of lego %s is: %d\n", $1, h);
																													}
			;

dopt  : VAR																								{
																														if ( delete_block(default_grid,$1) )
																															printf("Deleted lego %s\n", $1);
																													}
			| ALL																								{
																														if ( delete_all(default_grid) )
																														printf("Deleted all legos on grid %s\n", default_grid->id);
																													}
			| GRID GVAR																					{
																														if ( delete_grid(grid_list,$2) )
																														printf("Deleted grid %s\n", $2);
																													}
			;

%%

int main (void) {
	grid_list = create_grid_list();
	return yyparse ( );
}
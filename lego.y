%{
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "lego.h"
node_t *head;
int add(node_t * head, char* id, int x, int y, int z, char* type, int coox, int cooy, int h);
int rm(node_t ** head, char* id);
%}


%union {
       char* lexeme;			//identifier
       double value;			//value of an identifier of type NUM
       }

%token <value>    NUM
%token <lexeme>   DIR
%token SHOW
%token EXIT
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

%type <lexeme> type
%type <value> expr

%left '='
%left EQ '>' '<'

%start line

%%
line  : expr '\n'                   {printf("Result: %f\n");}
      | expr line                   {}
      ;

expr  : EXIT                              {exit(EXIT_SUCCESS);}
      | GRID NUM NUM                      {printf("grid has size %d %d \n", $2, $3);}
      | type VAR '=' '(' NUM ',' NUM ')'  {printf("%d\n",add(head,$2,$5,$7,$1,-1,-1,-1,-1));}
      | PLACE VAR AT '(' NUM ',' NUM ')'  {}
      | MOVE VAR mopt                     {}
      | HEIGHT hopt                       {}
      | DELETE VAR                        {printf("%d",rm(head,$2));}
      | FITS VAR '(' NUM ',' NUM ')'      {}
      ;

type  : MATRIX NUM NUM              {}
      | ARRAY NUM                   {}
      | DOME                        {}
      | PYRAMID NUM NUM             {}
      ;

mopt  : DIR NUM                     {}
      | AT '(' NUM ',' NUM ')'      {}
      ;

hopt  : '(' NUM ',' NUM ')'         {}
      | VAR                         {}
      ;

dopt  : VAR                         {}
      | ALL                         {}
      | GRID                        {}
      ;

%%

#include "lex.yy.c"

int add(node_t * head, char* id, int x, int y, int z, char* type, int coox, int cooy, int h) {
    node_t * current = head;
    node_t * node = malloc(sizeof(node_t));
    node->id = id;
    node->x = x;
    node->y = y;
    node->z = z;
    node->type = type;
    node->coox = coox;
    node->cooy = cooy;
    node->h = h;

    if (head == NULL){
      head = node;
      head->next = NULL;
      return 1;
    }

    while (current->next != NULL) {
        if(current->id == id){
          printf("This variable is already used. Error in line %d", yylineno);
          return -1;
        }
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next = node;
    current->next->next = NULL;

    return 1;
}

int rm(node_t ** head, char* id) {
    node_t * current = *head;
    node_t * prev = *head;
    node_t * temp_node = NULL;

    if(current == NULL){
      printf("This variable does not exist. Thus, it cannot be deleted. Error in line %d", yylineno);
      return -1;
    }

    if(current->id == id){
      free(head);
      head = current->next;
      return 1;
    }

    while (current->next != NULL && current->next->id != id){
        current = current->next;
    }

    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);

    return 1;

}

int main (void) {
  node_t * head = NULL;
  head = malloc(sizeof(node_t));

  return yyparse ( );
}
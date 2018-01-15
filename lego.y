%{
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "lego.h"
node_t * head;
int add(char id[], int x, int y, int z, char* type, int coox, int cooy, int h);
int rm(node_t ** head, char* id);
int update(int method, char* id, int coox, int cooy);
int updateDir(char* id, int coox, int cooy);
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
      | type VAR '=' '(' NUM ',' NUM ')'  {printf("%d\n",add($2,$5,$7,$1,-1,-1,-1,-1));}
      | PLACE VAR AT '(' NUM ',' NUM ')'  {printf("%d\n",update(0,$2,$5,$7));}
      | MOVE mopt                         {;}
      | HEIGHT hopt                       {}
      | DELETE VAR                        {printf("%d",rm(head,$2));}
      | FITS VAR '(' NUM ',' NUM ')'      {}
      ;

type  : MATRIX NUM NUM              {}
      | ARRAY NUM                   {}
      | DOME                        {}
      | PYRAMID NUM NUM             {}
      ;

mopt  : VAR DIR NUM                       {printf("%d\n",updateDir($1,$2,$3));}
      | VAR AT '(' NUM ',' NUM ')'        {printf("%d\n",update(1,$1,$4,$6));}
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

int add(char id[], int x, int y, int z, char* type, int coox, int cooy, int h) {
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
      printf("head is null\n");
      head = node;
      head->next = NULL;
      return 1;
    }

    while (current->next != NULL) {
      printf("while\n");
      if(strcmp(current->id, id) == 0){
        printf("This variable is already used. Error in line %d\n", yylineno);
        return 0;
      }
      current = current->next;
    }

    if(strcmp(current->id, id) == 0){
      printf("This variable is already used. Error in line %d\n", yylineno);
      return 0;
    }

    printf("endwhile\n");
    current->next = malloc(sizeof(node_t));
    current->next = node;
    current->next->next = NULL;

    return 1;
}

int update(int method, char* id, int coox, int cooy) {
    node_t * current = head;

    if (head == NULL){
      printf("This variable does not exist. Error in line %d", yylineno);
      return 0;
    }

    while (current->next != NULL) {
      printf("itera\n");
      if((strcmp(current->id, id) == 0)){
        if(method == 0){
          if(current->coox == -1 && current->cooy == -1){
            current->coox = coox;
            current->cooy = cooy;
            printf("before coox = %d, cooy = %d\n", coox, cooy);
            return 1;
          }else{
            printf("This lego was already placed. Please use move to move it. Error in line %d\n", yylineno);
            return 0;
          }
        }else{
          if(current->coox == -1 && current->cooy == -1){
            printf("Cannot move the lego. It has to be placed before it can be moved. Error in line %d\n", yylineno);
            return 0;
          }else{
            current->coox = coox;
            current->cooy = cooy;
            printf("before coox = %d, cooy = %d\n", coox, cooy);
            return 1;
          }
        }
      }
      current = current->next;
    }

    if((strcmp(current->id, id) == 0)){
      if(method == 0){
        if(current->coox == -1 && current->cooy == -1){
          current->coox = coox;
          current->cooy = cooy;
          printf("before coox = %d, cooy = %d\n", coox, cooy);
          return 1;
        }else{
          printf("This lego was already placed. Please use move to move it. Error in line %d", yylineno);
          return 0;
        }
      }else{
        if(current->coox == -1 && current->cooy == -1){
          printf("Cannot move the lego. It has to be placed before it can be moved. Error in line %d", yylineno);
          return 0;
        }else{
          current->coox = coox;
          current->cooy = cooy;
          printf("before coox = %d, cooy = %d\n", coox, cooy);
          return 1;
        }
      }
    }

    printf("This variable does not exist. Error in line %d", yylineno);

    return 0;
}

int updateDir(char* id, int coox, int cooy){
    node_t * current = head;
    return -1;
}

int rm(node_t ** head, char* id) {
    node_t * current = *head;
    node_t * prev = *head;
    node_t * temp_node = NULL;

    if(current == NULL){
      printf("This variable does not exist. Thus, it cannot be deleted. Error in line %d", yylineno);
      return 0;
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
  return yyparse ( );
}
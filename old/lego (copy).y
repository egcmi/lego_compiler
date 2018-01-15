%{
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "lego.h"
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
      | type VAR '=' '(' NUM ',' NUM ')'  {printf("%d\n",add(list,$2,$5,$7,$1,-1,-1,-1,-1));}
      | PLACE VAR AT '(' NUM ',' NUM ')'  {printf("%d\n",update(0,$2,$5,$7));}
      | MOVE mopt                         {;}
      | HEIGHT hopt                       {}
      | DELETE VAR                        {printf("%d",rm($2));}
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

int add(l_list * list, char id[], int x, int y, int z, char* type, int coox, int cooy, int h) {
    node_t * head = list->head;
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

    printf("add1111\n");

    if (head == NULL){
      head = node;
      printf("add21\n");
      return 1;
    }

    printf("add1111\n");

    while (current->next != NULL) {
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

    current->next = malloc(sizeof(node_t));
    current->next = node;
    current->next->next = NULL;

    printf("add2\n");

    return 1;
}

int update(int method, char* id, int coox, int cooy) {
    node_t * head = list->head;
    node_t * current = head;

    if (head == NULL){
      printf("This variable does not exist. Error in line %d", yylineno);
      return 0;
    }

    while (current != NULL) {
      if((strcmp(current->id, id) == 0)){
        if(method == 0){
          if(current->coox == -1 && current->cooy == -1){
            current->coox = coox;
            current->cooy = cooy;
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
            return 1;
          }
        }
      }
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d", yylineno);

    return 0;
}

int updateDir(char* id, int coox, int cooy){
    node_t * head = list->head;
    node_t * current = head;

    return 0;

    if (head == NULL){
      printf("This variable does not exist. Error in line %d", yylineno);
      return 0;
    }

    while (current != NULL) {
      if((strcmp(current->id, id) == 0)){
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
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d", yylineno);

    return 0;
}

int rm(char* id) {

    node_t* current = list->head;
    node_t* temp = malloc(sizeof(node_t));

    if (current == NULL){
      printf("Variable list is empty: could not delete %s. Error in line %d\n", id, yylineno);
      return 0;
    }

    if (strcmp(current->id, id) == 0){
      free(current);
      current = current->next;
      printf("Deleted node id=%s\n", id);
      return 1;
    }

    // delete any element
    while(current->next != NULL){
      if (strcmp(current->next->id, id)==0 ){
        temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("Deleted node id=%s\n", id);
        return 1;
      }
      current = current->next;
    }

    printf("Variable %s does not exist: it cannot be deleted. Error in line %d\n", id, yylineno);
    return 0;
}

List * emptylist(){
  List * list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

int main (void) {
  return yyparse ( );
}
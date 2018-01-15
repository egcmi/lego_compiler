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
      | VAR '=' type '(' NUM ',' NUM ')'  {printf("%d\n",add(list,$1,$5,$7,$3,-1,-1,-1,-1));}
      | VAR '=' ARRAY NUM                 {printf("%d\n",add(list,$1,1,$4,$3,-1,-1,-1,-1));}
      | PLACE VAR AT '(' NUM ',' NUM ')'  {printf("%d\n",update(list,0,$2,$5,$7));}
      | MOVE mopt                         {;}
      | HEIGHT hopt                       {}
      | DELETE VAR                        {printf("%d\n",rm(list,$2));}
      | FITS VAR '(' NUM ',' NUM ')'      {}
      ;

type  : MATRIX                            {;}
      | DOME                              {;}
      | PYRAMID                           {;}
      ;

mopt  : VAR DIR NUM                       {printf("%d\n",updateDir(list,$1,$2,$3));}
      | VAR AT '(' NUM ',' NUM ')'        {printf("%d\n",update(list,1,$1,$4,$6));}
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
    node_t * current = list->head;
    node_t * node = malloc(sizeof(node_t));
    node->id = id;
    node->x = x;
    node->y = y;
    node->z = z;
    node->type = type;
    node->coox = coox;
    node->cooy = cooy;
    node->h = h;

    if (list->head == NULL){
      list->head = node;
      list->head->next = NULL;
      return 1;
    }

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

    return 1;
}

int update(l_list * list, int method, char* id, int coox, int cooy) {
    node_t * current = list->head;

    if (list->head == NULL){
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

int updateDir(l_list * list, char* id, int coox, int cooy){
    node_t * current = list->head;

    return 0;

    if (list->head == NULL){
      printf("There exist no variables. Error in line %d", yylineno);
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

int rm(l_list * list, char* id) {

    node_t* current = list->head;
    node_t* temp = malloc(sizeof(node_t));

    if (list->head == NULL){
      printf("Variable list is empty: could not delete %s. Error in line %d\n", id, yylineno);
      return 0;
    }

    if (strcmp(current->id, id) == 0){
      free(current);
      list->head = current->next;
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

l_list* create_list(void) {
    l_list* p;
    p = malloc(sizeof(l_list));
    p->head = NULL;
    return p;
}

int main (void) {
  list = create_list();
  return yyparse ( );
}
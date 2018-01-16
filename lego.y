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
      | VAR '=' TYPE '(' NUM ',' NUM ')'  {printf("%d\n",add(default_grid->blocks,$1,$5,$7,-1,$3,-1,-1,-1));}
      | PLACE VAR AT '(' NUM ',' NUM ')'  {printf("%d\n",update(default_grid->blocks,0,$2,$5,$7));}
      | SHOW GVAR                         {printf("%d\n",show(grid_list,$2));}
      | MOVE mopt                         {;}
      | HEIGHT hopt                       {}
      | DELETE dopt                       {;}
      | FITS VAR '(' NUM ',' NUM ')'      {printf("%d\n",fits(default_grid->blocks,$2,$4,$6));}
      ;

mopt  : VAR DIR NUM                       {printf("%d\n",update_dir(default_grid->blocks,$1,$2,$3));}
      | VAR AT '(' NUM ',' NUM ')'        {printf("%d\n",update(default_grid->blocks,1,$1,$4,$6));}
      ;

hopt  : '(' NUM ',' NUM ')'         	  {}
      | VAR                         	  {}
      ;

dopt  : VAR                               {printf("%d\n",rm(default_grid->blocks,$1));}
      | ALL                               {printf("%d\n",rm_all(default_grid->blocks));}
      | GRID GVAR                         {printf("%d\n",rm_grid(grid_list,$2));}
      ;

%%

#include "lex.yy.c"


l_list* create_list(void) {
    l_list* p;
    p = malloc(sizeof(l_list));
    p->head = NULL;
    return p;
}

g_list* create_grid_list(void) {
    g_list* p;
    p = malloc(sizeof(g_list));
    p->head = NULL;
    return p;
}
grid_t* create_grid_t(void) {
  grid_t* p;
    p = malloc(sizeof(grid_t));
    return p;
}

int free_matrix(char *** matrix, int row, int col){
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            free(matrix[i][j]);
        }
    }
    free(matrix);
}


int add_grid(g_list * list, char id[], int row, int col) {
    grid_t * current = list->head;
    grid_t * node = malloc(sizeof(grid_t));
    node->id = id;
    node->row = row;
    node->col = col;
    node->blocks = create_list();
    default_grid=create_grid_t();
    node->matrix = (char * * *) malloc(row * sizeof(char * *));
    for(int i=0; i < row; i++){
        node->matrix[i] = (char * *) malloc(col * sizeof(char *));
        for(int j=0; j < col; j++){
            node->matrix[i][j] = "0";
        }
    }

    if (list->head == NULL){
      list->head = node;
      list->head->next = NULL;
      default_grid = list->head;
      default_grid->id=list->head->id;
      return 1;
    }

    while (current->next != NULL) {
      if(strcmp(current->id, id) == 0){
        printf("This grid is already used. Error in line %d\n", yylineno);
        free(node->matrix);
        free(node);
        return 0;
      }
      current = current->next;
    }

    if(strcmp(current->id, id) == 0){
      printf("This grid is already used. Error in line %d\n", yylineno);
      free(node->matrix);
      free(node);
      return 0;
    }

    current->next = malloc(sizeof(grid_t));
    current->next = node;
    current->next->next = NULL;

    default_grid = current->next;


    return 1;
}

int switch_grid(g_list * list, char* id) {

    if (list->head == NULL){
      printf("Grid list is empty: could not switch to any grid. Error in line %d\n", yylineno);
      return 0;
    }

    if(strcmp(id, "-1") == 0){
      id = list->head->id;
    } 


    grid_t* current = list->head;
    
    while(current != NULL){
      if (strcmp(current->id, id)==0 ){
        default_grid = current;
        printf("Switched to grid id=%s\n", id);
        return 1;
      }
      current = current->next;
    }

    printf("Grid %s does not exist: you cannot switch to it. Error in line %d\n", id, yylineno);
    return 0;
}


int rm_grid(g_list * list, char* id) {

    if (list->head == NULL){
      printf("Grid list is empty: could not delete %s. Error in line %d\n", id, yylineno);
      return 0;
    }

    grid_t* current = list->head;
    grid_t* temp = malloc(sizeof(grid_t));
    char* def_id = default_grid->id;

    if (strcmp(current->id, id) == 0){
      rm_all(current->blocks);
      free(current);
      list->head = current->next;
      printf("Deleted grid id=%s\n", id);
      if (strcmp(def_id, id) == 0){
        switch_grid(list, "-1");
      }
      return 1;
    }

    // delete any element
    while(current->next != NULL){
      if (strcmp(current->next->id, id)==0 ){
        rm_all(current->blocks);
        temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("Deleted grid id=%s\n", id);
        if (strcmp(def_id, id) == 0){
          switch_grid(list, list->head->id);
        }
        return 1;
      }
      current = current->next;
    }

    printf("Grid %s does not exist: it cannot be deleted. Error in line %d\n", id, yylineno);
    return 0;
}

int show(g_list * list, char* id){

    grid_t* current = list->head;

    if (list->head == NULL){
      printf("Grid list is empty: could not print %s. Error in line %d\n", id, yylineno);
      return 0;
    }

    while (current != NULL) {
      if(strcmp(current->id, id) == 0){
        int maxRow = current->row;
        int maxCol = current->col;
        for (int row=0; row<maxRow; row++){
          for(int col=0; col<maxCol; col++){
            printf("%s     ", current->matrix[row][col]);
          }
          printf("\n");
        }
        return 1;
      }
      current = current->next;
    }

}

int fits(l_list * list, char id[], int x, int y){
		node_t * current = list->head;
		int gridx = default_grid->row;
		int gridy = default_grid->col;
		grid_t * def = default_grid;

    if (list->head == NULL){
      printf("Grid list is empty: could not find %s. Error in line %d\n", yylineno);
      return 0;
    }

    if (x > gridx || y > gridy){
			printf("The coordinates are too big for the grid. Error in line %d\n", yylineno);
		  	return 0;
    }

    while (current != NULL) {
      if(strcmp(current->id, id) == 0){
      	int checkx = (current->x)-gridx+x;
      	int checky = (current->y)-gridy+y;
      	if(checkx > 0 || checky > 0){
      		printf("Cannot insert this variable at this point. There is not enough space. Check the grid size and the coordinates. Error in line %d\n", yylineno);
      		return 0;
      	}

      	char * var = def->matrix[x][y];
      	if(strstr(var, "o") != NULL || strstr(var,"x") != NULL){
		      printf("Cannot place the variable on the top of a dome or pyramid block. Error in line %d\n", yylineno);
		      return 0;
				}
				char * currVar;

				for(int i = x; i < x+current->x; i++){
		      for(int j = y; j < y+current->y; j++){
            currVar = def->matrix[i][j];
            if(strcmp(var,currVar) != 0){
                  printf("Cannot place the variable on blocks with different heights. Error in line %d\n", yylineno);
                  return 0;
            }
		      }
				}
      	printf("The block fits in the desidered coordinates %d, %d.\n", x, y);
      	return 1;
      }
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d\n", yylineno);
    return 0;
}

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
      printf("Added item %s to grid %s\n", list->head->id, default_grid->id);
      return 1;
    }

    while (current->next != NULL) {
      if(strcmp(current->id, id) == 0){
        printf("This variable is already used. Error in line %d\n", yylineno);
        free(node);
        return 0;
      }
      current = current->next;
    }

    if(strcmp(current->id, id) == 0){
      printf("This variable is already used. Error in line %d\n", yylineno);
      free(node);
      return 0;
    }

    current->next = malloc(sizeof(node_t));
    current->next = node;
    current->next->next = NULL;

    printf("Added item %s to grid %s\n", current->next->id, default_grid->id);

    return 1;
}


int add_in_matrix(grid_t * grid, char* type, int x, int y, int coox, int cooy){
		char * t = "";
		if(strcmp(type, "dome") == 0){
			t = "o";
		}else if (strcmp(type, "pyramid") == 0){
			t = "x";
		}

		for(int i = coox; i < x+coox; i++){
	    for(int j = cooy; j < y+cooy; j++){
	    	int curr = atoi(grid->matrix[i][j])+1;
	    	char * res = malloc(sizeof(char)*4);
	    	snprintf(res, sizeof(res), "%d", curr);
	    	strcat(res, t);
	    	grid->matrix[i][j] = res;
	    }
		}

}

int delete_in_matrix(grid_t * grid, char* type, int x, int y, int coox, int cooy){
		char * t = "";
		if(strcmp(type, "dome") == 0){
			t = "o";
		}else if (strcmp(type, "pyramid") == 0){
			t = "x";
		}

		for(int i = coox; i < x+coox; i++){
	    for(int j = cooy; j < y+cooy; j++){
	    	int curr = atoi(grid->matrix[i][j])+1;
	    	char * res = malloc(sizeof(char)*4);
	    	snprintf(res, sizeof(res), "%d", curr);
	    	strcat(res, t);
	    	grid->matrix[i][j] = res;
	    }
		}
}

int update(l_list * list, int method, char* id, int coox, int cooy) {
    node_t * current = list->head;

    if (list->head == NULL){
      printf("This variable does not exist. Error in line %d\n", yylineno);
      return 0;
    }

    while (current != NULL) {
      if((strcmp(current->id, id) == 0)){
        if(method == 0){
          if(current->coox == -1 && current->cooy == -1){
          	if(fits(list, current->id, coox, cooy)){
          		current->coox = coox;
            	current->cooy = cooy;
            	add_in_matrix(default_grid, current->type, current->x, current->y, coox, cooy);
            	return 1;
          	}else{
          		return 0;
          	}
          }else{
            printf("This lego was already placed. Please use move to move it. Error in line %d\n", yylineno);
            return 0;
          }
        }else{
          if(current->coox != -1 && current->cooy != -1 && fits(list, current->id, coox, cooy)){
          	if(fits(list, current->id, coox, cooy)){
	            current->coox = coox;
	            current->cooy = cooy;
	            add_in_matrix(default_grid, current->type, current->x, current->y, coox, cooy);
	            delete_in_matrix(default_grid, current->type, current->x, current->y, coox, cooy);
	            return 1;
          	}else{
          		return 0;
          	}
          }else{
          	printf("Cannot move the lego. It has to be placed before it can be moved. Error in line %d\n", yylineno);
            return 0;
          }
        }
      }
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d\n", yylineno);

    return 0;
}

int update_dir(l_list * list, char* id, int coox, int cooy){
    node_t * current = list->head;

    return 0;

    if (list->head == NULL){
      printf("There exist no variables. Error in line %d\n", yylineno);
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

    printf("This variable does not exist. Error in line %d\n", yylineno);

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

int rm_all(l_list * list){
    node_t* current = list->head;
    node_t* temp = malloc(sizeof(node_t));

    if (list->head == NULL){
      printf("Variable list is empty: could not delete any element. Error in line %d\n", yylineno);
      return 0;
    }

    // delete any element
    while(current != NULL){
      printf("deleted id=%s\n",current->id );
      temp=current->next;
      free(current);
      current=temp;
      
    }

    //printf("Variable does not exist: it cannot be deleted. Error in line %d\n", yylineno);
    return 1;
}


int main (void) {
  grid_list = create_list();
  return yyparse ( );
}
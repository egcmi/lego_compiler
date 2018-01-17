/*

*/
l_list * create_list(void) {
    l_list* p;
    p = malloc(sizeof(l_list));
    p->head = NULL;
    return p;
}

/*

*/
int add(grid_t * grid, char id[], int x, int y, char* type, int coox, int cooy) {
	  if (x == 0 || y == 0){
    	printf("You cannot create a variable with size 0. Error in line %d\n", yylineno);
      return 0;
    }
    l_list * list = grid->blocks;
    node_t * current = list->head;
    node_t * node = malloc(sizeof(node_t));
    node->id = id;
    node->x = x;
    node->y = y;
    node->type = type;
    node->coox = coox;
    node->cooy = cooy;

    if (list->head == NULL){
      list->head = node;
      list->head->next = NULL;
      printf("Added item %s to grid %s\n", list->head->id, grid->id);
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

    printf("Added item %s to grid %s\n", current->next->id, grid->id);

    return 1;
}

/*

*/
int fits(grid_t * grid, char id[], int x, int y){
    l_list * list = grid->blocks;
    node_t * current = list->head;
    int gridx = grid->row;
    int gridy = grid->col;

    if (list->head == NULL){
      printf("Grid list is empty: could not find %s. Error in line %d\n", yylineno);
      return 0;
    }

    if (x > gridx || y > gridy || x < 0 || y < 0){
      printf("The coordinates are out of the grid. Error in line %d\n", yylineno);
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

        char * var = grid->matrix[x][y];
        if(strstr(var, "o") != NULL || strstr(var,"x") != NULL){
          printf("Cannot place the variable on the top of a dome or pyramid block. Error in line %d\n", yylineno);
          return 0;
        }

        char * currVar;

        for(int i = x; i < x+current->x; i++){
          for(int j = y; j < y+current->y; j++){
            currVar = grid->matrix[i][j];
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


/*

*/
int on_top(grid_t * grid, node_t * node){
    int coox = node->coox;
    int cooy = node->cooy;
    
    if (node->h == height(grid, coox, cooy)){
      return 1;
    }

    return 0;
}

/*

*/
int height(grid_t * grid, int x, int y){

		if(x >= grid->row || y >= grid-> row){
			printf("Cannot calculate the height of a cell not in the grid boundary. Error in line %d\n", yylineno);
      return 0;
		}

    char * var = grid->matrix[x][y];
		int h = atoi(var);
		return h;
}

/*

*/
int height_var(grid_t * grid, char* id){

    l_list * list = grid->blocks;
    node_t * current = list->head;
    int h = 0;

    if (list->head == NULL){
      printf("There exist no variables. Error in line %d\n", yylineno);
      return 0;
    }

    while (current != NULL) {
      if((strcmp(current->id, id) == 0)){
        if(current->coox == -1 && current->cooy == -1){
          printf("Cannot check height of lego. It has to be placed before the height can be retrieved. Error in line %d\n", yylineno);
          return 0;
        }else{
          h = current->h;
          return h;
        }
      }
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d\n", yylineno);

    return 0;
}

/*

*/
int add_in_matrix(grid_t * grid, node_t * node, int coox, int cooy){
		int x = node->x;
		int y = node->y;
		char * type = node->type;
		int cell_height = height(grid, coox,cooy);
		node->h = cell_height + 1;

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

/*

*/
int delete_in_matrix(grid_t * grid, node_t * node){

		int x = node->x;
		int y = node->y;
		int coox = node->coox;
		int cooy = node->cooy;

		for(int i = coox; i < x+coox; i++){
	    for(int j = cooy; j < y+cooy; j++){
	    	int curr = atoi(grid->matrix[i][j])-1;
	    	char * res = malloc(sizeof(char)*4);
	    	snprintf(res, sizeof(res), "%d", curr);
	    	grid->matrix[i][j] = res;
	    }
		}
}

/*

*/
int update(grid_t * grid, int method, char* id, int coox, int cooy) {
    l_list * list = grid->blocks;
    node_t * current = list->head;

    if (list->head == NULL){
      printf("This variable does not exist. Error in line %d\n", yylineno);
      return 0;
    }

    while (current != NULL) {
      if((strcmp(current->id, id) == 0)){
        if(method == 0){
          if(current->coox == -1 && current->cooy == -1){
          	if(fits(grid, current->id, coox, cooy)){
          		current->coox = coox;
            	current->cooy = cooy;
            	add_in_matrix(grid, current, coox, cooy);
            	return 1;
          	}else{
          		return 0;
          	}
          }else{
            printf("This lego was already placed. Please use move to move it. Error in line %d\n", yylineno);
            return 0;
          }
        }else{
          if(current->coox != -1 && current->cooy != -1){
						int past_x = current->coox;
						int past_y = current->cooy;
            if (on_top(grid, current)){
              delete_in_matrix(grid, current);
            }else{
              printf("Variable %s is not on top. Thus, it cannot be deleted. Error in line %d\n", id, yylineno);
              return 0;
            }
          	if(fits(grid, current->id, coox, cooy)){
	            current->coox = coox;
	            current->cooy = cooy;
	            add_in_matrix(grid, current, coox, cooy);
	            return 1;
          	}else{
          		add_in_matrix(grid, current, past_x, past_y);
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

/*

*/
int update_dir(grid_t * grid, char* id, char* dir, int num){
    l_list * list = grid->blocks;
    node_t * current = list->head;

    if (list->head == NULL){
      printf("There exist no variables. Error in line %d\n", yylineno);
      return 0;
    }
    int dir_num;
    if(strcmp(dir, "left") == 0){
      dir_num = 1;
    }

    if(strcmp(dir, "right") == 0){
      dir_num = 2;
    }

    if(strcmp(dir, "up") == 0){
      dir_num = 3;
    }

    if(strcmp(dir, "down") == 0){
      dir_num = 4;
    }


    while (current != NULL) {
      if((strcmp(current->id, id) == 0)){
        if(current->coox == -1 && current->cooy == -1){
          printf("Cannot move the lego. It has to be placed before it can be moved. Error in line %d\n", yylineno);
          return 0;
        }else{
          int tempx;
          int tempy;
          switch (dir_num){
            case 1:
              tempx = current->coox;
              tempy = current->cooy-num;
              break;
            case 2:
              tempx = current->coox;
              tempy = current->cooy+num;
              break;
            case 3:
              tempx = current->coox-num;
              tempy = current->cooy;
              break;
            case 4:
              tempx = current->coox+num;
              tempy = current->cooy;
              break;
          }
          update(grid, 1, id, tempx, tempy);
          //printf("before coox = %d, cooy = %d\n", coox, cooy);
          return 1;
        }
      }
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d\n", yylineno);

    return 0;
}

/*

*/
int delete_block(grid_t * grid, char* id) {
    l_list * list = grid->blocks;
    node_t* current = list->head;
    node_t* temp = malloc(sizeof(node_t));

    if (list->head == NULL){
      printf("Variable list is empty: could not delete %s. Error in line %d\n", id, yylineno);
      return 0;
    }

    if (strcmp(current->id, id) == 0){
      if (on_top(grid, current)){
        free(current);
        list->head = current->next;
        delete_in_matrix(grid, current);
        printf("Deleted node id=%s\n", id);
        return 1;
      }else{
        printf("Variable %s is not on top. Thus, it cannot be deleted. Error in line %d\n", id, yylineno);
        return 0;
      }
    }

    // delete any element
    while(current->next != NULL){
      if (strcmp(current->next->id, id)==0 ){
        if (on_top(grid, current->next)){
          temp = current->next;
          current->next = temp->next;
          delete_in_matrix(grid, temp);
          free(temp);
          printf("Deleted node id=%s\n", id);
          return 1;
        }else{
          printf("Variable %s is not on top. Thus, it cannot be deleted. Error in line %d\n", id, yylineno);
          return 0;
        }

        return 1;
      }
      current = current->next;
    }

    printf("Variable %s does not exist: it cannot be deleted. Error in line %d\n", id, yylineno);
    return 0;
}

/*

*/
int delete_all(grid_t * grid){
    l_list * list = grid->blocks;
    node_t* current = list->head;
    node_t* temp = malloc(sizeof(node_t));

    if (list->head == NULL){
      printf("Variable list is empty: could not delete any element. Error in line %d\n", yylineno);
      return 0;
    }

    // delete any element
    while(current != NULL){
    	delete_in_matrix(grid, current);
      printf("deleted id=%s\n",current->id );
      temp=current->next;
      free(current);
      current=temp;
      
    }

    //printf("Variable does not exist: it cannot be deleted. Error in line %d\n", yylineno);
    return 1;
}


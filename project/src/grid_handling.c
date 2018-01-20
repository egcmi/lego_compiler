/*
creates an empty list of bricks
*/
g_list* create_grid_list(void) {
	g_list* p;
	p = malloc(sizeof(g_list));
	p->head = NULL;
	return p;
}

/*
creates empty grid
*/
grid_t* create_grid_t(void) {
	grid_t* p;
	p = malloc(sizeof(grid_t));
	return p;
}

/*
frees memory allocated for matrix
*/
int free_matrix(char *** matrix, int row, int col){
	for(int i=0; i < row; i++){
		for(int j=0; j < col; j++){
			free(matrix[i][j]);
		}
	}
	free(matrix);
}

/*
creates grid with desired characteristics:
	- id:   unique name
	- row:  number of rows
	- col:  number of columns
all the values in the matrix are initialised to 0
*/
int add_grid(g_list * list, char id[], int row, int col) {
	if (row <= 0 || col <= 0){
		printf("Error in line %d: size too small\n", yylineno);
		return 0;
	}
	grid_t * current = list->head;
	grid_t * grid = malloc(sizeof(grid_t));
	grid->id = id;
	grid->row = row;
	grid->col = col;
	grid->bricks = create_brick_list();
	default_grid=create_grid_t();
	grid->matrix = (char * * *) malloc(row * sizeof(char * *));
	for(int i=0; i < row; i++){
		grid->matrix[i] = (char * *) malloc(col * sizeof(char *));
		for(int j=0; j < col; j++){
			grid->matrix[i][j] = "0";
		}
	}

	if (list->head == NULL){
		list->head = grid;
		list->head->next = NULL;
		default_grid = list->head;
		default_grid->id=list->head->id;
		return 1;
	}

	while (current->next != NULL) {
		if(strcmp(current->id, id) == 0){
			printf("Error in line %d: %s already defined\n", yylineno, id);
			free(grid->matrix);
			free(grid);
			return 0;
		}
		current = current->next;
	}

	if(strcmp(current->id, id) == 0){
			printf("Error in line %d: %s already defined\n", yylineno, id);
		free(grid->matrix);
		free(grid);
		return 0;
	}

	current->next = malloc(sizeof(grid_t));
	current->next = grid;
	current->next->next = NULL;
	default_grid = current->next;
	return 1;
}

/*
searches for a grid with the provided id in the grid list (g_list), then sets it as default grid
*/
int switch_grid(g_list * list, char* id) {
	if (list->head == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	if(strcmp(id, "-1") == 0){
		id = list->head->id;
	} 

	grid_t* current = list->head;

	while(current != NULL){
		if (strcmp(current->id, id)==0 ){
			default_grid = current;
			return 1;
		}
		current = current->next;
	}

		printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

/*
searches for a grid with the provided id in the grid list (g_list), deletes it, then switches to another grid, if present
*/
int delete_grid(g_list * list, char* id) {
	if (list->head == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

  grid_t* current = list->head;
  grid_t* temp = malloc(sizeof(grid_t));
  char* def_id = default_grid->id;

  if (strcmp(current->id, id) == 0){
    delete_all(current);
    free(current);
    list->head = current->next;

		if (strcmp(def_id, id) == 0){
			switch_grid(list, "-1");
		}
		return 1;
	}

	while(current->next != NULL){
		if (strcmp(current->next->id, id)==0 ){
			delete_all(current);
			temp = current->next;
			current->next = temp->next;
			free(temp);
			if (strcmp(def_id, id) == 0){
				switch_grid(list, list->head->id);
			}
			return 1;
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

/*
prints a graphical representation of the grid. for each cell, a number represents the height/number of bricks on that cell
in addition to this, an additional optional character 'o' or 'x' represents respectively a dome or pyramid block
*/
int show(g_list * list, char* id){

	grid_t* current = list->head;

	if (list->head == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	while (current != NULL) {
		if(strcmp(current->id, id) == 0){
			int maxRow = current->row;
			int maxCol = current->col;
			
			printf("\n%-6s", id);
			for(int col=0; col<maxCol; col++){
				printf("%-4d", col);
			}
			printf("\n\n");

			for (int row=0; row<maxRow; row++){
				printf("%-6d", row);
				for(int col=0; col<maxCol; col++){
					printf("%-4s", current->matrix[row][col]);
				}
				printf("\n\n");
			}
			return 1;
		}
		current = current->next;
	}

}
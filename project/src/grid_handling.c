/*
creates an empty list of grids
*/
grid_list* create_grid_list(void) {
	grid_list* p = malloc(sizeof(grid_list));
	p->head = NULL;
	p->tail = NULL;
	p->length = 0;
	printf("Initiialised empty list of grids\n");
	return p;
}

void delete_grid_list(grid_list* list){
	if (is_grid_list_empty(list)){
		printf("Deleted empty list\n");
		free(list);
		return;
	}

	grid_t* b = list->head;
	while(b != NULL){
		printf("Deleted grid %s\n", b->id);
		list->head = list->head->next;
		free(b);
		b = list->head;
	}
	printf("Deleted entire list\n");
	free(list);
	return;
}

grid_t* create_grid(char* id, int row, int col){
	if (row <= 0 || col <= 0){
		printf("Size too small\n");
		return NULL;
	}

	grid_t* p = malloc(sizeof(grid_t));
	p->id = id;
	p->row = row;
	p->col = col;
	p->prev = NULL;
	p->next = NULL;
	printf("Initialised grid %s\n", id);
	return p;
}

int is_grid_list_empty(grid_list* list) {
	printf("List length is %d\n", list->length);
   return (list->head == NULL);
}

int insert_grid_tail(grid_list* list, grid_t* grid){
	if (is_grid_list_empty(list)){
		list->head = grid;
	} else {
		list->tail->next = grid;
		grid->prev = list->tail;
	}

	list->tail = grid;
	list->length++;
	printf("Inserted grid %s, list length: %d\n", grid->id, list->length);
	return 1;
}

grid_t* find_grid(grid_list* list, char* id){
	grid_t* b = list->head;
	while (b != NULL){
		if (strcmp(b->id, id) == 0){
			printf("grid %s found\n", id);
			return b;
		}
		b = b->next;
	}
	printf("grid %s not found\n", id);
	return NULL;
}


// segfault if grid is not in list
int remove_grid(grid_list* list, grid_t* grid){
	if (grid == NULL || list->head == NULL){
		return 0;
	}

	if (grid->prev == NULL){
		list->head = grid->next;
	} else {
		grid->prev->next = grid->next;
	}

	if (grid->next == NULL){
		list->tail = grid->prev;
	} else {
		grid->next->prev = grid->prev;
	}

	printf("Deleted grid %s, list length: %d\n", grid->id, list->length-1);
	free(grid);
	list->length--;
	return 1;
}

// up to here ------------------------------------------------------------------------------

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
int add_grid(grid_list* list, char id[], int row, int col) {
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
searches for a grid with the provided id in the grid list (grid_list), then sets it as default grid
*/
int switch_grid(grid_list* list, char* id) {
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
searches for a grid with the provided id in the grid list (grid_list), deletes it, then switches to another grid, if present
*/
int delete_grid(grid_list* list, char* id) {
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
int show(grid_list* list, char* id){

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
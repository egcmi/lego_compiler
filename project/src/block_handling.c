/*
creates an empty list of bricks
*/
brick_list* create_brick_list(void) {
	brick_list* p = malloc(sizeof(brick_list));
	p->head = NULL;
	p->tail = NULL;
	p->length = 0;
	printf("Initiialised empty list of bricks\n");
	return p;
}

void delete_brick_list(brick_list* list){
	if (is_brick_list_empty(list)){
		printf("Deleted empty list\n");
		free(list);
		return;
	}

	brick_t* b = list->head;
	while(b != NULL){
		printf("Deleted brick %s\n", b->id);
		list->head = list->head->next;
		free(b);
		b = list->head;
	}
	printf("Deleted entire list\n");
	free(list);
	return;
}

brick_t* create_brick(char* id, int row, int col, char* type){
	if (row <= 0 || col <= 0){
		printf("Size too small\n");
		return NULL;
	}

	brick_t* p = malloc(sizeof(brick_t));
	p->id = id;
	p->row = row;
	p->col = col;
	p->type = type;
	p->coorow = -1;
	p->coocol = -1;
	p->prev = NULL;
	p->next = NULL;
	printf("Initialised brick %s of type %s\n", id, type);
	return p;
}

int is_brick_list_empty(brick_list* list) {
	printf("List length is %d\n", list->length);
   return (list->head == NULL);
}

int insert_brick_tail(brick_list* list, brick_t* brick){
	if (is_brick_list_empty(list)){
		list->head = brick;
	} else {
		list->tail->next = brick;
		brick->prev = list->tail;
	}

	list->tail = brick;
	list->length++;
	printf("Inserted brick %s, list length: %d\n", brick->id, list->length);
	return 1;
}

brick_t* find_brick(brick_list* list, char* id){
	brick_t* b = list->head;
	while (b != NULL){
		if (strcmp(b->id, id) == 0){
			printf("Brick %s found\n", id);
			return b;
		}
		b = b->next;
	}
	printf("Brick %s not found\n", id);
	return NULL;
}


// segfault if brick is not in list
int remove_brick(brick_list* list, brick_t* brick){
	if (brick == NULL || list->head == NULL){
		return 0;
	}

	if (brick->prev == NULL){
		list->head = brick->next;
	} else {
		brick->prev->next = brick->next;
	}

	if (brick->next == NULL){
		list->tail = brick->prev;
	} else {
		brick->next->prev = brick->prev;
	}

	printf("Deleted brick %s, list length: %d\n", brick->id, list->length-1);
	free(brick);
	list->length--;
	return 1;
}

/*
creates brick with desired caracteristics. returns error if:
	- no grid exists
	- any of of the sides (row,col) is 0
	- another brick with the same id exists
*/
int add(grid_t * grid, char id[], int row, int col, char* type, int coorow, int coocol) {
	if (default_grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	if (row <= 0 || col <= 0){
		printf("Error in line %d: size too small\n", yylineno);
		return 0;
	}

	brick_list * list = grid->bricks;
	brick_t * current = list->head;
	brick_t * brick = malloc(sizeof(brick_t));
	brick->id = id;
	brick->row = row;
	brick->col = col;
	brick->type = type;
	brick->coorow = coorow;
	brick->coocol = coocol;

	if (list->head == NULL){
		list->head = brick;
		list->head->next = NULL;
		return 1;
	}

	while (current->next != NULL) {
		if(strcmp(current->id, id) == 0){
			printf("Error in line %d: %s already defined\n", yylineno, id);
			free(brick);
			return 0;
		}
		current = current->next;
	}

	if(strcmp(current->id, id) == 0){
			printf("Error in line %d: %s already defined\n", yylineno, id);
		free(brick);
		return 0;
	}

	current->next = malloc(sizeof(brick_t));
	current->next = brick;
	current->next->next = NULL;
	return 1;
}

/*
checks if the block identified by id fits at the given coordinates (row,y)
returns 1 if it fits, 0 if it doesn't
returns 0 (false) if:
	- there is not enough room (brick would be "hanging" out of the grid)
	- the surface where the brick needs to be placed is uneven (bricks of different heights, domes, pyramid)
	returns error if:
	- no bricks exists
	- coordinates (row,col) are less than 0 or bigger than the grid
*/
int fits(grid_t * grid, char id[], int row, int col){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	brick_list * list = grid->bricks;
	brick_t * current = list->head;
	int gridrow = grid->row;
	int gridcol = grid->col;

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	if (row > gridrow || col > gridcol || row < 0 || col < 0){
		printf("Error in line %d: cell out of bounds\n", yylineno);
		return 0;
	}

	while (current != NULL) {
		if(strcmp(current->id, id) == 0){
			int checkrow = (current->row)-gridrow+row;
			int checkcol = (current->col)-gridcol+col;
			if(checkrow > 0 || checkcol > 0){
				return 0;
			}

			char * var = grid->matrix[row][col];
			if(strstr(var, "o") != NULL || strstr(var,"x") != NULL){
				//printf("Cannot place brick on top of dome or pyramid\n");
				return 0;
			}

			char * currVar;
			for(int i = row; i < row+current->row; i++){
				for(int j = col; j < col+current->col; j++){
					currVar = grid->matrix[i][j];
					if(strcmp(var,currVar) != 0){
						return 0;
					}
				}
			}
			return 1;
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

/*
checks if brick (brick) is on top of the grid. returns 1 when true, 0 otherwise.
*/
int on_top(grid_t * grid, brick_t * brick){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	int coorow = brick->coorow;
	int coocol = brick->coocol;

	if (brick->h == height(grid, coorow, coocol)){
		return 1;
	}

	return 0;
}

/*
returns height of the cell (row,col) on which it is invoked, -1 if coordinates less than 0 or bigger than the size of the grid
*/
int height(grid_t * grid, int row, int col){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	if(row >= grid->row || col >= grid->col || row<0 || col<0){
		printf("Error in line %d: cell out of bounds\n", yylineno);
		return -1;
	}

	char * var = grid->matrix[row][col];
	int h = atoi(var);
	return h;
}

/*
returns height of the brick placed on the grid and identified by the provided id.
returns error if the brick is not placed or if it does not exist
*/
int height_var(grid_t * grid, char* id){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	brick_list * list = grid->bricks;
	brick_t * current = list->head;
	int h = 0;

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	while (current != NULL) {
		if((strcmp(current->id, id) == 0)){
			if(current->coorow == -1 && current->coocol == -1){
			printf("Error in line %d: %s not placed\n", yylineno, id);
				return 0;
			}else{
				h = current->h;
				return h;
			}
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

/*
increases the height/number of bricks of the cell in the grid defined by (coorow, coocool) by one when a new block is placed/moved.
if the (topmost) block (brick_t) added is a pyramid or dome, concatenates an 'x' or 'o' to the number to represent it
*/
void add_in_matrix(grid_t * grid, brick_t * brick, int coorow, int coocol){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return;
	}

	int row = brick->row;
	int col = brick->col;
	char * type = brick->type;
	int cell_height = height(grid, coorow,coocol);
	brick->h = cell_height + 1;

	char * t = "";
	if(strcmp(type, "dome") == 0){
		t = "o";
	}else if (strcmp(type, "pyramid") == 0){
		t = "x";
	}

	for(int i = coorow; i < row+coorow; i++){
		for(int j = coocol; j < col+coocol; j++){
			int curr = atoi(grid->matrix[i][j])+1;
			char * res = malloc(sizeof(char)*4);
			snprintf(res, sizeof(res), "%d", curr);
			strcat(res, t);
			grid->matrix[i][j] = res;
		}
	}

}

/*
decreases the height/number of bricks of the cell in the grid defined by (coorow, coocool) by one when a new block is deleted/moved.
if the (topmost) block (brick_t) removed is a pyramid or dome, the 'x' or 'o' that represent this condition are removed
*/
int delete_in_matrix(grid_t * grid, brick_t * brick){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	int row = brick->row;
	int col = brick->col;
	int coorow = brick->coorow;
	int coocol = brick->coocol;

	if (coorow < 0 || coocol < 0){
		return 0;
	}

	for(int i = coorow; i < row+coorow; i++){
		for(int j = coocol; j < col+coocol; j++){
			int curr = atoi(grid->matrix[i][j])-1;
			char * res = malloc(sizeof(char)*4);
			snprintf(res, sizeof(res), "%d", curr);
			grid->matrix[i][j] = res;
		}
	}

	return 1;
}

/*
used for move at coordinates (coorow, coocol). updates coordinates inside block and matrix inside grid
*/
int update(grid_t * grid, int method, char* id, int coorow, int coocol) {
	if(grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}
	brick_list * list = grid->bricks;
	brick_t * current = list->head;

	if (list->head == NULL){
	printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	while (current != NULL) {
		if((strcmp(current->id, id) == 0)){
			if(method == 0){
				if(current->coorow == -1 && current->coocol == -1){
					if(fits(grid, current->id, coorow, coocol)){
						current->coorow = coorow;
						current->coocol = coocol;
						add_in_matrix(grid, current, coorow, coocol);
						return 1;
					}else{
						return 0;
					}
				}else{
					printf("Error in line %d: %s already placed\n", yylineno, id);
					return 0;
				}
			}else{
				if(current->coorow != -1 && current->coocol != -1){
					int past_row = current->coorow;
					int past_col = current->coocol;
					if (on_top(grid, current)){
						delete_in_matrix(grid, current);
					}else{
						printf("Error in line %d: %s not on top\n", yylineno, id);
						return 0;
					}
					if(fits(grid, current->id, coorow, coocol)){
						current->coorow = coorow;
						current->coocol = coocol;
						add_in_matrix(grid, current, coorow, coocol);
						return 1;
					}else{
						add_in_matrix(grid, current, past_row, past_col);
						return 0;
					}
				}else{
					printf("Error in line %d: %s not placed\n", yylineno, id);
					return 0;
				}
			}
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

/*
rotates block identified by the provided id by swapping its width and depth
then places it on the grid with the upper left corner in the same cell as before
returns error if:
	- brick is not found
	- brick is not on top
	- brick is not placed
*/
int rotate(grid_t * grid, char* id) {
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}
	brick_list * list = grid->bricks;
	brick_t * current = list->head;

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	while (current != NULL) {
		if(current->coorow != -1 && current->coocol != -1){
			if (on_top(grid, current)){
				delete_in_matrix(grid, current);
			}else{
				printf("Error in line %d: %s not on top\n", yylineno, id);
				return 0;
			}
			int temp = current->row;
			current->row = current->col;
			current->col = temp;
			if(fits(grid, current->id, current->coorow, current->coocol)){
				add_in_matrix(grid, current, current->coorow, current->coocol);
				return 1;
			}else{
				temp = current->row;
				current->row = current->col;
				current->col = temp;
				add_in_matrix(grid, current, current->coorow, current->coocol);
				printf("Error in line %d: cannot rotate\n", yylineno);
				return 0;
			}
		}else{
			printf("Error in line %d: %s not placed\n", yylineno, id);
			return 0;
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

/*
used for move in direction dir by a number of cells specified by num. updates coordinates inside block and matrix inside grid
*/
int update_dir(grid_t * grid, char* id, char* dir, int num){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	brick_list * list = grid->bricks;
	brick_t * current = list->head;

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
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
			if(current->coorow == -1 && current->coocol == -1){
					printf("Error in line %d: %s not placed\n", yylineno, id);
				return 0;
			}else{
				int temprow;
				int tempcol;
				switch (dir_num){
					case 1:
					temprow = current->coorow;
					tempcol = current->coocol-num;
					break;
					case 2:
					temprow = current->coorow;
					tempcol = current->coocol+num;
					break;
					case 3:
					temprow = current->coorow-num;
					tempcol = current->coocol;
					break;
					case 4:
					temprow = current->coorow+num;
					tempcol = current->coocol;
					break;
				}
				if ( update(grid, 1, id, temprow, tempcol))
					return 1;
				else return 0;
			}
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

/*
deletes brick identified by the provided id from the grid, removes it from the matrix inside the grid,
then frees memory allocated for it
*/
int delete_block(grid_t * grid, char* id) {
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	brick_list * list = grid->bricks;
	brick_t* current = list->head;
	brick_t* temp = malloc(sizeof(brick_t));

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	if (strcmp(current->id, id) == 0){
		if (on_top(grid, current)){
			free(current);
			list->head = current->next;
			delete_in_matrix(grid, current);
			return 1;
		}else{
			printf("Error in line %d: %s not on top\n", yylineno, id);
			return 0;
		}
	}

	while(current->next != NULL){
		if (strcmp(current->next->id, id)==0 ){
			if (on_top(grid, current->next)){
				temp = current->next;
				current->next = temp->next;
				delete_in_matrix(grid, temp);
				free(temp);
				return 1;
			}else{
				printf("Error in line %d: %s not on top\n", yylineno, id);
				return 0;
			}

			return 1;
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

/*
deletes all bricks from the grid
*/
int delete_all(grid_t * grid){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	brick_list * list = grid->bricks;
	brick_t * current;

	while(list->head != NULL){
		delete_in_matrix(grid, list->head);
		current=list->head;
		list->head = list->head->next;
		free(current);
	}

	return 1;
}


/*
function for handling while loop
while the block still fits, move it by a number of cells given by num in the direction given by dir
*/
int while_move (grid_t * grid, char* id, char* dir, int num){
	if (default_grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	brick_list * list = grid->bricks;
	brick_t * current = list->head;

	if (list->head == NULL){
		printf("Brick %s not found. Error in line %d\n", id, yylineno);
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
			int temprow;
			int tempcol;
			switch (dir_num){
				case 1:
				temprow = current->coorow;
				tempcol = current->coocol-num;
				break;
				case 2:
				temprow = current->coorow;
				tempcol = current->coocol+num;
				break;
				case 3:
				temprow = current->coorow-num;
				tempcol = current->coocol;
				break;
				case 4:
				temprow = current->coorow+num;
				tempcol = current->coocol;
				break;
			}
			while(fits(grid, id, temprow, tempcol) != 0){
				update_dir(grid, id, dir, num);
				switch (dir_num){
					case 1:
					temprow = current->coorow;
					tempcol = current->coocol-num;
					break;
					case 2:
					temprow = current->coorow;
					tempcol = current->coocol+num;
					break;
					case 3:
					temprow = current->coorow-num;
					tempcol = current->coocol;
					break;
					case 4:
					temprow = current->coorow+num;
					tempcol = current->coocol;
					break;
				}
			}
			return 1;
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

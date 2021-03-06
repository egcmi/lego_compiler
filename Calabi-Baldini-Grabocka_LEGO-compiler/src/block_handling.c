/*
creates an empty list of blocks
*/
l_list * create_list(void) {
	l_list* p;
	p = malloc(sizeof(l_list));
	p->head = NULL;
	return p;
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

	l_list * list = grid->blocks;
	node_t * current = list->head;
	node_t * node = malloc(sizeof(node_t));
	node->id = id;
	node->row = row;
	node->col = col;
	node->type = type;
	node->coorow = coorow;
	node->coocol = coocol;

	if (list->head == NULL){
		list->head = node;
		list->head->next = NULL;
		return 1;
	}

	while (current->next != NULL) {
		if(strcmp(current->id, id) == 0){
			printf("Error in line %d: %s already defined\n", yylineno, id);
			free(node);
			return 0;
		}
		current = current->next;
	}

	if(strcmp(current->id, id) == 0){
		printf("Error in line %d: %s already defined\n", yylineno, id);
		free(node);
		return 0;
	}

	current->next = malloc(sizeof(node_t));
	current->next = node;
	current->next->next = NULL;
	return 1;
}

/*
checks if the block identified by id fits at the given coordinates (row,y)
returns 1 if it fits, 0 if it doesn't
returns 0 (false) if:
	- there is not enough room (brick would be "hanging" out of the grid)
	- the surface where the brick needs to be placed is uneven (blocks of different heights, domes, pyramid)
	returns error if:
	- no bricks exists
	- coordinates (row,col) are less than 0 or bigger than the grid
*/
int fits(grid_t * grid, char id[], int row, int col){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	l_list * list = grid->blocks;
	node_t * current = list->head;
	int gridrow = grid->row;
	int gridcol = grid->col;

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	if (row > gridrow || col > gridcol || row < 0 || col < 0){
		return -1;
	}

	while (current != NULL) {
		if(strcmp(current->id, id) == 0){
			int checkrow = (current->row)-gridrow+row;
			int checkcol = (current->col)-gridcol+col;
			if(checkrow > 0 || checkcol > 0){
				return -4;
			}

			char * var = grid->matrix[row][col];
			if(strstr(var, "o") != NULL || strstr(var,"x") != NULL){
				return -2;
			}

			char * currVar;
			for(int i = row; i < row+current->row; i++){
				for(int j = col; j < col+current->col; j++){
					currVar = grid->matrix[i][j];
					if(strcmp(var,currVar) != 0){
						return -3;
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
checks if brick (node) is on top of the grid. returns 1 when true, 0 otherwise.
*/
int on_top(grid_t * grid, node_t * node){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	int coorow = node->coorow;
	int coocol = node->coocol;

	if (node->h == height(grid, coorow, coocol)){
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

	l_list * list = grid->blocks;
	node_t * current = list->head;
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
increases the height/number of blocks of the cell in the grid defined by (coorow, coocool) by one when a new block is placed/moved.
if the (topmost) block (node_t) added is a pyramid or dome, concatenates an 'x' or 'o' to the number to represent it
*/
void add_in_matrix(grid_t * grid, node_t * node, int coorow, int coocol){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return;
	}

	int row = node->row;
	int col = node->col;
	char * type = node->type;
	int cell_height = height(grid, coorow,coocol);
	node->h = cell_height + 1;

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
decreases the height/number of blocks of the cell in the grid defined by (coorow, coocool) by one when a new block is deleted/moved.
if the (topmost) block (node_t) removed is a pyramid or dome, the 'x' or 'o' that represent this condition are removed
*/
int delete_in_matrix(grid_t * grid, node_t * node){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	int row = node->row;
	int col = node->col;
	int coorow = node->coorow;
	int coocol = node->coocol;

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
parameter method: 0 for place, 1 for move
*/
int update(grid_t * grid, int method, char* id, int coorow, int coocol) {
	if(grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}
	l_list * list = grid->blocks;
	node_t * current = list->head;

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	while (current != NULL) {
		if((strcmp(current->id, id) == 0)){
			if(method == 0){
				if(current->coorow == -1 && current->coocol == -1){
					int f = fits(grid, current->id, coorow, coocol);
					if(f == 1){
						current->coorow = coorow;
						current->coocol = coocol;
						add_in_matrix(grid, current, coorow, coocol);
						return f;
					}else if (f == -4){
						printf("Error in line %d: not enough room\n", yylineno);
						return f;
					} else return f;
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
					int f = fits(grid, current->id, coorow, coocol);
					if(f== 1){
						current->coorow = coorow;
						current->coocol = coocol;
						add_in_matrix(grid, current, coorow, coocol);
						return f;
					}else if (f == -4){
						printf("Error in line %d: not enough room\n", yylineno);
						add_in_matrix(grid, current, past_row, past_col);
						return f;
					} else return f;
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
	l_list * list = grid->blocks;
	node_t * current = list->head;

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	while (current != NULL) {
		if((strcmp(current->id, id) == 0)){
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
				if(fits(grid, current->id, current->coorow, current->coocol) == 1){
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

	l_list * list = grid->blocks;
	node_t * current = list->head;

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
				if ( update(grid, 1, id, temprow, tempcol) == 1)
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

	l_list * list = grid->blocks;
	node_t* current = list->head;
	node_t* temp = malloc(sizeof(node_t));

	if (list->head == NULL){
		printf("Error in line %d: %s not defined\n", yylineno, id);
		return 0;
	}

	if (strcmp(current->id, id) == 0){
		if(current->coorow <0 || current->coocol<0){
			free(current);
			list->head = current->next;
			return 1;
		}
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
			if(current->coorow <0 || current->coocol<0){
				temp = current->next;
				current->next = temp->next;
				free(temp);
				return 1;
			}
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
deletes all blocks from the grid
*/
int delete_all(grid_t * grid){
	if (grid == NULL){
		printf("Error in line %d: no grids defined\n", yylineno);
		return 0;
	}

	l_list * list = grid->blocks;
	node_t * current;

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

	l_list * list = grid->blocks;
	node_t * current = list->head;

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
			int past_row;
			int past_col;			
			switch (dir_num){
				case 1:					// left
				temprow = current->coorow;
				tempcol = current->coocol-num;
				break;
				case 2:					// right
				temprow = current->coorow;
				tempcol = current->coocol+num;
				break;
				case 3:					// up
				temprow = current->coorow-num;
				tempcol = current->coocol;
				break;
				case 4:					//down
				temprow = current->coorow+num;
				tempcol = current->coocol;
				break;
			}
			if (on_top(grid, current)){
				delete_in_matrix(grid, current);
				past_row=current->coorow;
				past_col=current->coocol;
				current->coorow=-1;
				current->coocol=-1;
				current->h=current->h-1;	
			}
			else{
				printf("Error in line %d: %s not on top\n", yylineno, id);
				return 0;
			}
			if(fits(grid, id, temprow, tempcol) != 1){
				update(grid,0, id,past_row,past_col);
				return 0;
			}
			int temprow1=temprow;
			int temprcol1=tempcol;

			while(fits(grid, id, temprow, tempcol) == 1){
				switch (dir_num){
					case 1:
					temprcol1=tempcol;					
					tempcol = tempcol-num;
					break;
					case 2:
					temprcol1=tempcol;					
					tempcol = tempcol+num;
					break;
					case 3:
					temprow1=temprow;
					temprow = temprow-num;
					break;
					case 4:
					temprow1=temprow;
					temprow = temprow+num;
					break;
				}
			}
			update(grid,0, id,temprow1,temprcol1);
			return 1;
		}
		current = current->next;
	}

	printf("Error in line %d: %s not defined\n", yylineno, id);
	return 0;
}

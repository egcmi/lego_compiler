#ifndef GRID_H
#define GRID_H

/*
represents a linked list of grids characterised as follows:
    head:   points to the first grid in the list
*/
typedef struct grid_list {
	grid_t *head;
} g_list;


/*
functions defined in block_handling.c
*/
g_list * grid_list;
grid_t * default_grid;
g_list* create_grid_list(void);
grid_t* create_grid_t(void);
int add_grid(g_list * list, char id[], int row, int col);
int delete_grid(g_list * list, char* id);
int switch_grid(g_list * list, char* id);
int show(g_list * list, char* id);
int free_matrix(char *** matrix, int row, int col);

#endif

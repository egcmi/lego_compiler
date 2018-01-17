#ifndef BLOCK_H
#define BLOCK_H

/*
represents a lego brick characterised as follows:
    id:     unique name
    x:      depth; e.g. if x==2 then the brick has depth of 2 units
    y:      width; e.g. if y==3 then the brick has width 3 units
    type:   matrix, dome or pyramid
    coox:   coordinate x on which it is placed to on the grid, -1 before it is placed on the grid
    cooy:   coordinate y on which it is placed to on the grid, -1 before it is placed on the grid
    h:      vertical position at which the brick is placed.
            given that each brick is 1 unit tall, h is defined as the sum of the number of bricks placed under it plus 1.
            e.g. if the brick is placed directly on the grid its height is 1;
            if the brick is placed on top of another brick placed on top of another brick, then its height is 3
    next:   next brick in the list
*/
typedef struct node {
    char* id;
    int x;      // swapped
    int y;      // swapped
    char* type;
    int coox;   // swapped
    int cooy;   // swapped
    int h;
    struct node * next;
} node_t;

/*
represents a linked list of lego bricks characterised as follows:
    head:   points to the first lego brick (node_t) in the list
*/
typedef struct list {
    node_t *head;
} l_list;

/*
represents a grid to place lego bricks on and is characterised as follows:
    id:     
    row:    
    col:    
    blocks: 
    matrix: 
    next:   
*/
typedef struct grid{
    char* id;
    int row;
    int col;
    l_list * blocks;
    char *** matrix;
    struct grid * next;
} grid_t;

/*
functions prototypes; defined in block_handling.c
*/
l_list * create_list(void);
int add(grid_t * grid, char* id, int x, int y, char* type, int coox, int cooy);
int delete_block(grid_t * grid, char* id);
int delete_all(grid_t * grid);
int update(grid_t * grid, int method, char* id, int coox, int cooy);
int update_dir(grid_t * grid, char* id, char* dir, int num);
int fits(grid_t * grid, char* id, int x, int y);
int add_in_matrix(grid_t * grid, node_t * node, int coox, int cooy);
int delete_in_matrix(grid_t * grid, node_t * node);
int on_top(grid_t * grid, node_t * node);
int height(grid_t * grid, int x, int y);
int height_var(grid_t * grid, char* id);

#endif
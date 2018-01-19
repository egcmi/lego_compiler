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
typedef struct brick {
    char* id;
    int row;
    int col;
    char* type;
    int coorow;
    int coocol;
    int h;
    struct brick* prev;
    struct brick* next;
} brick_t;

/*
represents a linked list of lego bricks characterised as follows:
    head:   points to the first lego brick (brick_t) in the list
*/
typedef struct doubly_ll {
    brick_t *head;
    brick_t *tail;
    int length;
} brick_list;

/*
represents a grid to place lego bricks on and is characterised as follows:
    id:     unique name
    row:    number of rows
    col:    number of columns
    blocks: list of blocks
    matrix: representation of the grid:
            each cell contains a numerical value representing the height/number of blocks on that cell,
            plus an additional optional character 'o' or 'x' representing respectively whether the last
            brick is a dome or a pyramid
    next:   next brid in the list
*/
typedef struct grid{
    char* id;
    int row;
    int col;
    brick_list * blocks;
    char *** matrix;
    struct grid * next;
} grid_t;

/*
functions defined in block_handling.c
*/
brick_list * create_list(void);
int add(grid_t * grid, char* id, int x, int y, char* type, int coox, int cooy);
int delete_block(grid_t * grid, char* id);
int delete_all(grid_t * grid);
int update(grid_t * grid, int method, char* id, int coox, int cooy);
int update_dir(grid_t * grid, char* id, char* dir, int num);
int fits(grid_t * grid, char* id, int x, int y);
void add_in_matrix(grid_t * grid, brick_t * brick, int coox, int cooy);
int delete_in_matrix(grid_t * grid, brick_t * brick);
int on_top(grid_t * grid, brick_t * brick);
int height(grid_t * grid, int x, int y);
int height_var(grid_t * grid, char* id);
int while_move(grid_t * grid, char* id, char* dir, int num);
int rotate(grid_t * grid, char* id);

#endif
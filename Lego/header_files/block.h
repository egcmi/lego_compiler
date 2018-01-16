typedef struct node {
    char* id;
    int x;
    int y;
    char* type;
    int z;
    int coox;
    int cooy;
    int h;
    struct node * next;
} node_t;

typedef struct list {
	node_t *head;
} l_list;

typedef struct grid{
    char* id;
    int row;
    int col;
    l_list * blocks;
    char *** matrix;
    struct grid * next;
} grid_t;

l_list * create_list(void);
int add(grid_t * grid, char* id, int x, int y, char* type, int coox, int cooy);
int delete_block(grid_t * grid, char* id);
int delete_all(grid_t * grid);
int update(grid_t * grid, int method, char* id, int coox, int cooy);
int update_dir(grid_t * grid, char* id, int coox, int cooy);
int fits(grid_t * grid, char* id, int x, int y);
int add_in_matrix(grid_t * grid, node_t * node, int coox, int cooy);
int delete_in_matrix(grid_t * grid, node_t * node);
int on_top(grid_t * grid, node_t * node);
int height(grid_t * grid, int x, int y);
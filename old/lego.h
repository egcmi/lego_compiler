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


typedef struct grid_list {
	grid_t *head;
} g_list;


g_list * grid_list;
grid_t * default_grid;
int add(grid_t * grid, char* id, int x, int y, char* type, int coox, int cooy);
int rm(grid_t * grid, char* id);
int update(grid_t * grid, int method, char* id, int coox, int cooy);
int update_dir(grid_t * grid, char* id, int coox, int cooy);
int add_grid(g_list * list, char* id, int row, int col);
int rm_grid(g_list * list, char* id);
int switch_grid(g_list * list, char* id);
int show(g_list * list, char* id);
int free_matrix(char *** matrix, int row, int col);
int fits(grid_t * grid, char id[], int x, int y);
int add_in_matrix(grid_t * grid, node_t * node, int coox, int cooy);
int delete_in_matrix(grid_t * grid, node_t * node);
int on_top(grid_t * grid, node_t * node);
int height(grid_t * grid, int x, int y);
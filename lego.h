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

typedef struct grid {
	int row;
	int col;
	int matrix[row][col];
	l_list * blocks;
} grid_t;


l_list * list;
int add(l_list * list, char id[], int x, int y, int z, char* type, int coox, int cooy, int h);
int rm(l_list * list, char* id);
int update(l_list * list, int method, char* id, int coox, int cooy);
int updateDir(l_list * list, char* id, int coox, int cooy);
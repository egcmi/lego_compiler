typedef struct node {
    char* id;
    int x;
    int y;
    int z;
    char* type;
    int coox;
    int cooy;
    int h;
    struct node * next;
} node_t;

typedef struct list {
	int count;
	node_t *head;
} list_t;

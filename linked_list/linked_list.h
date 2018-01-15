#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
	char* id;
	int x;
	int y;
	int z;
	char* type;
	int coox;
	int cooy;
	int h;
	struct node *next;
} node_t;

node_t* create_node(char* id, int x, int y, int z, int coox, int cooy, int h);
node_t* create_list(void);
int insert_element(node_t *head, node_t *element);
int delete_element(node_t *head, char* id);

#endif /*LINKEDLIST_H*/
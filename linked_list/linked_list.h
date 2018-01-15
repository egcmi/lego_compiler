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

typedef struct list {
	int count;
	node_t *first;
} l_list;

node_t* create_node(char* id, int x, int y, int z, int coox, int cooy, int h);
l_list* create_list(void);
int insert_element(l_list *list, node_t *element);
int delete_element(l_list *list, char* id);

#endif /*LINKEDLIST_H*/
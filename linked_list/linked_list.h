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
} node_struct;

typedef struct list {
	int count;
	node_struct *first;
} list_struct;

node_struct* create_node(char* id, int x, int y, int z, int coox, int cooy, int h);
list_struct* create_list(void);
int insert_element(list_struct *list, node_struct *element);
int delete_element(list_struct *list, char* id);

#endif /*LINKEDLIST_H*/
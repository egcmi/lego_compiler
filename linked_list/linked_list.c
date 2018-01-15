#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

node_t* create_node(char* id, int x, int y, int z, int coox, int cooy, int h){
	node_t* p; //pointer
	p=malloc(sizeof(node_t));
	p->id = id;								// !!! char* id /pointer???) !!!
	p->x = x;
	p->y = y;
	p->z = z;
	p->coox = coox;
	p->cooy = cooy;
	p->h = h;
	p->next = NULL;
	printf("Created node: id=%s, x=%d, y=%d, z=%d, coox=%d, cooy=%d, h=%d\n",
		p->id, p->x, p->y, p->z, p->coox, p->cooy, p->h);
	return p;
}

l_list* create_list(void) {
	l_list* p;
	p = malloc(sizeof(l_list));
	p->count = 0;
	p->first = NULL;
	printf("Created list, length=%d\n", p->count);
	return p;
}

// add element to the end of the list
int insert_element(l_list *list, node_t *element) {
	// list is empty
	if(list->count == 0){
		list->first = element;
		printf("Added node id=%s, in position=%d\n", element->id, list->count);
		list->count++;
		return TRUE;
	}

	// list is not empty
	node_t* current;
	current = list->first;
	while(current->next != NULL){
		if( strcmp(current->id, element->id)==0 ){
			printf("Variable %s already in use. Error in line %s\n", element->id, "yylineno");
			return FALSE;
		}
		current = current->next;
	}
	current->next = element;
	printf("Added node id=%s, in position=%d\n", element->id, list->count);
	list->count++;
	return TRUE;
}

int delete_element(l_list *list, char* id) {
	// list is empty
	if (list->count == 0){
		printf("Variable list is empty: could not delete %s. Error in line %s\n", id, "yylineno");
		return FALSE;
	}

	// list is not empty
	node_t* current;
	current = list->first;
	node_t* temp = malloc(sizeof(node_t));

	// delete first elelement
	if ( strcmp(current->id, id)==0 ){
		free(list->first);
		list->first = current->next;
		printf("Deleted node id=%s at position=%d\n", id, list->count);
		list->count--;
		return TRUE;
	}

	// delete any element
	while(current->next != NULL){
		if ( strcmp(current->next->id, id)==0 ){
			temp = current->next;
			current->next = temp->next;
			free(temp);
			printf("Deleted node id=%s at position=%d\n", id, list->count);
			list->count--;
			return TRUE;
		}
	}

	printf("Variable %s does not exist: it cannot be deleted. Error in line %s\n", id, "yylineno");
	return FALSE;
}


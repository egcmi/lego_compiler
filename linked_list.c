#include <stdio.h>
#include <stdlib.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


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
int delete_element(list_struct *list, node_struct *p);



node_struct* create_node(char* id, int x, int y, int z, int coox, int cooy, int h){
	node_struct* p; //pointer
	p=malloc(sizeof(node_struct));
	p->id = id;								// !!! char* id /pointer???) !!!
	p->x = x;
	p->y = y;
	p->z = z;
	p->coox = coox;
	p->cooy = cooy;
	p->h = h;
	p->next = NULL;
	return p;
}

list_struct* create_list(void) {
	list_struct* p;	//pointer
	p = malloc(sizeof(list_struct));
	p->count = 0;
	p->first = NULL;
	return p;
}

// add element to the end of the list
int insert_element(list_struct *list, node_struct *element) {
	// list is empty
	if(list->count == 0){
		list->first = element;
		list->count++;
		return TRUE;
	}

	// list is not empty
	node_struct* current;
	current = list->first;
	while(current->next != NULL){
        if(current->id == element->id){				// !!! string comparison !!!
        	printf("Variable %s already in use. Error in line %d\n", element->id, yylineno);
        	return FALSE;
        }
        current = current->next;
    }
    current->next = element;
//	element->next = NULL;
    list->count++;
    return TRUE
}

int delete_element(list_struct *list, char* id) {
	// list is empty
	if (list->count == 0){
		printf("Variable list is empty: could not delete %s. Error in line %d\n", id, yylineno);
		return FALSE;
	}

	// list is not empty
	node_struct* current, temp;
	current = list->first;
	temp = NULL;

	// delete first elelement
	if (current->id == id){								// !!! string comparison !!!
		free(list->first);
		list->first = current->next;
		list->count--;
		return TRUE;
	}

	// delete any element
	while(current->next != NULL){
		if (current->next->id == id){					// !!! string comparison !!!
			temp = current->next;
			current->next = temp->next;
			free(temp);
			list->count--;
			return TRUE;
		}
	}

	printf("Variable %s does not exist: it cannot be deleted. Error in line %d\n", id, yylineno);
	return FALSE;
}

int main() {


	list_struct *test_list;

	test_list=create_sList();

	if (test_list == NULL) return 0;

	if ( insert_element(test_list, NULL,7) == 0 )
	{
		printf("Adding first element succeeded\n");
		delete_element(test_list, NULL);
		printf("Only element also deleted\n");
	}
	else 
		printf("Adding failed\n");

	return 1;
}

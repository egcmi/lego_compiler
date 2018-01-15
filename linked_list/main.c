/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: emanuela
 *
 * Created on 15 January 2018, 09:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
/*
 * 
 */
int main(int argc, char** argv) {

	node_t *node;
	node = create_node("b1", 1, 2, 1, 0, 1, 1);

	node_t *head;
	head = malloc(sizeof(node_t));

	if(insert_element(head, node)){
		printf("Insert successful\n");
	} else {
		printf("Insert failed\n");
	}

	if(delete_element(head, "b1")){
		printf("Delete successful\n");
	} else {
		printf("Insert failed\n");
	}

	return (EXIT_SUCCESS);
}


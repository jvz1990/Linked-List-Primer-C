/*
 * doublyLinkList.h
 *
 *  Created on: 25Jan.,2017
 *      Author: j
 */

#ifndef LINKEDLIST_DOUBLYLINKLIST_H_
#define LINKEDLIST_DOUBLYLINKLIST_H_

#include <commons.h>

// dll - Doubly Linked List

typedef struct dll_node {
	UInt val;
	struct dll_node *next;
	struct dll_node *previous;
} dll_node_t;

Bool dll_init_list(dll_node_t ** head, dll_node_t ** last, UInt val);
void dll_print_list(dll_node_t ** head);
void dll_print_list_reverse(dll_node_t ** last);
Bool dll_push_last(dll_node_t ** head, dll_node_t ** last, UInt val);
Bool dll_push_first(dll_node_t ** head, dll_node_t ** last, UInt val);
void dll_destroy_list(dll_node_t ** head, dll_node_t ** last);
UInt dll_length(dll_node_t ** head);

void dll_pop_last(dll_node_t ** last);
void dll_pop_index(dll_node_t ** head, int n);




#endif /* LINKEDLIST_DOUBLYLINKLIST_H_ */

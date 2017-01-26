/*
 * linkedList.h
 *
 *  Created on: 25Jan.,2017
 *      Author: j
 */

#ifndef LINKEDLIST_LINKEDLIST_H_
#define LINKEDLIST_LINKEDLIST_H_

#include <commons.h>

typedef struct node {
	int val;
	struct node *next;
} node_t;

Bool init_linkedList(int val);
void print_list(node_t * head);
Bool push_last(node_t * head, int val);
Bool push_first(node_t ** head, int val);
void pop_last(node_t * head);
void pop_index(node_t ** head, int n);

//TODO make local
node_t * head;
node_t * current;

#endif /* LINKEDLIST_LINKEDLIST_H_ */

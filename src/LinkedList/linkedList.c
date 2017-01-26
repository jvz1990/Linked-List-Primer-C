/*
 * linkedList.c
 *
 *  Created on: 25Jan.,2017
 *      Author: j
 */

#include <stdio.h>
#include <stdlib.h>

#include <commons.h>

#include "linkedList.h"


Bool init_linkedList(int val) {
	if((head = malloc(sizeof(node_t))) == NULL) return false;
	head->val = val;

#ifndef nullterminated
	head->next = NULL;
#else
	head->next = head;
#endif
	current = NULL;
	return true;
}

Bool push_first(node_t ** head, int val) {
	node_t * new_head;

	if((new_head = malloc(sizeof(node_t))) == NULL) return false;

#ifndef nullterminated
#else
	current = *head;
	do {
		if(current->next != *head) current = current->next;
	} while (current->next != *head);
	current->next = new_head;
#endif

	new_head->val = val;
	new_head->next = *head;
	*head = new_head;

	return true;
}

Bool push_last(node_t * head, int val) {
	current = head;

#ifndef nullterminated
	while(current->next != NULL) {
		current = current->next;
	}
#else
	while(current->next != head) {
		current = current->next;
	}
#endif

	if((current->next = malloc(sizeof(node_t))) == NULL) return false;
	current->next->val = val;

#ifndef nullterminated
	current->next->next = NULL;
#else
	current->next->next = head;
#endif
	return true;
}

void pop_last(node_t * head) {

	if(head->next == NULL) {
		free(head);
		head = NULL;
	}

	current = head;
#ifndef nullterminated
	while(current->next->next != NULL) {
		current = current->next;
	}
#else
	while(current->next->next != head) {
		current = current->next;
	}
#endif
	free(current->next);

#ifndef nullterminated
	current->next = NULL;
#else
	current->next = head;
#endif
}

void print_list(node_t * head) {
	current = head;

#ifndef nullterminated
	while(current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
#else
	do {
		printf("%d\n", current->val);
		current = current->next;
	} while(current != head);
#endif
}

void pop_index(node_t ** head, int n) {

	current = *head;

	if(n < 1) {

#ifndef nullterminated
		current = current->next;
		free(*head);
		*head = current;
#else
		while(current->next != *head) {
			current = current->next;
		}
		current->next = (*head)->next;
		current = (*head)->next;
		free(*head);
		*head = current;
#endif

		return;
	}

	int i = 0;
	node_t * temp = NULL;

	for(; i < n-1; i++) {
		if(current->next == NULL) return;
		current = current->next;
	}

	temp = current->next;
	current->next = current->next->next;

	free(temp);
	temp = NULL;
}

/*
 * doublyLinkList.c
 *
 *  Created on: 25Jan.,2017
 *      Author: j
 */

#include <stdio.h>
#include <stdlib.h>

#include <commons.h>

#include "doublyLinkList.h"

UInt dll_length(dll_node_t ** head) {

	if(*head == NULL) {
		puts("\n!!--NO LIST FOUND. PLEASE INITIALIZE!--!!\n");
		return 0;
	}

	UInt i = 0;
	dll_node_t * current;

	current = *head;

	while(current->next != NULL) {
		i++;
		current = current->next;
	}

	return i+1;
}

Bool dll_init_list(dll_node_t ** head, dll_node_t ** last, UInt val) {

	if(*head != NULL) puts("\n Beware, another head already existing! \n");

	dll_node_t * new_head;
	if((new_head = malloc(sizeof(dll_node_t))) == NULL) return false;

	new_head->val = val;
	new_head->previous = NULL;
	new_head->next = NULL;

	*head = new_head;
	*last = new_head;

	return true;
}

void dll_print_list(dll_node_t ** head) {

	if(*head == NULL) {
		puts("\n!!--NO LIST FOUND. PLEASE INITIALIZE!--!!\n");
		return;
	}

	int i = 0;
	dll_node_t * current = *head;

	while(current != NULL) {
		printf("Object no. [%i] with value of [%i]\n", i++, current->val);
		current = current->next;
	}
}

void dll_print_list_reverse(dll_node_t ** last) {

	if(*last == NULL) {
		puts("\n!!--NO LIST FOUND. PLEASE INITIALIZE!--!!\n");
		return;
	}

	dll_node_t * current = *last;

	while(current != NULL) {
		printf("Object has value of [%i]\n", current->val);
		current = current->previous;
	}
}

Bool dll_push_last(dll_node_t ** head, dll_node_t ** last, UInt val) {

	if(*last == NULL) {
		puts("\n!!--NO EXISTING LIST FOUND--!!\n");
		return false;
	}

	dll_node_t * temp = *head;
	dll_node_t * new_item;
	if((new_item = malloc(sizeof(dll_node_t))) == NULL) return false;

	new_item->next = NULL;
	new_item->val = val;
	new_item->previous = *last;

	(*last)->next = new_item;
	*last = new_item;
	*head = temp;

	return true;
}

Bool dll_push_first(dll_node_t ** head, dll_node_t ** last, UInt val) {

	if(*head == NULL) {
		puts("\n!!--NO LIST FOUND. PLEASE INITIALIZE!--!!\n");
		return false;
	}

	dll_node_t * temp = *last;
	dll_node_t * new_item;

	if((new_item = malloc(sizeof(dll_node_t))) == NULL) return false;

	new_item->next = *head;
	new_item->val = val;
	new_item->previous = NULL;

	(*head)->previous = new_item;
	*head = new_item;
	*last = temp;

	return true;
}

void dll_destroy_list(dll_node_t ** head, dll_node_t ** last) {

	if(*head == NULL) {
		puts("\n!!--NO LIST FOUND. PLEASE INITIALIZE!--!!\n");
		return;
	}

	//end to start
	dll_node_t * temp;
	temp = *last;
	while(temp->previous != NULL) {
		temp = (*last)->previous;
		free(*last);
		*last = NULL;
		*last = temp;
	}
	free(*head); // destroying head
	*head = NULL; // setting NULL
	*last = NULL;
}

void dll_pop_last(dll_node_t ** last) {

	if(*last == NULL) {
		puts("\n!!--NO EXISTING LIST FOUND--!!\n");
		return;
	}

	*last = (*last)->previous;
	free((*last)->next);
	(*last)->next = NULL;
}

void dll_pop_index(dll_node_t ** head, int n) {

	if(n < 1) {
		*head = (*head)->next;
		free((*head)->previous);
		(*head)->previous = NULL;
		return;
	}

	dll_node_t * temp;
	temp = *head;

	UInt i = 0;

	for(; i < n; i++) {
		if(temp->next==NULL) return;
		temp = temp->next;
	}


	if(temp->next != NULL) temp->next->previous = temp->previous;
	if(temp->previous != NULL) temp->previous->next = temp->next;

	free(temp);
	temp = NULL;

}

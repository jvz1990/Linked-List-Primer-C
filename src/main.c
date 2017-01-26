/*
 ============================================================================
 Name        : test.c
 Author      : j
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "commons.h"

#include <LinkedList/linkedList.h>
#include <LinkedList/doublyLinkList.h>

// !!NOTE!! -- 'dll' in this instance = "Doubly Linked List"

int main(void) {

	dll_node_t * head = NULL;
	dll_node_t * last = NULL;

	UChar i = 0;

	if(dll_init_list(&head, &last, (UInt) i++) == false) return EXIT_FAILURE;

	for(; i < 6; i++) if(dll_push_last(&head, &last, (UInt) i) == false) return EXIT_FAILURE;

	dll_print_list(&head);

	puts("\n--Going in reverse--\n");
	dll_print_list_reverse(&last);

	printf("\nList contains %d items\n", dll_length(&head));

	puts("\nAdding items from the front\n");
	for(; i < 12;i++) if(dll_push_first(&head, &last, (UInt) (i*i)) == false) return EXIT_FAILURE;

	//12 items
	dll_pop_last(&last);
	//11..

	printf("\nList contains %d items\n", dll_length(&head));

	puts("\n -- Printing new list in forward mode \n");
	dll_print_list(&head);

	dll_destroy_list(&head, &last);
	printf("\nList contains %d items\n", dll_length(&head));

	i = 0;
	if(dll_init_list(&head, &last, (UInt) i++) == false) return EXIT_FAILURE;
	for(; i < 10; i++) if(dll_push_last(&head, &last, (UInt) i) == false) return EXIT_FAILURE;
	dll_print_list(&head);

	dll_pop_index(&head, 5);
	dll_print_list(&head);

	dll_destroy_list(&head, &last);


	return EXIT_SUCCESS;
}

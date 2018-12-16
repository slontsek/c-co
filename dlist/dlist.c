/*
 * This file is doubly_linked_list.c
 * Doubly linked list implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

#define MEMORY_ERROR -1

pdlist dlist_new(void) {

	pdlist list = malloc(sizeof(struct dlist));  // allocate memory for a new dlist
	
	if (NULL == list)                            // set parameters of an empty dlist
		return NULL;

	list->size = 0;
	list->head = NULL;

	return list;
}

int dlist_unshift(pdlist list, int value) {

	pdlist_entry pnew;
	pnew = malloc(sizeof(struct dlist_entry));   // allocate memory for a new element

	if (NULL == pnew)                            // error check
		return MEMORY_ERROR;

	pnew->next = list->head;                     // connect new element with the current dlist`s head
	pnew->value = value;

	printf("New element: %d\n", value);          // visualization

	if (NULL != list->head)
		pnew->next->prev = pnew;

	pnew->prev = NULL;
	list->head = pnew;                           // set new element as a new head of the dlist
	list->size++;
	return 0;
}

pdlist_entry dlist_pop(pdlist list, pdlist_entry *x) {

	int i;
	pdlist_entry p;                                       // declate temporary variale to moe through the dlist
	p = list->head;

	for (i = 0; i < list->size - 1; i++)                  // go through the dlist until the end
		p = p->next;

	*x = p;

	if (NULL != p->prev)
		p->prev->next = NULL;
	else
		list->head = NULL;

	list->size--;
	return *x;                                             // return the last element of the dlist
}

int dlist_delete(pdlist list) {

	pdlist_entry *x;
	x = malloc(sizeof(pdlist_entry));                      // allocate memory for a temp variable
	
	if (NULL == x)                                         // error check
		return MEMORY_ERROR;

	while (NULL != list->head->next) {
		dlist_pop(list, x);                                // do dlist_pop until no elements are left
		free(x);                                           // free memory
	}

	free(list->head);                                      // free memory
	free(list);
	return 0;
}

int dlist_push(pdlist list, int value) {

	int i;
	pdlist_entry p, pnew;
	pnew = malloc(sizeof(pdlist_entry));         // allocate memory for the new element
	if (NULL == pnew)                            // error check
		return MEMORY_ERROR;

	pnew->value = value;
	pnew->next = NULL;
	p = list->head;

	for (i = 0; i < list->size - 1; i++)
		p = p->next;                             // go to the end of the dlist

	p->next = pnew;                              // add new element to the end of the dlist
	pnew->prev = p;
	list->size++;
	return 0;
}

pdlist_entry *dlist_shift(pdlist list, pdlist_entry *x) {

	*x = list->head;                                          // we want do delete the first element of dlist
	list->head->next->prev = NULL;
	list->head = list->head->next;
	list->size--;
	return x;                                                 // return pointer to the deleted element
}

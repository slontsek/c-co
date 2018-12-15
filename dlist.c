/*
 * This file is doubly_linked_list.c
 * Doubly linked list implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

pdlist dlist_new(void) {

	pdlist list = malloc(sizeof(struct dlist));
	
	if (NULL == list)
		return NULL;

	list->size = 0;
	list->head = NULL;

	return list;
}

int dlist_unshift(pdlist list, int value) {

	pdlist_entry pnew;
	pnew = malloc(sizeof(struct dlist_entry));

	if (NULL == pnew)
		return -1;

	pnew->next = list->head;
	pnew->value = value;

	printf("New element: %d\n", value);

	if (NULL != list->head)
		pnew->next->prev = pnew;

	pnew->prev = NULL;
	list->head = pnew;
	list->size++;
	return 0;
}

pdlist_entry dlist_pop(pdlist list, pdlist_entry *x) {

	int i;
	pdlist_entry p;
	p = list->head;

	for (i = 0; i < list->size - 1; i++)
		p = p->next;

	*x = p;

	if (NULL != p->prev)
		p->prev->next = NULL;

	else
		list->head = NULL;

	list->size--;
	return *x;
}

int dlist_delete(pdlist list) {

	pdlist_entry *x;
	x = malloc(sizeof(pdlist_entry));

	while (NULL != list->head->next) {
		dlist_pop(list, x);
		free(x);
	}

	free(list->head);
	free(list);
	return 0;
}

int dlist_push(pdlist list, int value) {

	int i;
	pdlist_entry p, pnew;
	pnew = malloc(sizeof(pdlist_entry));
	pnew->value = value;
	pnew->next = NULL;
	p = list->head;

	for (i = 0; i < list->size - 1; i++)
		p = p->next;

	p->next = pnew;
	pnew->prev = p;
	list->size++;
	return 0;
}

pdlist_entry *dlist_shift(pdlist list, pdlist_entry *x) {

	*x = list->head;
	list->head->next->prev = NULL;
	list->head = list->head->next;
	list->size--;
	return x;
}
/*
* This file is dlist.h
* Header for doubly linked list
*/

#pragma once

typedef struct dlist_entry *pdlist_entry;

typedef struct dlist *pdlist;

struct dlist_entry {
	int value;
	pdlist_entry next;
	pdlist_entry prev;
};

struct dlist {
	int size;
	pdlist_entry head;
};

/*
 * Creates empty list
 * Parametres: none
 * Returns pointer to the list
 */

pdlist dlist_new(void);

/*
 * Adds new element to the beginning of the list
 * Parametres: list - pointer to the list, value - the element we want to add
 * Returns -1 if an error happens and 0 if everything is OK
 */

int dlist_unshift(pdlist list, int value);

/*
 * Frees memory for each element
 * Params: list - pointer to the list we want to delete
 * Returns 0 if everything is OK and the list was deleted;
 */

int dlist_delete(pdlist list);

/*
 * Deletes the last element of the list
 * Parametres: list - pointer to the list, x - saves the deleted element
 * Returns deleted element
 */

pdlist_entry dlist_pop(pdlist list, pdlist_entry *x);

/*
 * Adds new element to the end of the list
 * Params: list - pointer to the list, value - the element we want to add
 * Returns 0 if no errrors
 */

int dlist_push(pdlist list, int value);

/*
 * Deletes the first element of the list
 * Params: list - pointer to the list, x - saves the deleted element
 * Returns x - deleted element
 */

pdlist_entry *dlist_shift(pdlist list, pdlist_entry *x);

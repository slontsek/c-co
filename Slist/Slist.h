/*
 * This file is slist.h
 * Header for single linked list
 */

#pragma once

//Forward declaration

typedef struct slist_entry *pslist_entry;
typedef struct slist *pslist;

struct slist_entry {
	pslist_entry next;
	int value;
};

struct slist {
	pslist_entry head;
	int list_size;
};

/*
 * Creates an empty list
 * Params: none
 * Returns pointer to the created list
 */

pslist slist_new(void);

/*
 * Deletes existing list and all its elements
 * Params: list - pointer to the existing list 
 * Returns: none
 */

void slist_delete(pslist list);

/*
 * Adds a new element to the list
 * Params: list - pointer to the list, value - the value of the added element
 * Returns 0 if the elements was inserted, 1 - in case of error
 */

int slist_insert(pslist list, int value);

/*
 * Removes all the elements with the given value from the list
 * Params: list - pointer to the list, value - the value of the elements we want to remove from the list
 * Returns 0 if the element(-s) was(were) removed, 1 - in case of error
 */

int slist_remove(pslist list, int value);

/*
 * Prints all the elements of the list
 * Params: list - pointer to the list
 * Returns: none
 */

void slist_print(pslist list);

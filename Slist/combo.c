#include <stdio.h>
#include <stdlib.h>

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

pslist slist_new(void) {
  pslist list = malloc(sizeof(struct slist)); // allocating memory for the new slist
	if (NULL == list)                           // error check
	{
		printf("List was not created\n");
		return NULL;
	}
	list->list_size = 0;                        // set parametres of an empty slist
	list->head = NULL;
	return list;
}

/*
 * Helper slist_pop removes head from the list
 * Params: list - pointer to the list
 * Returns pointer to the head
 */

pslist_entry slist_pop(pslist list) {
	if (NULL != list->head) {
		pslist_entry pcurr = list->head;  // store info about head in a pcurr temporary variable
		free(list->head);                 // free memory where old head was kept
		list->head = pcurr->next;         // set new head of the slist
		free(pcurr);                      // free memory of a temp variale pcurr
		list->list_size--;
	};
	return list->head;
}

void slist_delete(pslist list) {
	pslist_entry curr_head;
	while (NULL != (curr_head = slist_pop(list))) {  // do slist_pop until untial there are no elements in the slist
	};
	free(curr_head);
	free(list);                                      // free memory where list was kept
}

//allocates memory for the new element, puts it to the end

int slist_insert(pslist list, int value) {
	pslist_entry pnew = malloc(sizeof(struct slist_entry));  // allocating memory for a new element
	if (NULL == pnew)                                        // error check
	{
		printf("Element is not inserted\n");
		return -1;
	}
	pnew->next = list->head;                                 // connect new element with the head of the slist                   
	list->list_size++;
	list->head = pnew;                                       // set new element as a new head of the slist
	pnew->value = value;
	printf("Inserted element is: %d\n", pnew->value);        // visualization
	return 0;
}

int slist_remove(pslist list, int value) {
	while (list->head->value == value)
		slist_pop(list);                            // if head has the value we are looking for, do slist_pop until it is not so

	pslist_entry pcurr = list->head, ptemp;         // declare pslist_entry temp to store temporary info about curr->next
	while (NULL != pcurr->next) {                   // search for elements with the desired value until the end of the slist
		if ((pcurr->next)->value == value) {
			ptemp = pcurr->next;
			free(pcurr->next);                      // free memory of the current element
			pcurr->next = NULL;
			if (NULL != pcurr->next) {
				printf("Element was not deleted");
				return -1;
			}
			pcurr->next = ptemp->next;              // connect the previous element with the next one
			list->list_size--;
		}
		pcurr = pcurr->next;                        // go to the next loop
	}
	if (pcurr->value == value) {                    // check the last left element
		free(pcurr);
		pcurr = NULL;
		list->list_size--;
	}
	return 0;
}

//For each element print its value

void slist_print(pslist list) {
	pslist_entry pcurr = list->head;   // declare variable to keep the info about current slist`s head
	printf("List: \n");
	while (NULL != pcurr) { 
		printf("%d\n", pcurr->value);  // print all elements of the slist
		pcurr = pcurr->next;
	}
}

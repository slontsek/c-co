/*
 * This file is slist.c
 * Single linked list implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include "Slist.h"

pslist slist_new(void) {
	pslist list = malloc(sizeof(struct slist));
	if (NULL == list)
	{
		printf("List was not created\n");
		return NULL;
	}
	list->list_size = 0;
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
		pslist_entry pcurr = list->head;
		free(list->head);
		list->head = pcurr->next;
		free(pcurr);
		list->list_size--;
	};
	return list->head;
}

void slist_delete(pslist list) {
	pslist_entry curr_head;
	while (NULL != (curr_head = slist_pop(list))) {
	};
	free(curr_head);
	free(list);
}

//allocates memory for the new element, puts it to the end

int slist_insert(pslist list, int value) {
	pslist_entry pnew = malloc(sizeof(struct slist_entry));
	if (NULL == pnew)
	{
		printf("Element is not inserted\n");
		return -1;
	}
	pnew->next = list->head;
	list->list_size++;
	list->head = pnew;
	pnew->value = value;
	printf("Inserted element is: %d\n", pnew->value);
	return 0;
}

int slist_remove(pslist list, int value) {
	while (list->head->value == value)
		slist_pop(list);

	pslist_entry pcurr = list->head, ptemp; //declare pslist_entry temp to store temporary info about curr->next
	while (NULL != pcurr->next) {
		if ((pcurr->next)->value == value) {
			ptemp = pcurr->next;
			free(pcurr->next);
			pcurr->next = NULL;
			if (NULL != pcurr->next) {
				printf("Element was not deleted");
				return -1;
			}
			pcurr->next = ptemp->next;
			list->list_size--;
		}
		pcurr = pcurr->next;
	}
	if (pcurr->value == value) {
		free(pcurr);
		pcurr = NULL;
		list->list_size--;
	}
	return 0;
}

//For each element print its value

void slist_print(pslist list) {
	pslist_entry pcurr = list->head;
	printf("List: \n");
	while (NULL != pcurr) {
		printf("%d\n", pcurr->value);
		pcurr = pcurr->next;
	}
}
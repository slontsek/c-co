/*
 * This is Slist_test.c
 * Testing Slist.c
 */


#include <stdio.h>
#include "Slist.h"

#define KRED "\x1B[31m" // red
#define KGRN "\x1B[32m" // green
#define KWHT "\x1B[37m" // white

#define CREATE_ERROR 1
#define REMOVE_ERROR -1


/*
 * testing creation, insertion and printing of a list
 */

int test1()
{
	pslist list;
// create new list and insert values
	list = slist_new();
	printf("List created! %p\n", list);
	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_insert(list, 3);
// print created list
	slist_print(list);
// delete it after work
	slist_delete(list);
	return 0;
}

/*
 * testing list creation
 */

int test2()
{
	pslist list = slist_new();
// is the program is correct, new list is expected to be empty and have size == 0
	if (NULL != list->head)
		goto error_path;
	if (0 != list->list_size)
		goto error_path;

	slist_delete(list);
	return 0;
// in case of incorrect work, delete the list and return error code
error_path:
	slist_delete(list);
	return CREATE_ERROR;
}

/*
 * testing removing elements from the list
 */

int test3()
{
	pslist list = slist_new();

	slist_insert(list, 1);
	slist_insert(list, 1);
	slist_insert(list, 2);
	slist_remove(list, 1);
// the program is expected to remove all the elements with value == 1, so list_size should be 1 after that
	int result = (list->list_size != 1) ? REMOVE_ERROR : 0;
	slist_delete(list);
// return 0 in case of correct work 
	return result;
}

int main(void)
{
	printf("Hello, " "world!" "\n");
	test1();
	printf("TEST #2 Create list:\t\t%s%s\n", (test2() == 0) ? KGRN"PASSED" : KRED"FAILED", KWHT);
	printf("TEST #3 Remove element:\t\t%s%s\n", (test3() == 0) ? KGRN"PASSED" : KRED"FAILED", KWHT);

	return 0;
}

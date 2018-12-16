/*
 * This file is traverse.c
 * Implementation of traverse function to print bst sketchily
 * Should be compiled with bst (1).h and bst (1).c files
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst (1).h"

/*
 * Helper: adds paddings to print bst nicely
 * Arguments: ch - char symbol, n - number of symbols
 * Returns: none
 */

void padding(char ch, int n) {

	int i;
	for (i = 0; i < n; i++)
		putchar(ch);
}

/*
 * Traverses tree and prints all its nodes sketchily in horizontal form
 * Arguments: tree - pointer to the bst, depth - depth of bst
 * Returns: none
 */

void traverse(PTREE_NODE tree, int depth) {

	if (tree == NULL) {
		padding('\t', depth);
		puts("õ");
	}
	else {
		traverse(tree->right, depth + 1);
		padding('\t', depth);
		printf("%d\n", tree->key);
		traverse(tree->left, depth + 1);
	}
}

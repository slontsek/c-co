/*
 * This file is check_tree.c
 * The function to check if BST is an AVL tree or not
 * Should be compiled with bst (1).h and bst (1).c
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst (1).h"

/*
 * Checks if the tree is an AVL tree
 * Params: tree - pointer to the tree that is going to be checked
 * Returns: 1, if the tree is an AVL tree
 *          0, if it is not
 */

int check_tree(PTREE_NODE tree) {
	
	if (tree != NULL) {
// get the height of each subtree
		int n = tree_depth(tree->left);
		int k = tree_depth(tree->right);
// the difference between heights should not be more than 1 and subtrees should both be AVL trees
		if (abs(k - n) <= 1 && check_tree(tree->left) == 1 && check_tree(tree->right) == 1) 
			return 1;
// otherwise, the tree is not an AVL tree
		return 0;	
	}
// empty tree is an AVL tree
	return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include "bst2.h"

int check_tree(PTREE_NODE tree) {
	if (tree != NULL) {
		int n = tree_depth(tree->left);
		int k = tree_depth(tree->right);
		if (abs(k - n) <= 1 && check_tree(tree->left) == 1 && check_tree(tree->right) == 1) 
			return 1;		
		return 0;	
	}
	return 1;
}
/*
 * This file is bst (1).c
 * Binary Search Tree implementstion
 */

#include <stdio.h> 
#include <stdlib.h> 
#include "bst (1).h"

PTREE_NODE create_tree(void) {
	PTREE_NODE tree = NULL;
	return tree;
}

PTREE_NODE add_node(PTREE_NODE tree, int x) {
	if (tree == NULL) {
		tree = (PTREE_NODE)malloc(sizeof(TREE_NODE));
		tree->key = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else {
		if (x < tree->key) {
			tree->left = add_node(tree->left, x);
		}
		if (x > tree->key) {
			tree->right = add_node(tree->right, x);
		}
	}
	return tree;
}

/*
 * Helper
 * Finds the node with min key
 * Arguments: tree - pointer to the tree
 * Returns pointer to the found node
 */

PTREE_NODE min_key_node(PTREE_NODE tree)
{
	PTREE_NODE curr = tree;
	while (NULL != curr->left)
		curr = curr->left;

	return curr;
}

PTREE_NODE delete_node(PTREE_NODE tree, int key)
{
	if (NULL == tree)
		return tree;

	if (key < tree->key)
		tree->left = delete_node(tree->left, key);

	else if (key > tree->key)
		tree->right = delete_node(tree->right, key);

	else {
		if (NULL == tree->right) {
			PTREE_NODE temp = tree->left;
			free(tree);
			return temp;
		}
		else if (NULL == tree->left) {
			PTREE_NODE temp = tree->right;
			free(tree);
			return temp;
		}

		PTREE_NODE temp = min_key_node(tree->right);

		tree->key = temp->key;

		tree->right = delete_node(tree->right, temp->key);
	}
	return tree;
}

void destroy_tree(PTREE_NODE tree) {
	if (tree != NULL) {
		destroy_tree(tree->left);
		destroy_tree(tree->right);
	}
	tree = NULL;
	free(tree);
}

void dfs(PTREE_NODE tree) {
	if (tree != NULL) {
		dfs(tree->left);
		printf("%d ", tree->key);
		dfs(tree->right);
	}
}

/*
 * Helper
 * Arguments: tree - pointer to the tree
 * Returns depth pf the tree
 */

int tree_depth(PTREE_NODE tree) {
	int n, m;
	if (tree == NULL) {
		return 0;
	}
	else {
		n = tree_depth(tree->left);
		m = tree_depth(tree->right);
		if (m > n) {
			return m + 1;
		}
		else {
			return n + 1;
		}
	}
}

/*
 * Helper
 * Prints all nodes of the given level
 * Arguments: tree - pointer to the tree, level
 * Returns: none
 */

void tree_lvl(PTREE_NODE tree, int x) {
	if (x == 0) {
		printf("%d ", tree->key);
	}
	if (tree->left != NULL) {
		tree_lvl(tree->left, x - 1);
	}
	if (tree->right != NULL) {
		tree_lvl(tree->right, x - 1);
	}
}

void wfs(PTREE_NODE tree) {
	int depth = tree_depth(tree);
	int level;
	for (level = 0; level < depth; level++)
		tree_lvl(tree, level);
}

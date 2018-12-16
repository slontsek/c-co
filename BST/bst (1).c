/*
 * This file is bst (1).c
 * Binary Search Tree implementation
 */

#include <stdio.h> 
#include <stdlib.h> 
#include "bst (1).h"

#define MEMORY_ERROR 1

PTREE_NODE create_tree(void) {
	PTREE_NODE tree = NULL;
	return tree;
}

PTREE_NODE add_node(PTREE_NODE tree, int x) {
	if (tree == NULL) {                                   // create tree and add node to it
		tree = (PTREE_NODE)malloc(sizeof(TREE_NODE)); // allocate memory for the new tree
		if (NULL == tree) 
			return MEMORY_ERROR;                  // error check
		tree->key = x;
		tree->left = NULL;                            // set parameters of the tree
		tree->right = NULL;
	}
	else {
		if (x < tree->key) {
			tree->left = add_node(tree->left, x);
		}                                             // add new node to an existing tree
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
// the very left node has min key
	while (NULL != curr->left) 
		curr = curr->left; 

	return curr;
}

PTREE_NODE delete_node(PTREE_NODE tree, int key)
{
	if (NULL == tree)                                    // trivial case
		return tree;

	if (key < tree->key)
		tree->left = delete_node(tree->left, key);   // go to the left subtree

	else if (key > tree->key)
		tree->right = delete_node(tree->right, key); // go to the right subtree

	else {                                               // we want to delete the current node
		if (NULL == tree->right) {                   // there is no right child
			PTREE_NODE temp = tree->left;        // declare temp variable to store info about left child
			free(tree);                          // free memory of the current node  
			return temp;
		}
		else if (NULL == tree->left) {               // there is no left child
			PTREE_NODE temp = tree->right;
			free(tree);
			return temp;
		}

		PTREE_NODE temp = min_key_node(tree->right); // set temp as the node with min value from the right subtree 

		tree->key = temp->key;                       // put temp node insted of tree (pointer to the root)

		tree->right = delete_node(tree->right, temp->key);
	}
	return tree;
}

void destroy_tree(PTREE_NODE tree) {
	if (tree != NULL) {
		destroy_tree(tree->left);  // delete recursively
		destroy_tree(tree->right);
	}
	tree = NULL;
	free(tree);
}

void dfs(PTREE_NODE tree) {
	if (tree != NULL) {
		dfs(tree->left);            // go to the left subtree
		printf("%d ", tree->key);   // printing the current node
		dfs(tree->right);           // go to the right subtree
	}
}

/*
 * Helper
 * Arguments: tree - pointer to the tree
 * Returns depth of the tree
 */

int tree_depth(PTREE_NODE tree) {
	int n, m;
	if (tree == NULL)                  // trivial case
		return 0;
	n = tree_depth(tree->left);        // go to the subtrees recursively
	m = tree_depth(tree->right);
	if (m > n)
		return m + 1;
	return n + 1;
}

/*
 * Helper
 * Prints all nodes of the given level
 * Arguments: tree - pointer to the tree, 
 *            level - level of the tree whose nodes are needed to be printed
 * Returns: none
 */

void tree_lvl(PTREE_NODE tree, int level) {
	if (0 == level) {
		printf("%d ", tree->key);        // print the root
	}
	if (tree->left != NULL) {
		tree_lvl(tree->left, level - 1);
	}
	if (tree->right != NULL) {
		tree_lvl(tree->right, level - 1);
	}
}

void wfs(PTREE_NODE tree) {
	int depth = tree_depth(tree);           // store depth of the tree
	int level;
	for (level = 0; level < depth; level++) // printing levels one by one
		tree_lvl(tree, level);
}

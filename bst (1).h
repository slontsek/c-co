/*
 * This file is bst.h
 * Header for bst.c
 */

#pragma once

 //Forward declaration

typedef struct _TREE_NODE *PTREE_NODE;

typedef struct _TREE_NODE {
	int key;
	PTREE_NODE left, right;
} TREE_NODE;

/*
 * Creates an empty tree
 * Arguments: none
 * Returns pointer to the created tree
 */

PTREE_NODE create_tree(void);

/*
 * Adds new element to the BST
 * Arguments:
 * 	tree - pointer to the tree
 *	key  - value of map key
 * Returns pointer to the tree
 */

PTREE_NODE add_node(PTREE_NODE tree, int key); // prototype

/*
 * Deletes existing element with the given key from the tree
 * Arguments:
 *  tree - pointer to the tree
 *  key - value of map key
 * Returns pointer to the deleted node
 */

PTREE_NODE delete_node(PTREE_NODE tree, int key);

/*
 * Does depth-first search of the tree and prints all nodes
 * Arguments: tree - pointer to the tree
 * Returns: none
 */

void dfs(PTREE_NODE tree);

/*
 * Does width-first search of the tree and prints all nodes
 * Arguments: tree - pointer to the tree
 * Returns: none
 */

void wfs(PTREE_NODE tree);

/*
 * Destroys the existing tree and all its nodes
 * Arguments: tree - pointer to the tree
 * Returns: none
 */

void destroy_tree(PTREE_NODE tree);

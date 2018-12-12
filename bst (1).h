/*
 * This file is bst.h
 * Header for bst.c - Binary Search Tree implementation
 */

#pragma once

//Forward declaration

#define FALSE 0
#define TRUE 1

typedef struct _TREE_NODE *PTREE_NODE;

typedef struct _TREE_NODE {
	int key;
	PTREE_NODE left, right;
} TREE_NODE;

// extern FILE *g_log;

/*
 * Creates new empty tree
 * Arguments: none
 * Returns pointer to the created tree
 */

//PTREE_NODE init_tree(void);

/*
 * Adds new element to the BST
 * Arguments:
 * 	tree - pointer to the tree
 *	key  - value of map key
 * Returns pointer to the tree (created or existing)
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
 * Prints all the nodes of the tree
 * Arguments: tree - pointer to the tree
 * Returns: none
 */

void print_tree(PTREE_NODE tree);

/*
 * Finds the node with the given value of the key
 * Arguments:
 *  tree - pointer to the tree where to search
 *  key - the value of the key
 * Returns pointer to the found node
 */

PTREE_NODE find(PTREE_NODE tree, int key);

/*
 * Destroys the existinct tree and all its nodes
 * Arguments: tree - pointer to the tree
 * Returns: none
 */

void destroy_tree(PTREE_NODE tree);

/*
 * This file is AVL.h
 * Header for AVL.c
 */

#pragma once 
#define MAX_SIZE 50

typedef struct Node *pnode;

typedef struct Node {
	char *surname; // surname 
	char *tel;     // phone number 
	pnode left;    // pointer to the left node 
	pnode right;   // pointer to the right node 
	int height;
} Node;


/*
 * Adds a new node to the tree
 * Params: p - pointer to the tree, s - surname of a new node, t - phone number of a new node
 * Returns pointer to the updated tree
 */

pnode add_node(pnode p, char s[MAX_SIZE], char t[MAX_SIZE]);

/*
 * Difference between heights of left and right subtrees
 * Params: p - pointer to the node
 * Returns: (height of the right subtree) - (height of the left subtree)
 */

int bfactor(pnode p);

/*
 * Finds height of the subtree
 * Params: p - pointer to the node
 * Returns height - int
 */

int height(pnode p);

/*
 * Changes height of the subtree (we have to do it after adding new nodes)
 * Params: x - pointer to the subtree
 * Returns: none
 */

void fixheight(pnode p);

/*
 * We need rotateleft and rotateright to keep the tree balanced
 * Params: p or q - pointer to the subtree we want to rotate
 * Returns pointer to the updated subtree
 */

pnode rotateleft(pnode p);

pnode rotateright(pnode q);

/*
 * Balance function to make AVL-tree from our tree after adding new nodes
 * Params: p - pointer to the tree
 * Returns pointer to the balanced tree
 */

pnode balance(pnode p);

/*
 * Finds node with node->surname = s
 * Params: p - pointer to the tree, s - surname we are looking for
 * Returns: pointer to the found node (NULL if surname is not found)
 */

pnode find_node(pnode p, char s[MAX_SIZE]);

/*
 * Prints phone number of the person we are looking for
 * Params: p - pointer to the tree, s - surname we are looking for
 * Returns: none
 */

void find(pnode p, char s[MAX_SIZE]);

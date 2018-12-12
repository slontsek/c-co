/*
 * This file is bst.c
 * Binary Search Tree implementstion
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// FILE *g_log; // g stands for global

/*int init_log(void)
{
	g_log = fopen("log.txt", "w+");
	if (NULL == g_log)
	{
		printf("Can't create log file\n");
		return FALSE;
	}

	fprintf(g_log, "init_log()\n");
	return TRUE;
}

void deinit_log(void)
{
	fprintf(g_log, "deinit_log()\n");
	fclose(g_log);
}
*/

PTREE_NODE add_node(PTREE_NODE tree, int key)
{
	if (NULL == tree)
	{
		//fprintf(g_log, "Create new tree\n");
		//printf("Create new tree\n");
		tree = malloc(sizeof(TREE_NODE));
		if (NULL == tree) {
			// fprintf(g_log, "Tree was not created\n");
			printf("Tree was not created\n");
			return -1;
		}
		tree->key = key;
		tree->left = tree->right = NULL;
	}
	else if (tree->key > key) {
		// fprintf(g_log, "add_node(%p, %d)\n", tree, key);
		// printf("add_node(%p, %d)\n", tree, key);
		tree->left = add_node(tree->left, key);
	}
	else
		tree->right = add_node(tree->right, key);

	return tree;
}

/* 
 * Helper: finds node with min key
 * Arguments: tree - pointer to the tree
 * Returns pointer to the node with min key
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
	//fprintf(g_log, "delete_node(%p, %d)\n", tree, key);

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

void print_tree(PTREE_NODE tree)
{
	//fprintf(g_log, "print_tree(%p)\n", tree);

	if (NULL != tree) {
		//printf("Tree is empty\n");
		//fprintf(g_log, "Tree is empty\n");
		print_tree(tree->left);
		printf("%d\n", tree->key);
		//fpintf(g_log, "%d", tree->key);
		print_tree(tree->right);
	}
}

PTREE_NODE find(PTREE_NODE tree, int key)
{
	// fprintf(g_log, "find(%d)\n", key);

	if (NULL == tree)
		return tree;

	if (key == tree->key)
		return tree;

	if (key < tree->key)
		tree->left = find(tree->left, key);

	else
		tree->right = find(tree->right, key);

	return tree;
}

void destroy_tree(PTREE_NODE tree)
{
	if (NULL == tree)
		//printf("Tree is destroyed\n");
		//fprintf(g_log, "Tree is destroyed\n");
		
	if (NULL != tree) {
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		free(tree);
		tree = NULL;
	}
}
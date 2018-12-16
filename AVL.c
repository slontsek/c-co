/*
 * This file is AVL.c
 * AVL-tree implementation and application for notebook task
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "AVL.h" 

pnode add_node(pnode p, char s[MAX_SIZE], char t[MAX_SIZE]) {

// If it is the first such note in the notebook
	if (NULL == p) {
		p = malloc(sizeof(pnode)); //allocating memory
		p->surname = calloc(MAX_SIZE, sizeof(char));
		p->tel = calloc(MAX_SIZE, sizeof(char));
		memcpy(p->surname, s, strlen(s) + 1);
		memcpy(p->tel, t, strlen(t) + 1);
		p->left = NULL; //set children of this node in AVL-tree as NULLs
		p->right = NULL;
	}
// If it is not the first note, put them in alphabetical order
	else if (strcmp(s, p->surname) > 0)
		p->right = add_node(p->right, s, t);
	else 
		p->left = add_node(p->left, s, t);

	return balance(p); // pointer to the balanced tree (made from ours)
}

int height(pnode p) {

	return p ? p->height : 0; // if p is not NULL, returns its height, else - 0
}

int bfactor(pnode p) {

	return height(p->right) - height(p->left); // returns factor of a tree
}

void fixheight(pnode p) {

	int h1 = height(p->left);
	int h2 = height(p->right);
	p->height = (h1 > h2 ? h1 : h2) + 1;  // if h1 > h2 returns h1 + 1, else - h2 + 1  
}

pnode rotateright(pnode p) {

	pnode q;

// rotation of right and left subbtrees of p
	q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);

	return q; // pointer to the rotated subtree
}

pnode rotateleft(pnode q) {

	pnode p;

// rotation of right and left subtrees of q
	p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);

	return p; // pointer of the updated subtree
}

/* 
 * use rotations to balance unbalanced tree
 * bfactor(p) cannot be more than 2 or less than -2 as we always balance the tree after adding a new node
 * if -2 < bfactor(p) < 2 we do not have to balance the tree
 */
pnode balance(pnode p) {

	fixheight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);

		return rotateleft(p);
	}
	if (bfactor(p) == -2) {
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);

		return rotateright(p);
	}
	return p;
}

pnode find_node(pnode p, char s[MAX_SIZE]) {

	int check = 0; // helper-variable
	pnode q = p;

	while (check == 0) {
		if (strcmp(s, q->surname) == 0)  // if strings are equal 
			return q;
		if (strcmp(s, q->surname) > 0) { // if s > p->surname (in alphabetical order)
			if (NULL != q->right)
				q = q->right;
			else
				check = -1;
		}
		if (strcmp(s, q->surname) < 0) { // if s < p->surname (in alphabetical order)
			if (NULL != q->left)
				q = q->left;
			else
				check = -1;
		}
	}
	if (check == -1)
		return 0;
}

void find(pnode p, char s[MAX_SIZE]) {

	pnode q;
	q = find_node(p, s);

	if (NULL == q)
		printf("Not found"); // such note was not found
	else
		printf("%s \n", q->tel); // printing the phone number
}

// Lets check how our notebook works

int main() {

	pnode note;
	note = NULL;
	char c[MAX_SIZE] = "Nikitin";
	char tel[MAX_SIZE] = "89643487691";
	note = add_node(note, c, tel);
	strcpy(c, "Mishin");
	strcpy(tel, "89761254331");
	note = add_node(note, c, tel);
	find(note, "Petrov");

	return 0;
}

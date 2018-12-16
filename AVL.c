/*
 * This file is AVL.c
 * AVL-tree implementation and application for notebook task
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "AVL.h" 

pnode add_node(pnode p, char s[MAX_SIZE], char t[MAX_SIZE]) {

	if (NULL == p) {
		p = malloc(sizeof(pnode));
		p->surname = calloc(MAX_SIZE, sizeof(char));
		p->tel = calloc(MAX_SIZE, sizeof(char));
		memcpy(p->surname, s, strlen(s) + 1);
		memcpy(p->tel, t, strlen(t) + 1);
		p->left = NULL;
		p->right = NULL;
	}
	else if (strcmp(s, p->surname) > 0)
		p->right = add_node(p->right, s, t);
	else 
		p->left = add_node(p->left, s, t);

	return balance(p);
}

int height(pnode p) {

	return p ? p->height : 0;
}

int bfactor(pnode p) {

	return height(p->right) - height(p->left);
}

void fixheight(pnode p) {

	int h1 = height(p->left);
	int h2 = height(p->right);
	p->height = (h1 > h2 ? h1 : h2) + 1;
}

pnode rotateright(pnode p) {

	pnode q;

	q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);

	return q;
}

pnode rotateleft(pnode q) {

	pnode p;

	p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);

	return p;
}

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

	int check = 0;
	pnode q = p;

	while (check == 0) {
		if (strcmp(s, q->surname) == 0)
			return q;
		if (strcmp(s, q->surname) > 0) {
			if (NULL != q->right)
				q = q->right;
			else
				check = -1;
		}
		if (strcmp(s, q->surname) < 0) {
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
		printf("Not found");
	else
		printf("%s \n", q->tel);
}

 // Lets check how our notebook works

int main() {

	pnode note;
	note = NULL;
	char c[MAX_SIZE] = "Никитин";
	char tel[MAX_SIZE] = "89643487691";
	note = add_node(note, c, tel);
	strcpy(c, "Ильин");
	strcpy(tel, "89761254331");
	note = add_node(note, c, tel);
	find(note, "Петров");

	return 0;
}
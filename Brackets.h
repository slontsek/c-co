/*
 * This file is Brackets.h
 * Header for brackets implementation
 */

#pragma once

// forward declaration

typedef struct bracket* pbracket;

/* structure of a bracket */
struct bracket
{
	char value;
	pbracket next;
};

/*
 * Function to push an item to stack
 * Params: top - pointer to the top bracket, new_value - new bracket
 * Returns: none
 */

void push(pbracket *top, int new_value);

/* 
 * Function to pop a bracket from the stack
 * Params: top - pointer to the top bracket
 * Returns the popped bracket
 */

char pop(pbracket *top);

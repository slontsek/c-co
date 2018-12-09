/*
 * This is Brackets.c
 * Implementation of stack for brackets task
 */

#include <stdio.h> 
#include <stdlib.h> 
#include "Brackets.h"
#define MAX_SIZE 1000

/* Returns 1 if character1 and character2 are matching left
and right brackets */
int is_correct(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else
		return 0;
}

/*Return 1 if expression has balanced brackets */
int are_balanced(char exp[])
{
	int i = 0;

	/* Declare an empty character stack */
	pbracket stack = NULL;

	while (exp[i])
	{
		/*If the exp[i] is a starting brackets then push it*/
		if (exp[i] == '{' || exp[i] == '(')
			push(&stack, exp[i]);

		/* If exp[i] is an ending bracket then pop from stack and
		check if the popped bracket is a matching pair*/
		if (exp[i] == '}' || exp[i] == ')')
		{

			/*If we see an ending bracket without a pair then return false*/
			if (NULL == stack)
				return 0;

			/* Pop the top element from stack, if it is not a pair
			bracket of character then there is a mismatch.*/
			if (!is_correct(pop(&stack), exp[i]))
				return 0;
		}
		i++;
	}

	/* If there is something left in expression then there is a starting
	bracket without a closing one */
	if (NULL == stack)
		return 1; //correct
	return 0;  //incorrect
}

int main()
{
	char exp[MAX_SIZE];
	scanf_s("%s", &exp, MAX_SIZE);
	if (are_balanced(exp))
		printf("Correct\n");
	else
		printf("Incorrect\n");
	return 0;
}

/* Function to push an item to stack*/
void push(pbracket top, int new_value)
{
	/* allocate memory for a new bracket */
	pbracket new_bracket =
		(pbracket)malloc(sizeof(struct bracket));

	/* put in the value */
	new_bracket->value = new_value;

	/* link the old stack with the new bracket */
	new_bracket->next = top;

	/* move the top to the new bracket */
	top = new_bracket;
}

/* function to pop a bracket from the stack */
int pop(pbracket top)
{
	char res;
	pbracket new_top;
	new_top = top;
	res = new_top->value;
	top = new_top->next;
	free(new_top);
	return res;
}
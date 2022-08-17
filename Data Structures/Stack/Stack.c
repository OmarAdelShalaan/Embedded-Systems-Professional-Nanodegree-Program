/*
 * Stack.c
 *
 *  Created on: Aug 12, 2022
 *      Author: omar
 */

#include "Stack.h"

void createEmptyStack(ST_stack_t *stack)
{
	stack->top = -1;
}

void push(ST_stack_t *stack, int data)
{
	if ( isFull( stack ) )
	{
		printf("Stack is Full\n");
		exit(-1);
	}
	stack->top++;
	stack->elements[stack->top] = data;
}

int  pop(ST_stack_t *stack)
{
	if(isEmpty(stack))
	{
		printf("Stack is Empty\n");
		exit(-1);
	}
	int temp = stack->elements[stack->top];
	stack->top--;
	return temp;
}

void printStack(ST_stack_t *stack)
{
	int temp = stack->top;
	int i;
	for ( i = 0; i <= temp; i++)
	{
		printf("Stack[%d] : %d\n", i + 1, stack->elements[i]);
	}
}

int getStackTop(ST_stack_t *stack)
{
	return (stack->top + 1);
}

bool isFull(ST_stack_t *stack)
{
	if ( (stack->top ) >= (stackSize - 1))
	{
		return true;
	}
	return false;
}

bool isEmpty(ST_stack_t *stack)
{
	if(stack->top == -1 )
	{
		return true;
	}
	return false;
}

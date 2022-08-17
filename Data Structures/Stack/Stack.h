/*
 * Stack.h
 *
 *  Created on: Aug 12, 2022
 *      Author: omar
 */

#ifndef STACK_H_
#define STACK_H_

#define stackSize  100

typedef enum bool
{
	false = 0,
	False = 0,
	true  = 1,
	True  = 1
}bool;

typedef struct stack
{
	int elements[stackSize];
	int top;
}ST_stack_t;

void createEmptyStack(ST_stack_t *stack);
void push(ST_stack_t *stack, int data);
int  pop(ST_stack_t *stack);
void printStack(ST_stack_t *stack);
int  getStackTop(ST_stack_t *stack);
bool isFull(ST_stack_t *stack);
bool isEmpty(ST_stack_t *stack);

#endif /* STACK_H_ */

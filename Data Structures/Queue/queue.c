/*
 * queue.c
 *
 *  Created on: Aug 17, 2022
 *      Author: omar
 */

#include "queue.h"

void createEmptyQueue(ST_queue_t *queue)
{
	queue->front = -1;
	queue->rear = -1;
}
void enqueue(ST_queue_t *queue, int data)
{
	if( isEmpty(queue) )
	{
		queue->front++;
		queue->rear++;
	}
	else if( isFull(queue) )
	{
		printf("Queue is Full\n");
		exit(-1);
	}
	else
	{
		queue->rear++;
	}
	queue->elements[queue->rear] = data;
}
int dequeue(ST_queue_t *queue)
{
	if( isEmpty(queue) )
	{
		printf("Queue is Empty\n");
		exit(-1);
	}
	int temp = queue->elements[queue->front];
	queue->front++;
	if( queue->rear < queue->front )
	{
		createEmptyQueue( queue);
	}
	return temp;
}
void printQueue(ST_queue_t *queue)
{
	int i;
	for(i = 0; i < queue_size; i++)
	{
		printf("%d\n",queue->elements[i]);
	}
}

int getQueueFront(ST_queue_t *queue)
{
	return queue->front;
}

int getQueueRear(ST_queue_t *queue)
{
	return queue->rear;
}

bool isFull(ST_queue_t *queue)
{
	if( queue->rear >= queue_size - 1)
	{
		return true;
	}
	return false;
}

bool isEmpty(ST_queue_t *queue)
{
	if( queue->front ==  -1)
	{
		return true;
	}
	return false;
}




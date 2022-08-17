/*
 * queue.h
 *
 *  Created on: Aug 17, 2022
 *      Author: omar
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define queue_size 100
typedef enum bool
{
	false = 0,
	False = 0,
	true = 1,
	True = 1,
}bool;
typedef struct queue {
	int elements[queue_size];
	int front;
	int rear;
}ST_queue_t;

void createEmptyQueue(ST_queue_t *queue);
void enqueue(ST_queue_t *queue, int data);
int dequeue(ST_queue_t *queue);
void printQueue(ST_queue_t *queue);
int getQueueFront(ST_queue_t *queue);
int getQueueRear(ST_queue_t *queue);
bool isFull(ST_queue_t *queue);
bool isEmpty(ST_queue_t *queue);


#endif /* QUEUE_H_ */

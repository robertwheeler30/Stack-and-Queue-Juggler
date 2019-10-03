/* Project: Stack and Queue Juggler
 * Programmer: Robert Wheeler
 * Course: CSC111
 * Professor: Dr. Lee
 * File: queueADT.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"
#include "SQ_JugglerClient.h"

//structure for the queue
struct queue{
    int size,back,front;
    unsigned int cap;
    int *array;
};

//Creates a queue variable and initializes and allocates data
//returns the newly created queue after its creation
Queue create_queue(unsigned int capacity)
{
    struct queue *q = (struct queue *) malloc(sizeof(struct queue));
    q->cap = capacity;
    q->front = 0;
    q->size = 0;
    q->back = capacity - 1;
    q->array = (int*) malloc(q->cap*sizeof(int));

    return q;
}

//Termination function that exits after 
//Relaying messages of errors that have occured
static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

//Destroys the passed queue by emptying it 
//then using free() to repurpose the memory space
void destroy_queue(Queue q)
{
  make_emptyQueue(q);
  free(q);
}

//Emptys the queue by redeclaring the front and size to zero
void make_emptyQueue(Queue q)
{
    q->front = 0;
    q->size = 0;
}

//Checks of the queue is full by comparing
//Its current size to its capacity
int is_fullQueue(Queue q)
{
    return (q->size == q->cap);
}

//Checks if the queue is empty by comparing its
//Its amount of contents to zero
int is_emptyQueue(Queue q)
{
    return (q->size == 0);
}

//Puts new data into the queue. First it checks to see if it is full
//The it will procede to increment the back and size.
void enqueue(Queue q, Item i)
{
    if(is_fullQueue(q))
    {
        terminate("Error in Enqueue: Queue is full");
    }

    q->back = (q->back + 1) % q->cap;
    q->array[q->back] = i;
    q->size = q->size + 1;
}

//Dequeue() checks if the queue is empty first then it will
//Return the last value as an item, which is our created
//typedef for integer.
Item dequeue(Queue q)
{
    if(is_emptyQueue(q))
    {
        terminate("Error in Enqueue: Queue is empty");
    }

    int ret = q->array[q->front];
    q->front = (q->front + 1) % q->cap;
    q->size = q->size - 1;
    return ret;
}


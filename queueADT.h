/* Project: Queue and Queue Juggler
 * Programmer: Robert Wheeler
 * Course: CSC111
 * Professor: Dr. Lee
 * File: QueueADT.h
 * 
 */

#include "SQ_JugglerClient.h"

#ifndef QUEUEADT_H
#define QUEUEADT_H


//Prototypes for all the functions in QueueADT.c
Queue create_queue(unsigned int capacity);
void destroy_queue(Queue q);
void make_emptyQueue(Queue q);
int is_emptyQueue(Queue q);
int is_fullQueue(Queue q);
void enqueue(Queue q, Item i);
int dequeue(Queue q);

#endif
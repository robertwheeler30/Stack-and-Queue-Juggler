/* Project: Stack and Queue Juggler Driver Code
 * Programmer: Robert Wheeler
 * Course: CSC111
 * Professor: Dr. Lee
 * File: SQ_JugglerClient.c
 * Purpose: To take input and push pop queue dequeue. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackADT.h"
#include "queueADT.h"

#define MAX 99

int main(int argc, char *argv[])
{
    //Declaring stacks and queues to be used
    Stack inStack = create_stack(), outStack = create_stack();
    Queue inQueue = create_queue(99), outQueue = create_queue(99);

    //Declaring file and data types
    FILE *proj_input;
    char data[MAX], str[MAX];
    int value;

    //Shows proper usage if not enough arguments are passed
    if (argc != 2)
    {
        fprintf(stderr, "usage: sqjuggler test.dat\n");
    }

    //Checks to make sure thesource file exists
    if ((proj_input = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }


    //scanning through the test.dat file for commands
    //Also pushes and enqueues & dequeues and pops
    fgets(str, MAX, proj_input);
    do
    {
        sscanf(str, "%s %d", &data[0], &value);

        if (strcmp(data, "add") == 0)
        {
            enqueue(inQueue, value);
            push(inStack, value);
        }
        if (strcmp(data, "delete") == 0)
        {
            enqueue(outQueue, pop(inStack));
            push(outStack, dequeue(inQueue));
        }
        fgets(str, MAX, proj_input);
    } while (!is_emptyQueue(inQueue));


    //Prints the stack and queue's
    printf("outStack: ");

    while (!is_emptyStack(outStack))
    {
        printf("%d ", pop(outStack));
    }

    printf("outQueue: ");

    while (!is_emptyQueue(outQueue))
    {
        printf("%d ", dequeue(outQueue));
    }

    printf("\n");

    fclose(proj_input); //Closes the files.
    return 0;
}
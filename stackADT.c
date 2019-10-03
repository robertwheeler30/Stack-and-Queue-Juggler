/* Project: Stack and Queue Juggler
 * Programmer: Robert Wheeler
 * Course: CSC111
 * Professor: Dr. Lee
 * File: StackADT.c
 * From textbook page 500, C Programming: a modern approach: KN King
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define MAX 99

//Creates a struct node
struct node
{
  Item data;
  struct node *next;
};

//Creates struct stack type
struct stack_type
{
  struct node *top;
};

//Termination function that will print a messsage passed by its caller and exit
static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

//Function to create stack. Called to create new individual stacks
Stack create_stack()
{
  Stack s = malloc(sizeof(struct stack_type));

  //Error Message
  if (s == NULL)
  {
    terminate("Error in create() : stack could not be created.");
  }

  s->top = NULL;

  return s;
}

//Frees the memory space allocated by the stack
void destroy_stack(Stack s)
{
  make_emptyStack(s);
  free(s);
}

//Emptys the stack by popping until is_empty() returns true
void make_emptyStack(Stack s)
{
  while (!is_emptyStack(s))
  {
    pop(s);
  }
}

//Checks if the stack is empty
int is_emptyStack(Stack s)
{
  return s->top == NULL;
}

//Checks if te stack is full.
int is_stackFull(Stack s)
{
  return 0;
}

//Enters data into the top of the stack.
void push(Stack s, Item i)
{
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
  {
    terminate("Error in push: stack is full.");
  }

  new_node->data = i;
  new_node->next = s->top;
  s->top = new_node;
}

//item is a data structure of type int but reprents the data in the stack
//Will withdraw the data from the stack from top to bottom
Item pop(Stack s)
{
  struct node *old_top;
  Item i;

  if (is_emptyStack(s))
  {
    terminate("Error in pop: stack is empty.");
  }

  old_top = s->top;
  i = old_top->data;
  s->top = old_top->next;
  free(old_top);
  return i;
}
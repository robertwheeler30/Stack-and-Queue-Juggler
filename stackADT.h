/* Project: Stack and Queue Juggler
 * Programmer: Robert Wheeler
 * Course: CSC111
 * Professor: Dr. Lee
 * File: stackADT.h
 * From textbook page 498, C Programming: a modern approach: KN King
 */

//Created an enumeration for the bool type to simplify things

#include "SQ_JugglerClient.h"

//creates an int type of item
typedef int Item;

//defines the stack
typedef struct stack_type *Stack;

//Prototypes for all the functions in stackADT.c
Stack create_stack();
void destroy_stack(Stack s);
void make_emptyStack(Stack s);
int is_emptyStack(Stack s);
int is_StackFull(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

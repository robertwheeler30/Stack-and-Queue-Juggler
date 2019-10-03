 #CSC111 Computer science II
 #makefile
 #Programmer: Robert Wheeler
 #Professor: Dr. Lee

SOURCES = stackADT.c queueADT.c SQ_JugglerClient.c
OBJECTS = stackADT.o queueADT.o SQ_JugglerClient.o
HEADERS = stackADT.h queueADT.h SQ_JugglerClient.h
CC = gcc
CFLAGS = -g -Wall

sqjuggler:	$(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) -o sqjuggler
clean:
		rm *o sqjuggler stackADT.o queueADT.o SQ_JugglerClient.o
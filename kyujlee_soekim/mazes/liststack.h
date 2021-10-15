#ifndef _LISTSTACK_
#define _LISTSTACK_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct pos {
	int x;
	int y;
}Pos;

typedef struct StackNodeType																						
{																													
	Pos data;																										
	struct StackNodeType* preElement;
}	StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	
	StackNode* pTopElement;		
} LinkedStack;

LinkedStack* createLinkedStack();


int pushLS(LinkedStack* pStack, StackNode element);


StackNode* popLS(LinkedStack* pStack);


StackNode* peekLS(LinkedStack* pStack);


void deleteLinkedStack(LinkedStack* pStack);



int isLinkedStackEmpty(LinkedStack* pStack);



#endif


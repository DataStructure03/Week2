#ifndef _LISTSTACK_
#define _LISTSTACK_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//each stack node
typedef struct StackNodeType																						// ex)stack
{																													// |3| <- top node
	int data;																										// |2| //<- top node point this node
	struct StackNodeType* preElement;// physical point element is Next Node but logical point element is preNode	// |1| -> NULL
}	StackNode;

// stack
typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} LinkedStack;

// create LinkedStack
LinkedStack* createLinkedStack();

// push element to LinkedStack
int pushLS(LinkedStack* pStack, StackNode element);

// pop element from LinkedStack
StackNode* popLS(LinkedStack* pStack);

// return the latest element
StackNode* peekLS(LinkedStack* pStack);

// delete LinkedStack
void deleteLinkedStack(LinkedStack* pStack);

// List doesn't have limitation so don't have to implement
//int isLinkedStackFull(LinkedStack* pStack);

//check LinkedStack is Empty
int isLinkedStackEmpty(LinkedStack* pStack);

//
int checkBracketMatching(char *pSource);

#endif


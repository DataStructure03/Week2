#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ArrayList's Element
typedef struct ArrayStackNodeType
{
	int data;  // Element's data
} ArrayStackNode;

// ArrayList
typedef struct ArrayStackType
{
	int maxElementCount;		// Element's max index
	int currentElementCount;	// Element's current index
	ArrayStackNode *pElement;	// array to store data
} ArrayStack;

// create arraystack
ArrayStack* createArrayStack(int maxElementCount);

// delete arraystack
void deleteArrayStack(ArrayStack* pStack);

// check the array whether it is full
int isArrayStackFull(ArrayStack* pStack);

// push element to arraystack
int pushAS(ArrayStack* pStack, ArrayStackNode element);

// pop element from arraystack
ArrayStackNode popAS(ArrayStack* pStack);

// return the latest element
ArrayStackNode* peekAS(ArrayStack* pStack);

// set zero all element
void clearArrayStack(ArrayStack* pStack);

// check ArrayStack is Empty
int isArrayStackEmpty(ArrayStack* pStack);

#endif

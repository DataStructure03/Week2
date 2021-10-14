#include <stdlib.h>

typedef struct StackNodeType
{
	int data;
} StackNode;

typedef struct ArrayStackType
{
	int currentElementCount;	// 현재 원소의 개수
	int maxElementCount;
	StackNode** arr;		// Top 노드의 포인터
} ArrayStack;

ArrayStack* createArrayStack(int max);
int pushAS(ArrayStack* pStack, StackNode *element);
StackNode* popAS(ArrayStack* pStack);
StackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);
int isBracketMatch(char *pSource);

#include "stack.h"
#include <string.h>


ArrayStack* createArrayStack(int max)
{
	ArrayStack	*new_AS = malloc(sizeof(ArrayStack));
	StackNode	**new_array = malloc(sizeof(StackNode *) * max);
	new_AS->currentElementCount = 0;
	new_AS->maxElementCount = max;
	new_AS->arr = new_array;
	return new_AS;
}

int pushAS(ArrayStack* pStack, StackNode *element)
{
	if (!pStack)
		return -1;
	if (isArrayStackFull(pStack))
		return -1;
	pStack->arr[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return pStack->currentElementCount;
}

StackNode* popAS(ArrayStack* pStack)
{
	if (!pStack)
		return NULL;
	if (isArrayStackEmpty(pStack))
		return NULL;
	return pStack->arr[--pStack->currentElementCount];
}

StackNode* peekAS(ArrayStack* pStack)
{
	if (!pStack)
		return NULL;
	if (isArrayStackEmpty(pStack))
		return NULL;
	return pStack->arr[pStack->currentElementCount - 1];
}

void deleteArrayStack(ArrayStack* pStack)
{
	for (int i = 0 ; i < pStack->currentElementCount; i++)
		free(pStack->arr[i]);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	return (pStack->maxElementCount == pStack->currentElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	return (pStack->currentElementCount == 0);
}

int isBracketMatch(char *pSource)
{
	ArrayStack *AS;
	StackNode *element;

	if (!pSource)
		return -1;
	AS = createArrayStack(strlen(pSource));
	for (int i = 0; pSource[i]; i++)
	{
		if (pSource[i] == '(')
		{
			element = malloc(sizeof(StackNode));
			pushAS(AS, element);
		}
		else if (pSource[i] == ')')
		{
			if (!(element = popAS(AS)))
			{
				deleteArrayStack(AS);
				return 0;
			}
			else
				free(element);
		}
	}
	if (!isArrayStackEmpty(AS))
		return 0;
	else
		return 1;
}

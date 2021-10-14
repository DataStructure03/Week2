#include "../linked_stack/linkedstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int checkBracketMatching(char *pSource)
{
	LinkedStack *stack;
	StackNode node;
	StackNode *pNode;

	stack = createLinkedStack();
	for (int i = 0; pSource[i] != 0; i++) {
		if (pSource[i] == '[' || pSource[i] == '{' || pSource[i] == '(') {
			node.data = pSource[i];
			pushLS(stack, node);
		} else if (pSource[i] == ']' || pSource[i] == '}' || pSource[i] == ')') {
			pNode = popLS(stack);
			if (pNode == NULL){
				return FALSE;
			}
			if (!((pNode->data == '[' && pSource[i] == ']') 
					|| (pNode->data == '{' && pSource[i] == '}')
					|| (pNode->data == '(' && pSource[i] == ')'))){
						return FALSE;
					}
		}
	}
	if (isLinkedStackEmpty(stack) == FALSE){
		return FALSE;
	}
	return TRUE;
}

int main()
{
	char s[MAX] = "{(3 + 4)+(2 * 6)} + [10 - 3{2(1 + 2)}]";
	int len = strlen(s);

	s[len] = 0;
	if (checkBracketMatching(s) == TRUE)
		printf("Success!\n");
	else
		printf("NOPE!\n");
	return 0;
}
#include "stack.h"
#include <stdio.h>

# define MAXNUM 10

int main()
{
	LinkedStack	*LS = createLinkedStack(MAXNUM);
	StackNode	node;
	StackNode	*ptr;
	int	data = 0;

	for(int i = 0, j = 0; i < MAXNUM; i++, j += 2)
	{
		node.data = j;
		printf("pushing : %d\n", node.data);
		pushLS(LS, node);
	}

	{
		printf("isStackFull : %d\n", isLinkedStackFull(LS));
	}

	{
		printf("peek top : %d\n", peekLS(LS)->data);
	}

	{
		for (int i = 0; i < MAXNUM + 2; i++)
		{
			ptr = popLS(LS);
			if (ptr)
				printf("popping top : %d\n", ptr->data);
			else
				printf("isStackEmpty : %d\n", isLinkedStackEmpty(LS));
		}
	}

	printf("-----------------------------------------\n");
	printf("BRACKET TEST\n");
	printf("-----------------------------------------\n");

	{
		char *s = "(1 + 2) + (3 + 4))";
		printf("%d\n", isBracketMatch(s));
	}

	{
		char *s = "(1 + 2) + (3 + 4)";
		printf("%d\n", isBracketMatch(s));
	}

	{
		char *s = "((1 + 2) + (3 + 4)";
		printf("%d\n", isBracketMatch(s));
	}

	{
		char *s = "( ((( ))) (( ) ( ) ( )) )";
		printf("%d\n", isBracketMatch(s));
	}

	{
		char *s = "( ((( ))) (( ) ( ) ( )) ) )";
		printf("%d\n", isBracketMatch(s));
	}

}

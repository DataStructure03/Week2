#include "stack.h"
#include <stdio.h>

# define MAXNUM 10

int main()
{
	ArrayStack	*AS = createArrayStack(MAXNUM);
	StackNode	*node;
	int	data = 0;

	for(int i = 0, j = 0; i < MAXNUM; i++, j += 2)
	{
		node = malloc(sizeof(StackNode));
		node->data = j;
		printf("pushing : %d\n", node->data);
		pushAS(AS, node);
	}

	{
		printf("isStackFull : %d\n", isArrayStackFull(AS));
	}

	{
		printf("peek top : %d\n", peekAS(AS)->data);
	}

	{
		for (int i = 0; i < MAXNUM + 2; i++)
		{
			node = popAS(AS);
			if (node)
				printf("popping top : %d\n", node->data);
			else
				printf("isStackEmpty : %d\n", isArrayStackEmpty(AS));
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

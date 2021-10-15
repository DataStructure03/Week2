#include "maze.h"

#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int go(int map[][MAX], LinkedStack *stack, int x, int y)
{
	StackNode element;
	if (x < 0 || y < 0 || x >= MAX || y >= MAX)
		return FALSE;
	if (map[x][y] == WALL || map[x][y] == CHECK)
		return FALSE;
	element.x = x;
	element.y = y;
	pushLS(stack, element);
	if (map[x][y] == END)
		return END;
	map[x][y] = CHECK;
	int exit = FALSE;
	exit |= go(map, stack, x - 1, y);
	exit |= go(map, stack, x, y - 1);
	exit |= go(map, stack, x + 1, y);
	exit |= go(map, stack, x, y + 1);
	if (!exit)
		free(popLS(stack));
	return exit;
}

int main (void)
{
/*	
	int map[MAX][MAX] = {
		{3, 0, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 4, 2},
		{2, 2, 2, 0, 2, 2, 2, 2},
		{2, 2, 2, 0, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 4, 2},
		{2, 0, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 0, 0},
		{2, 2, 2, 2, 2, 2, 2, 4}
	};
*/
	int map[MAX][MAX] = {
		{3, 0, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 4, 2},
		{2, 2, 2, 0, 2, 2, 2, 2},
		{2, 2, 2, 0, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 4, 2},
		{2, 0, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 0, 0},
		{2, 2, 2, 2, 2, 2, 2, 4}
	};
	LinkedStack *route = createLinkedStack();
	StackNode *tmp;
	go(map, route, 0, 0);
	int cnt = route->currentElementCount;
	for (int i = 0 ; i < cnt ; i++)
	{
		tmp = popLS(route);
		if (abs(tmp->x + tmp->y - (peekLS(route)->x + peekLS(route)->y)) <= 1)
			printf("(%d, %d) <- ", tmp->x, tmp->y);
		else
		{
			if (map[tmp->x - 1][tmp->y] == 1)
			{
				printf("(%d, %d) <- (%d, %d) <- 🤬 \n", tmp->x, tmp->y, tmp->x - 1, tmp->y);
				map[tmp->x - 1][tmp->y] = 9;
			}
			else if (map[tmp->x][tmp->y - 1] == 1)
			{
				printf("(%d, %d) <- (%d, %d) <- 🤬 \n", tmp->x, tmp->y, tmp->x, tmp->y - 1);
				map[tmp->x][tmp->y - 1] = 9;
			}
		}
		free(tmp);
	}
	printf("😀");
	printf("\n");
	for (int i = 0 ; i < MAX ; i++)
	{
		for (int j = 0 ; j < MAX ; j++)
		{
			if (map[i][j] == 9)
				printf("🤬");
			else
				printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}

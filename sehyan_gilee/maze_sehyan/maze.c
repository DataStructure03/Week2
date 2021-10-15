#include "maze.h"
#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

int myMaze[8][8] = {
	{0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0}
	};

int dir[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

void printMaze()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			printf("%d ", myMaze[i][j]);
		}
		printf("\n");
	}
}

void init_maze()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (myMaze[i][j] == 0)
				myMaze[i][j] = ROAD;
			else
				myMaze[i][j] = WALL;
		}
	}
	myMaze[0][0] = START;
	myMaze[7][7] = END;
}

void find_route(int x, int y, LinkedStack *stack)
{
	StackNode node;

	if (x < 0 || y < 0 || x > 7 || y > 7)
		return ;
	if (myMaze[x][y] != WALL && myMaze[x][y] != CHECK) {
		node.cur_x = x;
		node.cur_y = y;
		pushLS(stack, node);
		return ;
	} else {
		return ;
	}
}

int main()
{
	LinkedStack *stack = createLinkedStack();
	int x;
	int y;

	int START_POINT[2] = {0, 0};
	int END_POINT[2] = {7, 7};

	x = START_POINT[0];
	y = START_POINT[1];
	init_maze();
	printMaze();
	while (!(x == END_POINT[0] && y == END_POINT[1]))
	{
		find_route(x+1, y, stack);
		find_route(x, y+1, stack);
		find_route(x-1, y, stack);
		find_route(x, y-1, stack);

		if (isLinkedStackEmpty(stack) == TRUE)
			printf("ERROR\n");
		else {
			StackNode *n;
			n = popLS(stack);
			x = n->cur_x;
			y = n->cur_y;
			myMaze[x][y] = CHECK;
			free(n);
			printf("<%d, %d> - ", x, y);
		}
	}
	printf("\n");
	printMaze();
	return 0;
}
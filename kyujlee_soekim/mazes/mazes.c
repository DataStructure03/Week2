
#include <stdio.h>
#include "liststack.h"

#define WALL 1
#define VISITED 2

#define X 0
#define Y 1

#define MAZE_LENGTH 8

typedef struct map {
	int(*maze)[MAZE_LENGTH];
	int length;
	int height;
	Pos start;
	Pos exit;
}Map;


Pos dir[4] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0,1}
};

int samePos(Pos* pos1, Pos* pos2) {
	return (pos1->x == pos2->x && pos1->y == pos2->y);
}

Pos sumPos(Pos* toAdd1, Pos* toAdd2) {
	Pos sum;
	sum.x = toAdd1->x + toAdd2->x;
	sum.y = toAdd1->y + toAdd2->y;
	return sum;
}

void recordSolution(LinkedStack* sol, Pos* pos) {
	StackNode node;

	node.data = *pos;
	pushLS(sol, node);

}

int find(LinkedStack* sol, Map* map, Pos here) {

	if (here.x >= map->length || here.x < 0 ||
		here.y >= map->height || here.y < 0 ||
		map->maze[here.y][here.x] == VISITED ||
		map->maze[here.y][here.x] == WALL)
		return false;


	map->maze[here.y][here.x] = VISITED;
	if (samePos(&(map->exit), &here))
	{
		recordSolution(sol, &here);
		return true;
	}


	for (int i = 0;i < 4; ++i) {
		if (find(sol, map, sumPos(&here, &dir[i])))
		{
			recordSolution(sol, &here);
			return true;
		}
	}
	map->maze[here.y][here.x] = 0;
	return false;
}

int main() {

	int maze[][MAZE_LENGTH] = {
	{0,  0,  1,  1,  1,  1,  1,  1},
	{1, 0,  0,  0,  0,  0,  0,  1},
	{1,  1,  1,  0,  1,  1,  1,  1},
	{1, 1,  1,  0,  1,  1,  1,  1},
	{1,  0,  0,  0,  0,  0,  0,  1},
	{1,  0,  1,  1,  1,  1,  1,  1},
	{1,  0,  0,  0,  0,  0,  0,  0},
	{1,  1,  1,  1,  1,  1,  1,  0}
	};
	Map  map;
	map.length = MAZE_LENGTH;
	map.height = 8;
	map.maze = maze;
	map.start.x = 0;
	map.start.y = 0;
	map.exit.x = 7;
	map.exit.y = 7;

	LinkedStack* solution = createLinkedStack();

	find(solution, &map, map.start);

	//print solution map
	for (int y = 0; y < map.height;++y) {
		for (int x = 0; x < map.length; ++x) {
			if (map.maze[y][x] == WALL)
				printf("%c", '#');
			else if (map.maze[y][x] == VISITED)
				printf("%c", 'O');
			else if (map.maze[y][x] == 0)
				printf(" ");
		}
		printf("\n");
	}
	printf("\n\n");

	//print solution position
	for (StackNode* toPrint = popLS(solution);
		toPrint;
		free(toPrint), toPrint = popLS(solution))
		printf("( %d , %d ) -> ", toPrint->data.x, toPrint->data.y);
	printf("Exited!\n");

	deleteLinkedStack(solution);
}
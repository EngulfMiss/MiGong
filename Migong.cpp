#include<iostream>
#include<cmath>
using namespace std;

void findway(int x, int y, int count, int **maze, int len);

int len = 0;
int min_num = INT_MAX;
int main()
{
	int **maze = NULL;
	cin >> len;
	maze = new int *[len];
	for (int i = 0; i < len; i++)
	{
		maze[i] = new int[len];
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cin >> maze[i][j];
		}
	}

	findway(1, 1, 0, maze, len);

	if (min_num == INT_MAX) {
		cout << "No way";
	}
	else {
		cout << min_num;
	}

	for (int i = 0; i < len; i++)
	{
		delete[] maze[i];
	}
	delete maze;
	return 0;
}


void findway(int x, int y, int count, int **maze, int len) {
	if (x == len - 2 && y == len - 2) {
		min_num = count < min_num ? count : min_num;
	}
	else {
		maze[x][y] = 1;
		if (maze[x+1][y] == 0) {
			findway(x + 1, y, count + 1, maze, len);
		}

		if (maze[x-1][y] == 0) {
			findway(x - 1, y, count + 1, maze, len);
		}

		if (maze[x][y+1] == 0) {
			findway(x, y + 1, count + 1, maze, len);
		}

		if (maze[x][y-1] == 0) {
			findway(x, y - 1, count + 1, maze, len);
		}
		maze[x][y] = 0;
	}
}
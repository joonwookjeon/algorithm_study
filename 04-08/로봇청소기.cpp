#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int map[51][51];
bool visit[51][51];
int N, M;
int r, c, d;
int result = 0;

int change_direction(int direction)
{
	if (direction == 0)
		return 3;
	else if (direction == 1)
		return 0;
	else if (direction == 2)
		return 1;
	else
		return 2;
}

//d 방향, 0은 북, 1은 동, 2는 남, 3은 서
void dfs(int y, int x, int direction)
{
	if (map[y][x] == 1)
	{
		return;
	}

	if (map[y][x] == 0 && visit[y][x] == false)
	{
		result++;
		visit[y][x] = true;
	}
	int dir = change_direction(direction);
	//d 방향, 0은 북, 1은 동, 2는 남, 3은 서
	for (int i = 0; i < 4; i++)
	{
		if (dir == 0)
		{
			if (map[y - 1][x] == 0 && visit[y - 1][x] == false)
			{
				dfs(y - 1, x, 0);
				return;
			}
			else if (map[y - 1][x] == 1 || visit[y - 1][x] == true)
			{
				if (i == 3)
					dir = 0;
				else
					dir = 3;
			}
		}		//d 방향, 0은 북, 1은 동, 2는 남, 3은 서
		else if (dir == 3)
		{
			if (map[y][x - 1] == 0 && visit[y][x - 1] == false)
			{
				dfs(y, x - 1, 3);
				return;
			}
			else if (map[y][x - 1] == 1 || visit[y][x - 1] == true)
			{
				if (i == 3)
					dir = 3;
				else
					dir = 2;
			}
		}
		//d 방향, 0은 북, 1은 동, 2는 남, 3은 서
		else if (dir == 2)
		{
			if (map[y + 1][x] == 0 && visit[y + 1][x] == false)
			{
				dfs(y + 1, x, 2);
				return;
			}
			else if (map[y + 1][x] == 1 || visit[y + 1][x] == true)
			{
				if (i == 3)
					dir = 2;
				else
					dir = 1;
			}
		}
		//d 방향, 0은 북, 1은 동, 2는 남, 3은 서
		else if (dir == 1)
		{
			if (map[y][x + 1] == 0 && visit[y][x + 1] == false)
			{
				dfs(y, x + 1, 1);
				return;
			}
			else if (map[y][x + 1] == 1 || visit[y][x + 1] == true)
			{
				if (i == 3)
					dir = 1;
				else
					dir = 0;
			}
		}
	}
	int back_y, back_x;
	//d 방향, 0은 북, 1은 동, 2는 남, 3은 서
	if (dir == 0)
	{
		back_y = y + 1;
		back_x = x;
	}
	else if (dir == 1)
	{
		back_y = y;
		back_x = x - 1;
	}
	else if (dir == 2)
	{
		back_y = y - 1;
		back_x = x;
	}
	else if (dir == 3)
	{
		back_y = y;
		back_x = x + 1;
	}
	dfs(back_y, back_x, dir);
	return;
}

int main(void)
{
	cin >> N >> M;
	cin >> r >> c >> d;
	memset(map, 0, sizeof(map));
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(r, c, d);

	printf("%d\n", result);

	system("pause");
	return 0;
}
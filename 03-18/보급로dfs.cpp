#include <iostream>
#include <algorithm>
#include <string.h>

//#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N;

int map[100][100];
bool visit[100][100];
int DP[100][100];
int result = 9999999;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y, int current)
{
	
	
	if (x == (N - 1) && y == (N - 1))
	{
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
		{
			continue;
		}
		if (current+map[nx][ny]<DP[nx][ny])
		{
			DP[nx][ny] = current + map[nx][ny];
			if (visit[nx][ny] == false)
			{
				visit[nx][ny] = true;
				dfs(nx, ny, current + map[nx][ny]);
				visit[nx][ny] = false;
			}
		}
	}
	
}

int main(void)
{
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc;i++)
	{
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
        memset(DP, 999999, sizeof(DP));
		result = 9999999;
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf("%1d", &map[j][k]);
			}
		}

		visit[0][0] = true;
		DP[0][0] = 0;
		dfs(0, 0, 0);
		printf("#%d %d\n", i, DP[N-1][N-1]);
	}
	return 0;
}
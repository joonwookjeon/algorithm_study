#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

int map[51][51];
bool change[51][51];
bool visit[51][51] = { false, };


int sum = 0;
int cnt = 0;
int N, L, R;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

vector<pair<int, int>> v;

void DFS(int x, int y)
{
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visit[nx][ny] || nx >= N || nx < 0 || ny >= N || ny < 0)
			continue;
		if (change[nx][ny] == true)
		{
			sum += map[nx][ny];
			cnt++;

			v.push_back(make_pair(nx, ny));
			DFS(nx, ny);
		}
	}
}

int main() 
{
	
	int result=0;
	cin >> N >> L >> R;

	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}


	while (true)
	{
		int true_cnt=0;
		
		

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				change[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visit[i][j] = false;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N-1; j++)
			{
				if (abs(map[i][j] - map[i][j + 1]) >= L && abs(map[i][j] - map[i][j + 1]) <= R)
				{
					change[i][j] = true;
					change[i][j + 1] = true;
				}
			}
		}

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (abs(map[i][j] - map[i + 1][j]) >= L && abs(map[i][j] - map[i + 1][j]) <= R)
				{
					change[i][j] = true;
					change[i + 1][j] = true;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (change[i][j] == true)
					true_cnt++;
			}
		}
		
		


		if (true_cnt == 0)
		{
			break;
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (change[i][j] == true && visit[i][j]==false)
				{
					sum = map[i][j];
					cnt++;
					v.push_back(make_pair(i, j));
					DFS(i, j);
					int avg = sum / cnt;

					for (int k = 0; k < v.size(); k++)
					{
						map[v[k].first][v[k].second] = avg;
					}

					v.clear();
					sum = 0;
					cnt = 0;
				}
			}
		}


		result++;
	}
	printf("%d\n", result);
	system("pause");
	return 0;
}
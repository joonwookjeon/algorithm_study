#include <iostream>
#include <queue>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N;

int map[100][100];
int DP[100][100];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs() {
	queue <pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx >= 0 && nx < N && ny < N) {
				if (DP[nx][ny] > DP[x][y] + map[nx][ny]) {
					DP[nx][ny] = DP[x][y] + map[nx][ny];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}



int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{

		memset(map, 0, sizeof(map));
		memset(DP, 9999, sizeof(DP));
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf_s("%1d", &map[j][k]);
			}
		}
		DP[0][0] = 0;
		bfs();

		printf("#%d %d\n", i, DP[N - 1][N - 1]);
	}
	return 0;
}
#include <iostream>
#include <stdlib.h>
using namespace std;



int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

int main ()
{
	int map[100][100];
	int num[7] = { 0, };
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) 
	{
		int move;
		cin >> move;

		int nx = x + dx[move];
		int ny = y + dy[move];
		x = nx, y = ny;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		{
			continue;
		}

		int temp = 0;
		if (move == 0)
		{
			temp = num[3];
			num[3] = num[1];
			num[1] = num[4];
			num[4] = num[6];
			num[6] = temp;
			
		}
		if (move == 1)
		{
			temp = num[1];
			num[1] = num[3];
			num[3] = num[6];
			num[6] = num[4];
			num[4] = temp;
		}
		if (move == 2)
		{
			temp = num[1];
			num[1] = num[5];
			num[5] = num[6];
			num[6] = num[2];
			num[2] = temp;
			
		}
		if (move == 3)
		{
			temp = num[1];
			num[1] = num[2];
			num[2] = num[6];
			num[6] = num[5];
			num[5] = temp;
		}
		if (map[nx][ny] == 0)
		{
			map[nx][ny] = num[6];
		}
		else {
			num[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << num[1] << endl;
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>

using namespace std;

int n, m, h;


bool map[100][100];
bool visit[100][100];

int result=9999;

bool line()
{
	for (int i = 1; i <= n; i++)
	{
		int cur_line = i;
		for (int j = 1; j <= h; j++)
		{
			if (map[j][cur_line] == true)
			{
				cur_line += 1;
			}
			else if (cur_line - 1 > 0 && map[j][cur_line - 1] == true)
			{
				cur_line -= 1;
			}
		}
		if (i == cur_line)
		{
			continue;
		}
		else
			return false;
	}
	return true;
}

void dfs(int row, int cnt)
{
	

	if (cnt > 3)
	{
		return;
	}

	if (result != 9999)
		return;
	if (line())
	{
		result = cnt;
		return;
	}
	for (int i = row; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (map[i][j] == false)
			{
				if (map[i][j - 1] == false && map[i][j + 1] == false)
				{
					map[i][j] = true;
					dfs(i, cnt + 1);
					map[i][j] = false;
				}
			}
		}
	}
	return;
}

int main() {

	memset(map, false, sizeof(map));
	memset(visit, false, sizeof(visit));

	
	cin >> n >> m >> h;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = true;
	}

	dfs(1,0);
	if (result == 9999 || result > 3)
	{
		result = -1;
	}

	printf("%d\n", result);

	system("pause");
	return 0;
}
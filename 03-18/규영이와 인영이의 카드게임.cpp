#include <iostream>
#include <string.h>
using namespace std;

int kyu[9], inn[9];

bool visit[19];
bool visit2[19];

int kyu_win, inn_win;
int kyu_sum, inn_sum;

void dfs(int depth, int sum1, int sum2)
{
	if (depth == 9)
	{
		if (sum1 > sum2)
		{
			kyu_win++;
		}
		else if (sum1 < sum2)
		{
			inn_win++;
		}

		return;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (visit2[inn[i]] == false) 
			{
				visit2[inn[i]] = true;
				if (kyu[depth] > inn[i])
				{
					dfs(depth + 1, sum1 + kyu[depth] + inn[i], sum2);
				}
				else
				{
					dfs(depth + 1, sum1, sum2 + kyu[depth] + inn[i]);
				}
				visit2[inn[i]] = false;
			}
		}
	}

}


int main(void)
{
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		kyu_win = 0, inn_win = 0;
		memset(visit, false, sizeof(visit));
		
		for (int i = 0; i < 9; i++)
		{
			cin >> kyu[i];
			visit[kyu[i]] = true;
		}
		int idx = 0;
		for (int i = 1; i <= 18; i++)
		{
			if (visit[i] == false)
			{
				inn[idx] = i;
				idx++;
			}
		}

		dfs(0, 0, 0);
		printf("#%d %d %d\n", i, kyu_win, inn_win);
	}

	return 0;
}
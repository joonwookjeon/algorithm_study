#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
int N, M, sum, length;
vector <pair<int, int>> house;
vector <pair<int, int>> store1;

int map[100][100];
int visit[100];
int result = 9999;

void dfs(int store, int choice)
{
	if (choice == M)
	{
		sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			length = 9999;
			for (int j = 0; j < store1.size() ; j++)
			{
				if (visit[j])
				{
					int dis = abs(store1[i].first - house[j].first) + abs(store1[i].second - house[j].second);
					length = min(length, dis);
				}
			}
			sum += length;
		}
		result = min(result, sum);

		return;

	}
	if (store > store1.size())
		return;
	visit[store] = true;
	dfs(store + 1, choice + 1);
	visit[store] = false;
	dfs(store + 1, choice);
	
}

int main()
{
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				house.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2)
			{
				store1.push_back(make_pair(i, j));
			}

		}
	}

	dfs(0, 0);

	printf("%d\n", result);
	system("pause");
	return 0;
}


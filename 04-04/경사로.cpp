#include <iostream>
#include <stdlib.h>

using namespace std;

int N, L;

int result = 0;

int map[101][101];

int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	bool stair_visit[101];
	for (int i = 0; i < N; i++)
	{
		memset(stair_visit, false, sizeof(stair_visit));
		int height = map[i][0];
		bool row_result = true;
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == height)
			{
				continue;
			}
			else if (map[i][j] == (height - 1))
			{
				int cnt = L;
				int new_j = j;
				height = height - 1;
				while (cnt>0)
				{
					if (map[i][new_j] == height)
					{
						stair_visit[new_j] = true;
						cnt--;
						new_j++;
					}
					else 
					{
						row_result = false;
						break;
					}
				}
				if (row_result == false)
				{
					break;
				}
			}
			else if (map[i][j] == height + 1)
			{
				int cnt2 = L;
				int check_j = j-1;
				int check_height = height;
				while (cnt2 > 0)
				{
					if (!stair_visit[check_j] && map[i][check_j]==check_height)
					{
						cnt2--;
						stair_visit[check_j] = true;
						check_j--;
					}
					else
					{
						row_result = false;
						break;
					}
				}
				if (row_result == false)
				{
					break;
				}
				height = height + 1;
			}
			else {
				row_result = false;
			}

		}
		if (row_result == true)
		{
			result++;
		}
	}
	
	for (int j = 0; j < N; j++)
	{
		memset(stair_visit, false, sizeof(stair_visit));
		int height2 = map[0][j];
		bool col_result = true;
		for (int i = 0; i < N; i++)
		{
			if (map[i][j] == height2)
			{
				continue;
			}
			else if (map[i][j] == (height2 - 1))
			{
				int cnt3 = L;
				int new_i = i;
				height2 = height2 - 1;
				while (cnt3 > 0)
				{
					if (map[new_i][j] == height2)
					{
						stair_visit[new_i] = true;
						cnt3--;
						new_i++;
					}
					else
					{
						col_result = false;
						break;
					}
				}
				if (col_result == false)
				{
					break;
				}
			}
			else if (map[i][j] == height2 + 1)
			{
				int cnt4 = L;
				int check_i = i - 1;
				int check_height = height2;
				while (cnt4 > 0)
				{
					if (!stair_visit[check_i] && map[check_i][j] == check_height)
					{
						cnt4--;
						stair_visit[check_i] = true;
						check_i--;
					}
					else
					{
						col_result = false;
						break;
					}
				}
				if (col_result == false)
				{
					break;
				}
				height2 = height2 + 1;
			}
			else {
				col_result = false;
			}

		}
		if (col_result == true)
		{
			result++;
		}
	}
	
	cout << result << endl;
	

	system("pause");
	return 0;
}
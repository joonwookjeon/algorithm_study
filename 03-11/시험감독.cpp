#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int cnt=0;

int main(void) {
	int N;
	cin >> N;

	vector <int> place;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		place.push_back(num);
	}
	int main, sub;

	cin >> main >> sub;

	for (int i = 0; i < N; i++) {
		place[i] = place[i] - main;
		cnt++;
		if (place[i] <= 0)
		{
			continue;
		}
		else {
			while (place[i] > 0)
			{
				place[i] = place[i] - sub;
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	system("pause");
	return 0;

}
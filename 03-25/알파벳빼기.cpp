#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string a="";
		string b="";

		cin >> a;

		for (int i = 0; i < a.length(); i++)
		{
			if (a.at(i) == 'a' || a.at(i) == 'e' || a.at(i) == 'i' || a.at(i) == 'o' || a.at(i) == 'u')
			{
				continue;
			}
			else
			{
				b += a.at(i);
			}
		}
		cout << "#" << i << " " << b << endl;


	}

	return 0;

	

}
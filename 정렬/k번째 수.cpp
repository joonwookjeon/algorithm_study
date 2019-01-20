#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    int i, j, k;
    int size = commands.size();

    for (int s = 0; s < size; s++)
    {
        vector<int> choice;
        
        i = commands[s][0];
        j = commands[s][1];
        k = commands[s][2];
        
        int ii = i - 1;
        
        for (int a = 0; a <= j - i; a++)
        {
            choice.push_back(array[ii]);
            ii++;
        }
        
        sort(choice.begin(), choice.end());
        
        int b = choice[k - 1];
        answer.push_back(b);
    }
    return answer;
}



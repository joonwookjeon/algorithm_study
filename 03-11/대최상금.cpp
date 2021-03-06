#include <iostream>
#include <string>
 
 
using namespace std;
 
int cnt;
bool arr[1000000];
int max_depth[11];
 
void dfs(string num, int depth)
{
    int num1= stoi(num);
    if (max_depth[depth] > num1)
    {
        return;
    }
     
    if (depth == cnt)
    {
        arr[stoi(num)] = true;
        return;
    }
    max_depth[depth] = num1;
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            if (num[i] <= num[j]) {
                swap(num[i], num[j]);
                dfs(num, depth + 1);
                swap(num[i], num[j]);
            }
        }
    }
}
 
int main(void) {
    int testnum;
    cin >> testnum;
     
 
    for (int i = 1; i <= testnum; i++)
    {
        int result=0;
        for (int j = 0; j < 1000000; j++ ) {
            arr[j] = false;
        }
        for(int j=0;j<11; j++){
            max_depth[j]=0;
        }
 
        string s;
        cin >> s >> cnt;
 
 
        dfs(s, 0);
 
        for (int k = 999999; k >= 0; k--)
        {
            if (arr[k] == true)
            {
                result = k;
                break;
            }
        }
 
        printf("#%d %d\n", i, result);
 
    }
 
    return 0;
}
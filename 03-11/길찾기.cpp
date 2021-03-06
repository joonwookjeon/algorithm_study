#include <iostream>
 
using namespace std;
 
int A[100];
int B[100];
int result;
 
void dfs(int num)
{
    if (num == 99)
    {
        result = 1;
        return;
    }
    else
    {
        if(A[num] != -1)
            dfs(A[num]);
        if (B[num] != -1)
            dfs(B[num]);
    }
}
 
int main(void)
{
     
     
    for (int i = 1; i <= 10; i++)
    {
        result = 0;
        int cnt, n;
        for (int j = 0; j < 100; j++)
        {
            A[j] = -1;
            B[j] = -1;
        }
 
        cin >> cnt >> n;
 
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            if (A[a] == -1)
            {
                A[a] = b;
            }
            else
            {
                B[a] = b;
            }
 
        }
 
        dfs(0);
 
        printf("#%d %d\n", i, result);
    }
    return 0;
 
}
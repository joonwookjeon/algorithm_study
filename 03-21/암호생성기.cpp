#include <iostream>
#include <queue>
 
using namespace std;
 
queue <int> q;
int x, N, temp;
int main(void) {
     
    for (int i = 0; i < 10; i++)
    {
        cin >> N;
        for (int j = 0; j < 8; j++)
        {
            cin >> x;
            q.push(x);
        }
        int cnt=1;
        while (true)
        {
            temp = q.front();
            q.pop();
            if (temp - cnt <= 0)
            {
                temp = 0;
                q.push(temp);
                break;
            }
            else
            {
                q.push(temp - cnt);
            }
            cnt++;
            if (cnt == 6)
            {
                cnt = 1;
            }
 
        }
 
        printf("#%d ", N);
        while(!q.empty())
        {
            int num= q.front();
            printf("%d ", num);
            q.pop();
        }
        printf("\n");
    }
    return 0;
 
}
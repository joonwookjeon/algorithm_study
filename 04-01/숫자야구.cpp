#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

bool result[1000] ={true, };



void same_erase(int number)
{
    int x[3]={0,0,0};
    int num=number;
    for(int j=0; j<3; j++)
    {
        if(num%10==0)
        {
            result[number]=false;
            break;
        }
        else
        {
            x[j]=num%10;
            num=num/10;
        }
    }
    if(x[0]==x[1] || x[0]==x[2] || x[1]==x[2])
    {
        result[number]=false;
    }
    return;
}

bool game(int my, int com, int res_stk, int res_ball)
{
    int strike=0 , ball=0;
    int a[3]={0,0,0};
    int b[3]={0,0,0};
    int a_num=my;
    int b_num=com;
    for(int i=2; i>=0; i--)
    {
        a[i]=a_num%10;
        b[i]=b_num%10;
        a_num=a_num/10;
        b_num=b_num/10;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a[i]==b[j])
            {
                if(i==j)
                {
                    strike++;
                }
                else
                {
                    ball++;
                }
            }
                
        }
    }
    if(res_stk==strike && res_ball==ball)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    //cout << baseball[0][0] << endl;
    memset(result, true, sizeof(result));
    for(int i=100; i<1000; i++)
    {
        same_erase(i);
    }
    
    for(int i=100; i<1000;i++)
    {
        if(result[i]==false)
        {
            continue;
        }
        else
        {
            for(int j=0; j<baseball.size(); j++)
            {
                bool game_result=true;
                game_result=game(i, baseball[j][0],baseball[j][1],baseball[j][2]);
                if(game_result==false)
                {
                    result[i]=false;
                    break;
                }
            }
        }
    }
   
    
    for(int i=100; i<1000; i++)
    {
        if(result[i]==true)
        {
            cout << i << endl;
            answer++;
        }
    }
    return answer;
}
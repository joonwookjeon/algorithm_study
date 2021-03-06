#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool number[10000000]={false,};
bool visit[10000000]={false,};
int num_arr[10000000]={0,};
int num_length=0;
int answer=0;
bool isprime(int num)
{
    if(num==1)
        return false;
    else if(num==2)
        return true;
    bool flag =true;
    for(int i=2; i<=num-1; i++)
    {
        if(num%i == 0)
            flag=false;
    }
    return flag;
}

void dfs(int current,int cnt, int index)
{
    if(cnt==num_length)
        return;
    current=current*10;
    for(int i=0; i<num_length; i++)
    {
        if(visit[i]==true)
        {
            continue;
        }
        else
        {
            current= current+num_arr[i];
            if(isprime(current))
            {
                number[current]=true;
            }
            visit[i]=true;
            dfs(current, cnt+1, i);
            visit[i]=false;
        }
    }
    return;
}

int solution(string numbers) 
{
    answer = 0;
    
    num_length=numbers.length();
    for(int i=0; i<numbers.length(); i++)
    {
        int num1= numbers.at(i)-'0';
        num_arr[i]=num1;
    }
    for(int i=0; i<num_length; i++)
    {
        if(num_arr[i]==0)
            continue;
        else{
            if(number[num_arr[i]]==false)
            {
                if(isprime(num_arr[i]))
                   {
                       number[num_arr[i]]=true;
                   }
                visit[i]=true;
                dfs(num_arr[i], 1, i);
                visit[i]=false;
            }
        }
    }
    for(int i=0; i<10000000; i++){
        if(number[i]==true){
            cout << i << endl;
            answer++;
        }
    }               
   
    return answer;
}
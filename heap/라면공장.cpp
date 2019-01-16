#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional> // less<int>사용하기 위한 헤더임
using namespace std;


int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
 
 priority_queue<int, vector<int>, less<int>> tow;
 int answer = 0;
 int j = 0;
 
 for (int i = 0; i<k; i++) {
  if (dates[j] == i) {				//공급 날짜가 되면 priority_queue에 일단 넣는다. top은 가장 큰수
   temp.push(supplies[j]);
   if (j != supplies.size() - 1)
    j++;
  }
  //재고가 다 떨어지면 priority_queue에서 가장 큰 수를 꺼내 stock에 추가 시킨다.
  if (stock == 0)
  {
   stock += tow.top();
   tow.pop();
   answer++;
  }
  //매일 stock을 하나씩 감소 시킨다.
  stock--;

 }
 return answer;
}

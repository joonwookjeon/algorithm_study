#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional> // less<int>����ϱ� ���� �����
using namespace std;


int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
 
 priority_queue<int, vector<int>, less<int>> tow;
 int answer = 0;
 int j = 0;
 
 for (int i = 0; i<k; i++) {
  if (dates[j] == i) {				//���� ��¥�� �Ǹ� priority_queue�� �ϴ� �ִ´�. top�� ���� ū��
   temp.push(supplies[j]);
   if (j != supplies.size() - 1)
    j++;
  }
  //��� �� �������� priority_queue���� ���� ū ���� ���� stock�� �߰� ��Ų��.
  if (stock == 0)
  {
   stock += tow.top();
   tow.pop();
   answer++;
  }
  //���� stock�� �ϳ��� ���� ��Ų��.
  stock--;

 }
 return answer;
}

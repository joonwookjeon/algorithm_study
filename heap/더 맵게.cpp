#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer=0;
    int top1=0, top2=0;
    int cnt=0;
	
//top�� ���� ���� ���� ������ priority_queue�� ���� �ֱ�
    priority_queue <int, vector<int>, greater<int>> sol;
    for(int i=0; i<scoville.size();i++){
        sol.push(scoville[i]);
    }

 
    while (true){
//top1(���� ������) �� K���� ũ�� cnt ��ȯ
        top1=sol.top();
        if(top1>=K){
            answer=cnt;
            break;
        }
        sol.pop();
//priority queue�� ��� ������ -1��ȯ
        if(sol.empty()){
            answer = -1;
            break;
        }
//���� ���� ���� k���� ������ top1+2*top2�� queue�� ���� �ְ� ��� ���ö� ���� �ݺ�������
        else
        {
            top2=sol.top();
            sol.pop();
            sol.push(top1+2*top2);
            cnt++;
        }
    }
    
    
    return answer;
}
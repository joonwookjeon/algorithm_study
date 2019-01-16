#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer=0;
    int top1=0, top2=0;
    int cnt=0;
	
//top에 가장 작은 수가 오도록 priority_queue에 집어 넣기
    priority_queue <int, vector<int>, greater<int>> sol;
    for(int i=0; i<scoville.size();i++){
        sol.push(scoville[i]);
    }

 
    while (true){
//top1(가장 작은수) 가 K보다 크면 cnt 반환
        top1=sol.top();
        if(top1>=K){
            answer=cnt;
            break;
        }
        sol.pop();
//priority queue가 비어 있으면 -1반환
        if(sol.empty()){
            answer = -1;
            break;
        }
//가장 작은 수가 k보다 작으면 top1+2*top2를 queue에 집어 넣고 결과 나올때 까지 반복문실행
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
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    for(int i=0; i<progresses.size(); i++){
        int j=0;
        while(true){
            if((progresses[i]+(speeds[i]*j))>=100){
                days.push(j);
                break;
            }
            else
                j++;
        }
    }
    while(!days.empty()){
        int max=days.front();
        days.pop();
        int cnt=1;
        while(!days.empty()&&max>=days.front()){
            days.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
   
    return answer;
}
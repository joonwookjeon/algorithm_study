#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    while(true){
        bool prio = true;
        for(int i=1; i<priorities.size();i++){
            if(priorities[0]<priorities[i])
                prio=false;
        }
        if(prio==false){
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            if(location==0)
            {
                location=priorities.size()-1;
            }
            else{
                location=location-1;
            }
        }
        else{
            if(location==0){
                answer++;
                break;
            }
            else{
                priorities.erase(priorities.begin());
                answer++;
                location--;
            }
        }
    }
    
    return answer;
}
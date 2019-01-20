#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    for(int i=1; i<=red; i++){
        if(red%i!=0){
            continue;
        }
        int j= red/i;
        if(2*i+2*j+4==brown){
            if(i>j){
                answer.push_back(i+2);
                answer.push_back(j+2);    
            }
            else{
                answer.push_back(j+2);
                answer.push_back(i+2);
            }
            
            break;
        }
    }
    
    
    return answer;
}
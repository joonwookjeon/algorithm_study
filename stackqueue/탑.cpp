#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    for(int i = heights.size()-1; i>=0; i--){
        int result=0;
        for(int j=i-1; j>=0; j--){
            if(heights[j]>heights[i])
            {
                result=j+1;
                break;
            }
        }
        answer.push_back(result);
        
    }
    reverse(answer.begin(),answer.end());
    
    return answer;
}
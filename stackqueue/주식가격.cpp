#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=prices.size()-1; i>=0 ;i--){
        int cnt=0;
        for(int j=i+1; j<=prices.size()-1;j++){
            cnt++;
            if(prices[i]>prices[j]){
                break;
            }
        }
        answer.push_back(cnt);
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}
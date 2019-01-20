#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    int h=0;
    for(int i=citations.size()-1; i>=0; i--){
        if(citations[i]>=h+1)
            h++;
    }
    answer=h;
    return answer;
}
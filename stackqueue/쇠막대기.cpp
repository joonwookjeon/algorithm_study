#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
    vector <char> stick;
    int answer=0;
    int result=0;
    for(int i=0; i<arrangement.length(); i++){
        if(arrangement[i]=='(')
            stick.push_back(arrangement[i]);
        else{
            stick.erase(stick.begin()+stick.size()-1);
            if(arrangement[i-1]=='(')
                result=result+stick.size();
            else
                result++;
        }
    }
    answer=result;
    return answer;
}
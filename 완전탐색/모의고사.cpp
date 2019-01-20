#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one={1,2,3,4,5};
    vector<int> two={2,1,2,3,2,4,2,5};
    vector<int> three={3,3,1,1,2,2,4,4,5,5};
    int num1=0, num2=0, num3=0;
    int maximum=0;
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==one[i%5]){
            num1++;
        }
    }
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==two[i%8]){
            num2++;
        }
    }
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==three[i%10]){
            num3++;
        }
    }
    maximum=max(num1,max(num2,num3));
    if(num1==maximum)
        answer.push_back(1);
    if(num2==maximum)
        answer.push_back(2);
    if(num3==maximum)
        answer.push_back(3);
    return answer;
}
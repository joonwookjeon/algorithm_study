#include <string>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;

// 소수인지 판별하는 함수 
bool isPrime(int number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
 
    bool isPrime = true;
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number% i == 0)
            return false;
    }
 
    return isPrime;
}

//문자 비교 (string을 가장 큰 수로 정렬하기 위한 용도) 
bool compare(char a, char b)
{
    return a > b;
}
 
int solution(string numbers) {
    int answer = 0;
 
    string temp;
    temp = numbers;
 //temp 에서 가장 큰 수가 나오도록 정렬 ex) 1537 =>7531
    sort(temp.begin(), temp.end(), compare);
 //stoi 는 문자열을 정수로 변환
    vector<bool> prime(std::stoi(temp) + 1);
 
    prime[0] = false;
// 1부터 temp 까지 소수배열로 만들어 놓고 소수인지를 판별   
   for (long long i = 1; i < prime.size(); i++)
    {
        prime[i] = isPrime(i);
    }
    string s, sub;
 
    s = numbers;
 
//정렬 ex) 1537 =>1357	
    sort(s.begin(), s.end());
//중복 제거하기 위해 set 사용
    set<int> primes;
    int l = s.size();
    do {
        for (int i = 1; i <= l; i++)
        {
            sub = s.substr(0, i);
//소수가 맞으면 primes set에 넣는다. 중복되는 것이 있으면 set이 제거
            if (prime[std::stoi(sub)]) {
                primes.insert(std::stoi(sub));
            }
        }
//next_permutation 함수가 모든 경우의 수를 다 따져준다.
    } while (next_permutation(s.begin(), s.end()));
 
    answer = primes.size();
    return answer;
}

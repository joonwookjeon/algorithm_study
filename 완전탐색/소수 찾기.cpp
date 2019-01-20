#include <string>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;

// �Ҽ����� �Ǻ��ϴ� �Լ� 
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

//���� �� (string�� ���� ū ���� �����ϱ� ���� �뵵) 
bool compare(char a, char b)
{
    return a > b;
}
 
int solution(string numbers) {
    int answer = 0;
 
    string temp;
    temp = numbers;
 //temp ���� ���� ū ���� �������� ���� ex) 1537 =>7531
    sort(temp.begin(), temp.end(), compare);
 //stoi �� ���ڿ��� ������ ��ȯ
    vector<bool> prime(std::stoi(temp) + 1);
 
    prime[0] = false;
// 1���� temp ���� �Ҽ��迭�� ����� ���� �Ҽ������� �Ǻ�   
   for (long long i = 1; i < prime.size(); i++)
    {
        prime[i] = isPrime(i);
    }
    string s, sub;
 
    s = numbers;
 
//���� ex) 1537 =>1357	
    sort(s.begin(), s.end());
//�ߺ� �����ϱ� ���� set ���
    set<int> primes;
    int l = s.size();
    do {
        for (int i = 1; i <= l; i++)
        {
            sub = s.substr(0, i);
//�Ҽ��� ������ primes set�� �ִ´�. �ߺ��Ǵ� ���� ������ set�� ����
            if (prime[std::stoi(sub)]) {
                primes.insert(std::stoi(sub));
            }
        }
//next_permutation �Լ��� ��� ����� ���� �� �����ش�.
    } while (next_permutation(s.begin(), s.end()));
 
    answer = primes.size();
    return answer;
}

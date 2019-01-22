
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
string solution(string number, int k) {
    string answer = "";

    if (number.size() == 1)
        answer = number;


    bool b = false;


    do
    {
        b = false;
        for (int i = 0; i < number.size() - 1; i++)
        {
            if (k == 0)
                break;
            if (number[i] < number[i + 1])
            {
                number.erase(i, 1);

                i=-1;
                k--;
                b = true;
            }
        }
    } while (b == true && k > 0);



    while (k>0)
    {
        number.erase(number.size()-1);
        k--;
    }
    answer = number;
    return answer;
}

 
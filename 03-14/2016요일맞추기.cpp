#include <iostream>
 
int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
 
using namespace std;
 
int main(void)
{
    int tc;
    cin >> tc;
 
    for (int i = 1; i <= tc; i++)
    {
        int mon, day;
        int day_total=0;
        int result;
         
        cin >> mon >> day;
 
        if (mon == 1)
        {
            day_total = day ;
        }
        else
        {
            for (int j = 0; j < mon - 1; j++)
            {
                day_total += month[j];
            }
            day_total += day;
 
        }
 
        if (day_total % 7 == 1)
        {
            result = 4;
        }
        else if (day_total % 7 == 2)
        {
            result = 5;
        }
        else if (day_total % 7 == 3)
        {
            result = 6;
        }
        else if (day_total % 7 == 4)
        {
            result = 0;
        }
        else if (day_total % 7 == 5)
        {
            result = 1;
        }
        else if (day_total % 7 == 6)
        {
            result = 2;
        }
        else
        {
            result = 3;
        }
 
        printf("#%d %d\n", i, result);
 
    }
 
 
    return 0;
}
JAN

ABCDEFGHIJKLMNOPQRST

9+9+5

9+5+9+


¸Þ¸ðÀå

AAA


2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48

 #include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string name) {
    int answer = 0;
    map<char,int> m;
    m['A']=0;
    m['B']=1;
    m['C']=2;
    m['D']=3;
    m['E']=4;
    m['F']=5;
    m['G']=6;
    m['H']=7;
    m['I']=8;
    m['J']=9;
    m['K']=10;
    m['L']=11;
    m['M']=12;
    m['N']=13;
    m['O']=12;
    m['P']=11;
    m['Q']=10;
    m['R']=9;
    m['S']=8;
    m['T']=7;
    m['U']=6;
    m['V']=5;
    m['W']=4;
    m['X']=3;
    m['Y']=2;
    m['Z']=1;
    int a_count=0;
    for(int i=1;i<name.length();i++){
        if(name[i]!='A')
            break;
        a_count++;
    }
    for(int i=0;i<name.length();i++){
        answer+=m[name[i]];
    }
    answer+=name.length()-1-a_count;
    return answer;
}

 
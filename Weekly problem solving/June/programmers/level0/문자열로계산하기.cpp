#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

int solution(string my_string)
{
    int answer = 0;
    string input;

    queue<int> q;
    stack<int> s;
    bool op = true;
    
    for (int i = 0; i < my_string.length(); i++)
    {

        if (my_string[i] != '+' && my_string[i] != '-' && my_string[i] != ' ')
        {
            input += my_string[i];
        }
        else
        {
            s.push(stoi(input));
            if (my_string[i] == '+')
            {
                op = true;
                input = "";
            }
            else if (my_string[i] == '-')
            {
                op = false;
                input = "";
            }
        };
        if (s.size() >= 2)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (op)
            {
                answer += b + a;
                s.push(answer);
            }
            else
            {
                answer += b - a;
                s.push(answer);
            }
        }
    }

    return answer;
}

int main(){

    string m = "3 + 4 - 5";
    int ans;
    ans = solution(m);
    cout << ans << endl;
}
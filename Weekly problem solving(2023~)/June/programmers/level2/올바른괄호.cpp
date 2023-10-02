#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                char cur = st.top();
                st.pop();
            }
            else
            {
                answer = false;
                return answer;
            }
        }
    };

    if (!st.empty())
    {
        answer = false;
    }
    else
    {
        answer = true;
    }

    return answer;
}
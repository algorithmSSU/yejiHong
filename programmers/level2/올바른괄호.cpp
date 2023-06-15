#include <string>
#include <iostream>
#include <stack>

using namespace std;
bool solution(string s);
int main()
{

    string text = "()()";

    cout << solution(text) << endl;
};
bool solution(string s)
{
    stack<char> st;
    bool answer = true;
    int x = 0;
    int y = 0;
    int check;
    for (int i = 0; i < s.length(); i++)
    {
        char temp = s[i];
        if (temp == '(')
        {
            st.push('(');
            x++;
        }
        else
        {
            
            if (st.empty() || st.top() != '(')
            {
                answer = false;
            }
            else
            {
                st.pop();
                y++;
            };
        };
    };
    check = x - y;
    cout << x << y <<check << endl;
    if (check == 0)
    {
        answer = true;
    }
    else
    {
        answer = false;
    }
    return answer;
}
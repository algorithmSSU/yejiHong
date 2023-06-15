#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "";
    stack<string> s1;
    stack<string> s2;
    stack<string> s3;
    for (int i = cards1.size() - 1; i >= 0; i--)
    {
        s1.push(cards1[i]);
    };

    for (int i = cards2.size() - 1; i >= 0; i--)
    {
        s2.push(cards2[i]);
    };

    for (int i = goal.size() - 1; i >= 0; i--)
    {
        s3.push(goal[i]);
    }

    int t = goal.size();
    while (!s3.empty())
    {

        if (!s1.empty() && !s3.empty() && s1.top() == s3.top())
        {
            s3.pop();
            s1.pop();
        }
        else if (!s2.empty() && !s3.empty() && s2.top() == s3.top())
        {
            s3.pop();
            s2.pop();
        }
        else
        {
            answer = "No";
            return answer;
        }
    }

    answer = "Yes";

    return answer;
}
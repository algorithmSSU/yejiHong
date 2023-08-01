#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    map<char, int> m;

    for (int i = 0; i < s.length(); i++)
    {
        if (m.find(s[i]) == m.end())
        {
            m[s[i]] = i;
            answer.emplace_back(-1);
        }
        else
        {
            int diff = i - m[s[i]];
            answer.emplace_back(diff);
            m[s[i]] = i;
        }
    };

    return answer;
}
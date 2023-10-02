#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string before, string after)
{
    int answer = 1;
    map<char, int> m;

    for (int i = 0; i < before.length(); i++)
    {
        m[before[i]]++;
    };

    for (int j = 0; j < after.length(); j++)
    {
        if (m.find(after[j]) == m.end())
        {
            return 0;
        }
        else
        {
            if (m[after[j]] == 0)
            {
                return 0;
            }
            else
            {
                m[after[j]]--;
            }
        }
    }
    return answer;
}
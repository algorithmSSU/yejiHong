#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;

    map<string, int> m1;
    map<int, string> m2;

    for (int i = 0; i < players.size(); i++)
    {
        m1[players[i]] = i;
        m2[i] = players[i];
    };

    for (int i = 0; i < callings.size(); i++)
    {
        int call_idx = m1[callings[i]];
        string change = m2[call_idx - 1];
        m1[change] = call_idx;
        m1[callings[i]]--; // 호출되었으니 앞으로갓!
        m2[call_idx] = change;
        m2[call_idx - 1] = callings[i];
    };

    for (int i = 0; i < m2.size(); i++)
    {
        answer.emplace_back(m2[i]);
    }

    return answer;
}
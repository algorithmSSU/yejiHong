#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> info;
    map<string, int>::iterator p;

    for (int i = 0; i < participant.size(); i++)
    {
        info[participant[i]]++;
    };

    for (int i = 0; i < completion.size(); i++)
    {
        auto it = info.find(completion[i]);
        it->second--;
    };
    for (p = info.begin(); p != info.end(); p++)
    {
        if (p->second != 0)
        {
            answer += p->first;
        }
    }

    // 0 인 거 찾기
    return answer;
}
https : // school.programmers.co.kr/learn/courses/30/lessons/178871#
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
        using namespace std;

map<string, int> call;
map<string, int>::iterator ptr;
vector<pair<int, string>> info;

void make_calling(vector<string> callings)
{
    for (int i = 0; i < callings.size(); i++)
    {
        call[callings[i]]++;
    }
}

void make_player(vector<string> players)
{
    for (int i = 0; i < players.size(); i++)
    {
        info.emplace_back(i, players[i]);
    }
}

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;

    make_calling(callings);
    make_player(players);

    for (ptr = call.begin(); ptr != call.end(); ptr++)
    {
        for (int j = 0; j < info.size(); j++)
        {
            if (ptr->first == info[j].second)
            {
                info[j].first -= ptr->second;
                // cout << info[j].first << endl;
                int idx = info[j].first;
            };
            for (int k = j - 1; k >= info[j].first; k--)
            {
                info[k].first++;
            }
        }
    }
    sort(info.begin(), info.end());
    for (int i = 0; i < info.size(); i++)
    {
        answer.emplace_back(info[i].second);
    }

    return answer;
}
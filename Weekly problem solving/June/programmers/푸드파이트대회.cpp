#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food)
{
    string answer = "";
    vector<pair<int, int>> source;

    for (int i = 1; i < food.size(); i++)
    {
        if (food[i] >= 2)
        {
            int recur = food[i] / 2;
            source.emplace_back(i, recur);
        }
    };
    string res = "";

    for (int i = 0; i < source.size(); i++)
    {
        for (int j = 0; j < source[i].second; j++)
        {
            res += source[i].first + '0';
        };
    };
    answer = res + '0';
    reverse(res.begin(), res.end());
    answer += res;

    return answer;
}
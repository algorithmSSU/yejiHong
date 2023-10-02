#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;

    vector<int> day;

    for (int i = 0; i < score.size(); i++)
    {
        day.emplace_back(score[i]);
        sort(day.begin(), day.end());
        reverse(day.begin(), day.end());
        if (i < k)
        {
            answer.emplace_back(day[i]);
        }
        else
        {
            answer.emplace_back(day[k - 1]);
        }
    }

    return answer;
}
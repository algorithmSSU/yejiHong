#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int size = progresses.size();

    reverse(progresses.begin(), progresses.end());
    reverse(speeds.begin(), speeds.end());

    while (!progresses.empty())
    {
        int pop_count = 0;
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        };
        while (progresses[progresses.size() - 1] >= 100)
        {
            pop_count++;
            progresses.pop_back();
        };
        if (pop_count != 0)
        {
            answer.emplace_back(pop_count);
        }
    }
    return answer;
}
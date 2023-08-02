#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 0;
    vector<int> measure;
    while (number != 0)
    {
        int target = number;
        int tcnt = 1;
        for (int i = 1; i <= target / 2; i++)
        {
            if (target % i == 0)
            {
                tcnt++;
            }
        }
        measure.emplace_back(tcnt);
        number--;
    };

    for (int i = 0; i < measure.size(); i++)
    {
        if (measure[i] > limit)
        {
            answer += power;
        }
        else
        {
            answer += measure[i];
        }
    }
    return answer;
}
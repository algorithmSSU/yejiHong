#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0;
    sort(numbers.begin(), numbers.end());

    int maxv = -100000001;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            int temp = numbers[i] * numbers[j];
            maxv = temp <= maxv ? maxv : temp;
        }
    }

    answer = maxv;

    return answer;
}
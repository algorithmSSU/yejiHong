#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> answer;

    int r = n;

    while (r--)
    {
        if (answer.empty())
        {
            answer.emplace_back(x);
        }
        else
        {
            long long int temp = answer.back();
            temp += x;
            answer.emplace_back(temp);
        }
    }

    return answer;
}
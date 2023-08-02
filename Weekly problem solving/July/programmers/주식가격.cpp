#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    int before = 0;
    int s = prices.size()-1;

    for (int i = 0; i < prices.size() - 1; i++)
    {
        bool ch = true;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] > prices[j])
            {
                answer.emplace_back(j - i);
                ch =false;
                break;
            }
        };
        if(ch){
            answer.emplace_back(s-i);
        }

    }
    answer.emplace_back(0);
    return answer;
}
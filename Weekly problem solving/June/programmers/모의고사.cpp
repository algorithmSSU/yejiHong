
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<vector<int>> pick{{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    int ans[3] = {0, 0, 0};

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == pick[0][i % 5])
        {
            ans[0]++;
        };
        if (answers[i] == pick[1][i % 8])
        {
            ans[1]++;
        };
        if (answers[i] == pick[2][i % 10])
        {
            ans[2]++;
        };
    };

    int maxv = 0;
    for (int i = 0; i < 3; i++)
    {
        maxv = maxv < ans[i] ? ans[i] : maxv;
    };

    for (int i = 0; i < 3; i++)
    {
        if (maxv == ans[i])
        {
            answer.emplace_back(i + 1);
        };
    }

    return answer;
};

int main(){

    vector<int> answers{0,1,2};
    vector<int> res;
    res= solution(answers);

    return 0;

};

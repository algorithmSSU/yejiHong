#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score)
{
    vector<int> answer;
    vector<pair<int, int>> avg;
    vector<pair<int, int>> test;
    for (int i = 0; i < score.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < score[i].size(); j++)
        {
            sum += score[i][j];
        };
        int tmp = sum / score[i].size();
        avg.emplace_back(tmp, i + 1);
    };

    sort(avg.begin(), avg.end());
    // reverse(avg.begin(),avg.end());

    for(int i=0;i<avg.size();i++){
        std::cout << avg[i].first<< avg[i].second << endl;
    }
    test.emplace_back(avg.back());
    avg.pop_back();
    int startidx = 0;
    while (!avg.empty())
    {
        if (test[startidx].first == avg.back().first)
        {
            avg.back().second = test[startidx].second;
            test.emplace_back(avg.back());
            
        }
        else
        {
            test.emplace_back(avg.back());
        };
        avg.pop_back();
        startidx++;
    };


    for(int i=0;i<test.size();i++){
        std::cout << test[i].first << " " << test[i].second << endl;
    }

    for (int i = 0; i < test.size(); i++)
    {
        answer.emplace_back(test[i].second);
    }
    // reverse(answer.begin(),answer.end());

    return answer;
}


int main(){
    vector<vector<int>> v = {{80,80}, 
    {70, 80},
     {30, 50}, 
     {90, 100}, 
     {100, 90}, 
     {100, 100}, 
     {10, 30}};
    
    vector<int> answer;
    answer = solution(v);
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    vector<pair<int, int> > p;
    vector<int>sa;
    sa = priorities;
    sort(sa.begin(), sa.end(), greater<int>());

    int start_idx = 0;
    int compare_idx = 0;

    for (int i = 0; i < priorities.size(); i++)
    {
        p.emplace_back(priorities[i], i);
    };

    int cnt = 0;
    while (!p.empty())
    {

        cnt++;
        for (int i = start_idx; i < p.size() + start_idx; i++)
        {
            if (i >= p.size())
            {
                i = i - p.size();
            }
            if (sa[compare_idx] == p[i].first)
            {
                if (p[i].second == location)
                {
                    answer = cnt;
                }
                p.erase(p.begin() + i);
                start_idx = i;
                compare_idx++;
                break;
            }
        }
    }

    return answer;
};

int main(){

}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cal_a(vector<int> v, int s)
{
    vector<int> pick;
    int start = 1;
    while (s--)
    {
        if (start <= 5)
        {
            pick.emplace_back(start);
            start++;
        }
        else
        {
            start = 1;
        }
    }
    return pick;
};
vector<int> cal_b(vector<int> v, int s)
{
    vector<int> pick = {2, 1, 2, 3, 4, 2, 5, 2};
    vector<int> ans;
    int start_idx = 0;

    while (s--)
    {
        if (start_idx <= pick.size())
        {
            ans.emplace_back(pick[start_idx]);
            start_idx++;
        }
        else
        {
            start_idx = 0;
        }
    }
    return ans;
};

vector<int> cal_c(vector<int> v, int s)
{
    vector<int> pick = {3, 3, 1, 1, 4, 4, 5, 5};
    int start_idx = 0;
    vector<int> ans;
    while (s--)
    {
        if (start_idx <= pick.size())
        {
            ans.emplace_back(pick[start_idx]);
            start_idx++;
        }
        else
        {
            start_idx = 0;
        }
    }
    return ans;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int size = answers.size();
    vector<int> a;
    vector<int> b;
    vector<int> c;

    a = cal_a(answers, size);
    b = cal_b(answers, size);
    c = cal_c(answers, size);

    return a;
};

int main(){

    vector<int>answer;
    vector<int> v ={1,2,3,4,5};
    answer = solution(v)
    
    
}
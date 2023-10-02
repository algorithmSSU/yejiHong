#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> rnk;
void make_rank()
{
    int score = 6;
    for (int i = 1; i <= 6; i++)
    {
        rnk[score] = i;
        score--;
    }
    rnk[0] = 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    make_rank();
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    int len = lottos.size();
    int same = 0;
    int zero = 0;

    // 0 counting
    zero = count(lottos.begin(), lottos.end(), 0);
    int startidx = zero != 0 ? zero : 0;
    for (int i = startidx; i < lottos.size(); i++)
    {
        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == win_nums[j])
            {
                same++;
            }
        }
    }

    answer.emplace_back(rnk[same + zero]);
    answer.emplace_back(rnk[same]);

    return answer;
};

int main(){


    
}
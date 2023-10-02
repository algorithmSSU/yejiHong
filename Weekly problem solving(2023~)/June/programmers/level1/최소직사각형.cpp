#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    vector<int> big;
    vector<int> small;

    for (int i = 0; i < sizes.size(); i++)
    {
        int maxval, minval = 0;
        maxval = sizes[i][0] < sizes[i][1] ? sizes[i][1] : sizes[i][0];
        minval = sizes[i][0] > sizes[i][1] ? sizes[i][1] : sizes[i][0];
        big.emplace_back(maxval);
        small.emplace_back(minval);
    }

    sort(big.begin(), big.end(), greater<int>());
    sort(small.begin(), small.end(), greater<int>());

    answer = big[0] * small[0];

    return answer;
}
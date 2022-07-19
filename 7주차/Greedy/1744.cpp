#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solution(priority_queue<int> q);

int n;
int result;
vector<int> positive;
vector<int> negative;
int zero_count;

int solution();

int p_size, n_size, z_size;

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp > 1)
        {
            positive.push_back(temp);
        }
        else if (temp == 1)
        {
            result += 1;
        }
        else if (temp == 0)
        {
            zero_count += 1;
        }
        else
        {
            negative.push_back(temp);
        }
    };

    cout << solution() << endl;
};

int solution()
{
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end(), less<int>());

    for (int i = 0; i < positive.size() - (positive.size() % 2); i += 2)
    {
        result += positive[i] * positive[i + 1];
    };

    if (positive.size() % 2 == 1)
    {
        result += positive.back();
    };

    for (int i = 0; i < negative.size() - (negative.size() % 2); i += 2)
    {
        result += negative[i] * negative[i + 1];
    };

    if (negative.size() % 2 == 1)
    {
        if (zero_count == 0)
        {
            result += negative.back();
        };
    };

    return result;
};
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
bool check[100000] = {
    false,
};
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < deliveries.size(); i++)
    {
        int d, p;
        d = deliveries[i];
        p = pickups[i];
        v.emplace_back(d, p);
    };

    int dest = v.size() - 1;
    int cur;
    long long cnt = 0;
    while (check[0] == false)
    {
        // int dest = v.size() - 1;

        int d = 0;
        int p = 0;
        // cout << dest << endl;
        cnt += dest + 1;
        // cout << "cnt:" << cnt << endl;
        for (int i = dest; i >= 0; i--)
        {

            d += v[i].first;
            // cout << "d:"<<  d << endl;
            if (d > cap)
            {
                for (int j = dest; j >= i + 1; j--)
                {
                    p += v[j].second;
                    // cout << "p:" << p << endl;
                    if (p <= cap)
                    {
                        // cout << "j:" << j << endl;
                        check[j] = true;
                        cur = j;
                    };
                };
                dest = cur - 1;
                d = 0;
                break;
            }
            else if (d == cap)
            {
                for (int j = dest; j >= i; j--)
                {
                    p += v[j].second;
                    // cout << "p:" << p << endl;
                    if (p <= cap)
                    {
                        // cout << "j:" << j << endl;
                        check[j] = true;
                        cur = j;
                    };
                };
                dest = cur - 1;
                d = 0;
                break;
            };
        };
    };

    // long long answer = -1;
    answer = cnt * 2; // 온만큼 돌아가니까-> *2
    return answer;
};

int main()
{
    long long answer;
    int cap = 4;
    int n = 5;
    vector<int> del = {1, 0, 3, 1, 2};
    vector<int> pick = {0, 3, 0, 4, 0};
    answer = solution(cap, n, del, pick);
    cout << answer << endl;
}
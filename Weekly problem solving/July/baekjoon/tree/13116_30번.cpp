#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    vector<int> answer;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        int a_n, b_n;
        int ans = 0;
        int record[1024] = {
            0,
        };

        cin >> a >> b;
        record[a] = 1;
        record[b] = 1;

        while (1)
        {
            // 대소비교.. 추가했더니 통과(조건을 좀 더 생각해보기)
            if (a > b)
            {
                a /= 2;
                if (record[a] == 1)
                {
                    ans = a;
                    break;
                }
                else
                {
                    record[a] = 1;
                }
            }
            else
            {
                b /= 2;
                if (record[b] == 1)
                {
                    ans = b;
                    break;
                }
                else
                {
                    record[b] = 1;
                }
            }
        }
        answer.emplace_back(ans * 10);
    };

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }
}
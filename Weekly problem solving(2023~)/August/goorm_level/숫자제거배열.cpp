#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;

    cin >> n >> k;
    int n_temp = n;

    string target = to_string(k);

    long long int cnt = 0;

    while (n--)
    {
        string number;
        cin >> number;

        for (int i = 0; i < number.length(); i++)
        {
            int same = 0;
            if (number[i] == target[0])
            {

                int t_idx = 0;
                int n_idx = i;
                same++;
                while (i != number.length() - 1 && number[++n_idx] == target[++t_idx])
                {
                    same++;
                    n_idx++;
                    t_idx++;
                }
                if (same == target.size())
                {
                    // cout << number << endl;
                    cnt++;
                    break;
                }
            }
        }
    }

    int answer = n_temp - cnt;
    cout << answer << '\n';
}
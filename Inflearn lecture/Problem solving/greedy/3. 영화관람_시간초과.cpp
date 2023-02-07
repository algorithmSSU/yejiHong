// 앙직아직
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
        if (i == 0)
        {
            res.push_back(0);
        }
        else
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (v[j] > temp)
                {
                    res.push_back(j + 1);
                    break;
                }
                else
                {
                    if (j == 0 && v[j] < temp)
                    {
                        res.push_back(0);
                    }
                }
            }
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
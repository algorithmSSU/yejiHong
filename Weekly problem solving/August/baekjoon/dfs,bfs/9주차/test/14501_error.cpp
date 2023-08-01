#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::pair;

vector<pair<int, int>> work;
vector<int> bene;
int benefit(pair<int, int> w, int index);
int n;

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p, b;
        cin >> p >> b;
        work.push_back(make_pair(p, b));
    };

    for (int i = 0; i < n; i++)
    {
        int result = benefit(work[i], i);
        // cout << "db: "<< i << endl;
        bene.push_back(result);
    };

    cout << max(bene.front(), bene.back());
};

int benefit(pair<int, int> w, int index)
{
    int Next_i;
    int Next = 0;
    int move = w.first;
    int benefit = w.second;
    int result;
    int p, b;

    while (move <= n - index)
    {
        int d = work[move].first;
        int db = work[move].second;
        int temp = move + d;

        if (temp <= n - index + 1)
        { // (5+1)6 <=11

            benefit += db;

            while (1)
            {
                if (temp == n - index)
                {
                    move++;
                    break;
                };
                p = work[temp].first;  // work[6].first = 2, work[7].first = 3
                b = work[temp].second; // work[6].second = 20
                                       // work[7].second = 30
                if (temp + p <= n + 1)
                { // 8<=11, 10<=11
                    if (Next < b)
                    {
                        Next = b;
                        Next_i = temp;
                    };
                    temp++;
                }
                else
                {
                    benefit += work[Next_i].second;
                    break;
                };
            };
            // benefit+= work[Next_i].second;
            // cout << work[Next_i].first << endl;
            // cout << "benefit: " << benefit << endl;
            result = benefit;
            move += work[Next_i].first; // Next_i;
        }
        else
        {
            break;
        };
    };
    return result;
};
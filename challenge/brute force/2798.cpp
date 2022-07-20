#include <iostream>
#include <vector>

using namespace std;

int N, M;
int main()
{

    cin >> N >> M;
    vector<int> number;

    int a, b, c;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        number.push_back(num);
    };

    int before = 100000;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int sum = number[i] + number[j] + number[k];
                int d = M - sum;
                if (d >= 0)
                {
                    if (before > d)
                    {
                        before = d;
                        a = i;
                        b = j;
                        c = k;
                    };
                }
            };
        };
    };

    cout << number[a] + number[b] + number[c] << endl;
};

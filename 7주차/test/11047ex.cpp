#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> myv;

    int N, K, g;
    cin >> N >> K;

    int i;
    for (i = 0; i < N; i++)
    {
        cin >> g;
        if (g < K)
        {
            myv.push_back(g);
        }
    }
    //현재 vector myv 에는 1 5 10 50 100 500 1000원이 각 충분한 양으로 들어있다.

    sort(myv.begin(), myv.end(),
         [](int s1, int s2)
         {
             if (s1 > s2)
             {
                 return true;
             }
             else
             {
                 return false;
             }
         });
    //현재 vector myv 에는 1000 500 100 50 10 5 1원이 각 충분한 양으로 들어있다.

    int sum = 0;
    int a = 0;
    int v;
    int remainder = 0; //나머지
    while (1)
    {
        if (N == 1)
        {
            sum = K / N;
            break;
        }
        else
        {
            v = K / myv[a]; // 만들어야 하는 값의 동전개수
            // cout << "중간확인용 v: " << v << endl;
            remainder = K % myv[a]; //위에서 만들고 남은 잔액
            // cout << "중간확인용 remainder: " << remainder << endl;
            sum = sum + v;
            a++;
            if (remainder == 0)
            {
                break;
            }
            K = remainder;
        }
    }
    cout << sum;

    return 0;
}
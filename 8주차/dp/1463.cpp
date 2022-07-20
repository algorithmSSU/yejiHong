#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1, 0); // 입력받은 n + 1 만큼의 크기로 셋팅, 0으로 초기화

    dp[1] = 0; // 연산필요없음
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        };
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    };

    cout << dp[n] << "\n";
};

/*

ex) 11
1: 0
2: 1
3: 1
4: 2
5: 3
6: 2
7: 3
8: 3
9: 2
10: 3
11: 4


앞에서 계산된 결과를 계속 사용한다.
2또는 3으로 나누어 떨어지지 않을 때는 (그냥 빼줌) 연산했으니 +1
dp[i]=dp[i-1]+1;


2로 나누어 떨어질 때는 -> 최소 값 계산(그냥 빼주었을 때, 나누어주었을 때)
dp[i] = min(dp[i],dp[i/2]+1);


3으로 나누어 떨어질 때는 -> 최소 값 계산(그냥 빼주었을 때, 나누어주었을 때)
dp[i] = min(dp[i],dp[i/3]+1);

*/
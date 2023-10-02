/*
계단 수 : 인접한 모든 자리의 차이가 1인 수
*/

#include <iostream>
#include <vector>

#define mod 1000000000
using namespace std;

int dp[101][10] = {0,}; // 일단 0으로 초기값 설정
int main()
{
    int n;
    cin >> n;

    /*1행*/
    /*길이가 1인 계단 수 갯수*/
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    /*2행~9행*/
    /*길이가 2인 계단 수 갯수*/
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) // 
                dp[i][0] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= mod;
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++) {
        result = (result + dp[n][i]) % mod;
    }
    cout << result << "\n";

    for (int i = 0; i < 10;i++){
        cout << dp[3][i] << " ";
    }

        return 0;
}


/*

2 4 6 8 10
12 14 16 18 20
...

N = 1
A = 9 (1,2,3,4,5,6,7,8,9)

N = 2
A = (1,0) (1,2) (2,1) (2,3) (3,2) (3,4) (4,3) (4,5)
    (5,4) (5,6) (6,5) (6,7) (7,6) (7,8) (8,7) (8,9) (9,8)
    17개


*/
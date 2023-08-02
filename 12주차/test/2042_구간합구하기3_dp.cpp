// dp 방식
// 메모리가 터져버림

#include <iostream>
#include <vector>

using namespace std;

#define MAX 10001

vector<int> num;
int dp[MAX][MAX];
vector<vector<int>> v;
int N, M, K;

void input();
void input()
{
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    };
};

void makedp();
void makedp()
{

    for (int i = 0; i < num.size(); i++)
    {
        dp[i][i] = num[i];
    };
    // dp[0][0] = num[0];
    // dp[0][1] = dp[0][0] + num[1];

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            dp[i][j] = dp[i][j - 1] + num[j];
            // cout << i << "," << j << " " << dp[i][j] << endl;
        };
    };

    /*
        for (int j = 0; j < num.size();j++){
            for (int k = 0; k < num.size();k++){
                cout << dp[j][k] << endl;
            }
        }

    */
};

void order(int a, int b, int c);
void order(int a, int b, int c)
{
    if (a == 1)
    {
        num[b - 1] = c;
    };
    makedp();
    if (a == 2)
    {
        cout << dp[b - 1][c - 1] << "\n";
    };
};
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    input();
    makedp();

    for (int i = 0; i < (M + K); i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        order(a, b, c);
    };
}
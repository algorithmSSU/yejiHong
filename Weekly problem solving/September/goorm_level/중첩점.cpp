#include <iostream>
#include <vector>

using namespace std;
long long int dp[2][109][109] = {
    0,
};
long long int n, m;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  // n : 정사각배열의 가로,세로

  for (int i = 0; i < m; ++i)
  {
    long long int row, col;
    char d;
    cin >> row >> col >> d; // x,y 좌표에 d방향으로 직선을 그릴 것이다.

    if (d == 'R')
    {
      for (int i = col; i <= n; ++i)
      {
        dp[0][row][i]++;
      }
    }
    else if (d == 'L')
    {
      for (int i = col; i > 0; --i)
      {
        dp[0][row][i]++;
      }
    }
    else if (d == 'D')
    {
      for (int i = row; i <= n; ++i)
      {
        dp[1][i][col]++;
      }
    }
    else if (d == 'U')
    {
      for (int i = row; i > 0; --i)
      {
        dp[1][i][col]++;
      }
    }
  }

  long long int answer = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      answer += 1LL * dp[0][i][j] * dp[1][i][j];
    }
  }

  cout << answer << '\n';
  return 0;
}
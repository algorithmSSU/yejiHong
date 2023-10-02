#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[51];
int main(){
  ios_base::sync_with_stdio(false);
  cin >> n;

  dp[1]=1;
  dp[2]=1;

  for(int i=3;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
  }

  cout << dp[n] << endl;

}
#include <iostream>
#include <vector>
using namespace std;


int dp[100001];

int main(){
  dp[3]=1;
  dp[5]=1;

  int n;
  cin >> n;

  for(int i=6;i<=30;i++){
    if(dp[i-3]){
      dp[i]=dp[i-3]+1;
    }
    if(dp[i-5]){// i-5 한값도 값이 있으면
      dp[i]=min(dp[i-5]+1,dp[i]);
    }
  }

  
  if(dp[n]){
    cout << dp[n] << endl;
  }else{
    cout << -1 << endl;
  }

}
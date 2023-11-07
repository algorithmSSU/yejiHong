#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int test_case;
  int T;

  cin >> T;

  int dp[10]={0,};

  for(test_case =1; test_case <=T; ++test_case){
    
    int num;
    cin >> num;

    dp[1] = 1;
    dp[2] = -1;

    for(int i=3; i<=num; i++){
      if(i%2 == 0){ //짝수면 뺀다
        dp[i] = dp[i-1]-i;
      }else if(i%2 == 1){ // 홀수면 더한다
        dp[i] = dp[i-1]+i;
      }
    }

    cout << "#" << test_case << " " << dp[num] << '\n';
  
  }
}
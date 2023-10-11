#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[1000004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;


    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i] = dp[i-2]+dp[i-1]%15746;
    }

    cout << dp[n] << endl;


}
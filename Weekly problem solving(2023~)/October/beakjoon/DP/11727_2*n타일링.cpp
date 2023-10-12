#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dp[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    dp[1]=1;
    dp[2]=3;
    dp[3]=5;
    dp[4]=11;
    
    for(int i=5;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]*2 % 10007;
    }

    cout << dp[n]% 10007 << endl;
}
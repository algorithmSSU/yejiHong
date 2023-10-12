#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[10001];
int wine[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;



    for(int i=1;i<=n;i++){
        cin >> wine[i];
    }

    dp[0]=0;
    dp[1]=wine[1];
    dp[2]=wine[1]+wine[2];

    for(int i=3; i<=n; i++){
        dp[i]=max(max(dp[i-3]+wine[i-1]+wine[i],dp[i-2]+wine[i]),dp[i-1]);
    }
    cout << dp[n] << endl;
}
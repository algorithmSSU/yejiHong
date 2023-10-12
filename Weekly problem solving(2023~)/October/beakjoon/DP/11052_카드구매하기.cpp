#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int card[100001];
int dp[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> card[i];
    }


    dp[0]=0;
    dp[1]=card[1];

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] = max(dp[i],dp[i-j]+card[j]);
        }
    }

    cout << dp[n] << endl;
    
}
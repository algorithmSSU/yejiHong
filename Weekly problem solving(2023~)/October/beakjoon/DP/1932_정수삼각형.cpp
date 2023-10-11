#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int tg[502][502];
int dp[502][502]={0,};
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n; 
    int answer;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> tg[i][j];
        }
    }

    dp[1][1]= tg[1][1];

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+tg[i][j];
        }
    }
    answer = -1e9;
    for(int i=1;i<=n;i++){
        answer = max(answer,dp[n][i]);
    }

    cout << answer << endl;

}
#include <iostream>
#include <algorithm>
using namespace std;


int dp[1001][4];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int answer = 1e9;

    cin >> n;

    cin >> dp[1][1];
    cin >> dp[1][2];
    cin >> dp[1][3];

    

    for(int i = 2; i<=n;i++){
        int pos1, pos2, pos3;
        cin >> pos1 >> pos2 >> pos3;
        dp[i][1] = min(dp[i-1][2],dp[i-1][3])+pos1;
        dp[i][2] = min(dp[i-1][1],dp[i-1][3])+pos2;
        dp[i][3] = min(dp[i-1][2],dp[i-1][1])+pos3;
    }
    
    for(int i=1;i<=3;i++){
        answer = min(dp[n][i],answer);
    }

    cout << answer << endl;

}
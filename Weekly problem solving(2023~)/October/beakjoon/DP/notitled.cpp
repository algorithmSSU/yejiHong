#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;

#define MAX 100006
long long sticker[2][MAX];
long long dp[2][MAX];
int T;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    vector<long long> v;

    while(T--){
        int n;
        
        memset(dp,0,sizeof(dp));
        cin >> n;
        for(int i=0;i<2;i++){
            for(int j=2;j<n+2;j++){
                cin >> sticker[i][j];
            }
        }

        dp[0][2] =sticker[0][2];
        dp[1][2] =sticker[1][2];


        for(int i =3;i<n+2;i++){
            dp[0][i]=max(dp[1][i-2],dp[1][i-1])+sticker[0][i];
            dp[1][i]=max(dp[0][i-2],dp[0][i-1])+sticker[1][i];
        }

        long long answer = max(dp[0][n+1],dp[1][n+1]);

        //cout << answer << endl;

        // for(int i=0;i<2;i++){
        //     for(int j=2;j<n+2;j++){
        //         cout << dp[i][j] << " ";
        //     };
        //     cout << '\n';
        // }

        v.emplace_back(answer);
    }

    for(auto it : v){
        cout << it << '\n';
    }



}
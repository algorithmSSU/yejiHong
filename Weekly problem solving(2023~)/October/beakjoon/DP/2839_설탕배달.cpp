#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[5001]={0,};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    dp[3]=1;
    dp[5]=1;

    for(int i=6;i<=n;i++){
        if(dp[i-3]){
            dp[i]=dp[i-3]+1;
        }
        if(dp[i-5]){
            dp[i]=dp[i-5]+1;
        }
    }

    if(!dp[n]){
        cout << -1 << endl;
    }else{
        cout << dp[n] << endl;
    }

    

}
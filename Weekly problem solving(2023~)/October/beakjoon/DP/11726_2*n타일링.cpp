#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int dp[10];

    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=9;i++){
        dp[i]=dp[i-1]+dp[i-2];
    };

    cout << dp[9] << endl;
}
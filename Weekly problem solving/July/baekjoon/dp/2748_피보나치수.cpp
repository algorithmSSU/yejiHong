#include <iostream>
#include <string>

using namespace std;


long long int dp[101]={0,};
int main(){

    int n;
    cin >> n;

    dp[0]=0;
    dp[1]=1;
    dp[2]=1;

    int i =3;
    while(i<=n){
        dp[i] = dp[i - 1] + dp[i - 2];
        i++;
    };

    cout << dp[n] << '\n';

}
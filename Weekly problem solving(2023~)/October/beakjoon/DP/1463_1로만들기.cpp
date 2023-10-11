#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    // bottom up

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1; // 빼기 연산 1 회 더해주기

        if(i%2 == 0){
            dp[i] = min(dp[i],dp[i/2]+1); // min(앞에서 구해놓은 연산 횟수, 나누기 연산 1회 더해주기)
        }
        if(i%3 == 0){
            dp[i] = min(dp[i],dp[i/3]+1);  // min(앞에서 구해놓은 연산 횟수, 나누기 연산 1회 더해주기)
        }
    }

    cout << dp[n] << endl;

    

    




}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[103];
long long dp[103];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // 갯수
    vector<int> l;
    int Max= 0;

    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        Max = max(Max,c);
        l.push_back(c);
    }

    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;

    for(int i=6;i<=Max;i++){
        dp[i]=dp[i-5]+dp[i-1];
    }
    
    for(auto it : l){
        cout << dp[it] << '\n';
    }

    

}
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int day[16];
int reward[16];
int dp[16];


int func();

int main(){
    cin >> n;

    for (int i = 0; i < n;i++){
        cin >> day[i] >> reward[i];
    };

    cout << func() << endl;

    
    for(int i=0;i<n;i++){
        cout << dp[i] << " ";
    };
    cout << "\n";
    

    return 0;

};

int func(){
    int ans = 0;

    for (int i = 0; i <= n;i++){
        dp[i] = max(dp[i], ans);
        
        if(day[i]+i<=n){
            dp[day[i] + i] = max(dp[day[i] + i], dp[i] + reward[i]);
        };
        ans = max(ans, dp[i]);
    };
    return ans;
};

/*

dp[1] = 20;
dp[6] = max(20,220)








*/
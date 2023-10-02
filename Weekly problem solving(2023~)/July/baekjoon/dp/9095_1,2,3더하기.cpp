#include <iostream>
#include <vector>

using namespace std;

int dp[1000]={0,};

int main(){
    int n;
    

    // 점화식 점화식 점화식 점화식!!!!! 
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;


    cin >> n;
    vector<int> ans;
    for(int j=0;j<n;j++){
        int num;
        cin >> num;
        for (int i = 4; i <= num; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        };

        //cout << dp[num] << '\n';
        ans.emplace_back(dp[num]);
        
    };

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << '\n';
    }

    
    

}
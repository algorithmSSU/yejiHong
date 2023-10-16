#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;


int sticker[3][100002];
int dp[3][100002];
int n;

int solution(int len){
    dp[1][1] = sticker[1][1];
    dp[2][1] = sticker[2][1];
    for(int i=2;i<=len;i++){
        dp[1][i]= max(dp[2][i-2],dp[2][i-1])+sticker[1][i];
        dp[2][i]= max(dp[1][i-2],dp[1][i-1])+sticker[2][i];
    }
    return max(dp[1][len],dp[2][len]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> answer;
    cin >> n;

    for(int i=0;i<n;i++){
        int temp = 0;
        int cols;
        cin >> cols;

        for(int y=1;y<=2;y++){
            for(int x=1;x<=cols;x++){
                cin >> sticker[y][x];
            }
        }
        temp = solution(cols);
        answer.emplace_back(temp);
        memset(dp,0,sizeof(dp));
    }

    for(auto it : answer){
        cout << it << endl;
    }


}
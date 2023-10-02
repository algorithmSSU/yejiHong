#include <iostream>
#include <vector>

using namespace std;


int dp[31][31];

int main(){
    cin.tie(0);

    vector<int> answer;
    ios_base::sync_with_stdio(false);



    // 패턴을 보니까 점화식을 세울 수 있었다.
    // dp[1][1] = 1
    // dp[1][2] = 2
    // dp[1][3] = 3

    for(int i=1;i<=30;i++){
        dp[1][i]=i;
    };


// 이부분은 다시 한번 더 보고 이해할 필요가 있음..
    for(int i=2;i<=30;i++){
        for(int j=i;j<=30;j++){
            for(int k=j-1;k>=1;k--){
                dp[i][j]+=dp[i-1][k];
            }
        }
    }

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        answer.emplace_back(dp[a][b]);
    }

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }
}
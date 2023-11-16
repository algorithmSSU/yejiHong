#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;
#define MAX 502
int N,M;
int Party[MAX][MAX];
bool visited[MAX];
vector<string> answer;

void floyd_washall(){
    for(int k =1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                int temp = Party[i][k] + Party[k][j];
                if(temp<Party[i][j]){
                    Party[i][j] = temp;
                }
            }
        }
    }
}

void solution(){
    cin >> N >> M; // 파티장의 크기, 손님의 수
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> Party[i][j];
        }
    }
    floyd_washall();

    for(int i =0;i<M;i++){
        int now,next,time;
        cin >> now >> next >> time;
        if(Party[now][next]<=time){
            answer.emplace_back("Enjoy other party");
        }else{
            answer.emplace_back("Stay here");
        }
    }

    for(auto ans : answer){
        cout << ans << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}
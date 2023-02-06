#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;


const int cap=8;
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};

int row,col,a[cap][cap];
int tmp[cap][cap];
int ans=0;
bool visited[cap][cap];

void copy(int a[cap][cap],int b[cap][cap]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            a[i][j] = b[i][j];
        }
    }
}
// 바이러스 확산 시킨 후 안전지역 카운팅
void bfs(){
    int virus[8][8];
    copy(virus,tmp);

    queue< pair<int, int> > q;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(virus[i][j]==2){
                q.push(make_pair(i,j)); // 바이러스 위치 모두 담고
            }
        }
    }

    while(q.size()){// 바이러스 담은 곳 모두 방문
        int y= q.front().first;
        int x= q.front().second;

        q.pop();

        for(int k=0;k<4;k++){
            int ny = y+dy[k];
            int nx = x+dx[k];
            
            if(ny<0 || ny>=row || nx<0|| nx>=col){
                continue;
            }
            if(virus[ny][nx]==0){ // 1:벽, 2:바이러스, 0:emprt place , 바이러스가 0공간까지 삼킴
                virus[ny][nx]=2;
                q.push(make_pair(ny,nx));
            }
        }
    }


    // 바이러스 확신 시키고 나서 안전지역 카운팅
    int cnt =0;
    for(int i=0;i<row;i++){
        for(int j =0;j<col;j++){
            if(virus[i][j]==0){
                cnt++;
            }
        }
    }
    ans = max(ans,cnt);

}

// 벽 세우기
void wall(int cur){ 
    if(cur==3){
        bfs();
        return;
    }

    for(int i=0; i<row;i++){
        for(int j =0;j<col;j++){
            if(tmp[i][j]==0){
                tmp[i][j]=1;
                wall(cur+1);
                tmp[i][j]=0;}
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]==0){
                memset(visited,0,sizeof(visited));
                copy(tmp,a);
                tmp[i][j]=1;
                wall(1);
                tmp[i][j]=0;
            };
        };
    
    };
    cout << ans;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int n,m;
int map[301][301]={0,};
int dy[4]={0,0,1,-1};
int dx[4]={-1,1,0,0};
bool visited[301][301]={0,};

void melt(int y,int x){
    int zero_cnt =0;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(map[ny][nx]==0){
            zero_cnt++;
        }
    }

    map[y][x]-=zero_cnt;
    if(map[y][x]<=0){
        map[y][x]=-1;
    }
    
}


int bfs(int y,int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    if(map[y][x]<0){
        return 0;
    }

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        visited[cy][cx]=true;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny>=0 && nx>=0 && ny<n && nx<m){
                if(!visited[ny][nx] && map[ny][nx]>0){
                    visited[ny][nx]=true;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
    return 1;
    
}


void print(int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }

    int lump = 0;
    int cnt = 0;
    while(1){
        cnt++;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]!=0){
                    melt(i,j); // 0 이 아닌 위치에서만 0과 맞닿은 부분만큼 녹도록
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j] && map[i][j]>0){
                    lump+=bfs(i,j);
                }
            }
        }
        
        // 다시 돌 때 visited 초기화
        for(int i=0;i<301;i++){
            memset(visited[i],0,sizeof(bool)*301);
        }
        
        if(lump==0){
            cnt = 0;
            break;

        }else if(lump>=2){
            break;
        }
        lump = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]==-1){
                    map[i][j]=0;
                }
            }
        }
    }

    cout << cnt << '\n';






}
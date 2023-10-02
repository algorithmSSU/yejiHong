#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>


using namespace std;

char map[51][51]; // 전체 맵
int visited[51][51]={0,}; // 최단 거리 체크용(거리기록해서 비교)
bool visit[51][51]={false,}; // 방문 체크용
int r,c;
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};



int bfs(int y,int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    int cost = 0;
    visit[y][x]=true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        
        q.pop();


        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny>=0 && nx>=0 && ny<r && nx<c){
                if(!visited[ny][nx] && map[ny][nx]=='L'&& !visit[ny][nx]){
                    visit[ny][nx]=true;
                    visited[ny][nx]=visited[cy][cx]+1;
                    cost = max(cost,visited[ny][nx]);
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
    return cost;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;

    for(int i=0;i<r;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            map[i][j]=str[j];
        }
    }

    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i][j]=='L'){
                int temp=bfs(i,j);
                ans = ans < temp ? temp : ans;
                // 모든 지점 다시 원복
                memset(visited,0,sizeof(visited));
                memset(visit,0,sizeof(visit));
                
            }
        }
    }

    cout << ans << '\n';

}
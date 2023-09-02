#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[1001][1001]={0,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int n,m;

//최단경로 -> bfs 이용
//1step 마다 상/하/좌/우 동등탐색 -> 최대 4가지의 경로 발생
//벽 뿌심? 벽 뿌시지 않음? 에 따라 구분해서 cost 가 달라지므로


int bfs(){
    bool visited[1001][1001][2]; // [y][x][벽 뿌셨는지 체크]
    visited[0][0][0]=true;
    visited[0][0][1]=true;
    queue<pair<pair<int,int>, pair<int,int> > > q;
    q.push(make_pair(make_pair(0,0),make_pair(0,1)));// 0,0 지점에서 벽이 아닌, cost=1로 주고
    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int wall = q.front().second.first;
        int cost = q.front().second.second;

        q.pop();

        // 도착지점 도착하면 지금까지 누적된 cost return 
        if(cy==n-1 && cx==m-1){
            return cost;
        }

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny>=0 && nx>=0 && ny<n && nx<m){
                if(!visited[ny][nx][wall]){
                    //벽을 아직 부순적이 없고, 벽이 아니라 일반 길일때
                    if(wall==0 && map[ny][nx]==0){
                        visited[ny][nx][wall]=true;
                        q.push(make_pair(make_pair(ny,nx),make_pair(0,cost+1)));
                    // 벽을 아직 부순적이 없고, 벽일때
                    }else if(wall==0 && map[ny][nx]==1){
                        visited[ny][nx][wall]=true;
                        q.push(make_pair(make_pair(ny,nx),make_pair(1,cost+1)));
                    // 벽을 부쉰적이 있고, 벽이 아닐 때
                    }else if(wall==1 && map[ny][nx]==0){
                        visited[ny][nx][wall]=true;
                        q.push(make_pair(make_pair(ny,nx),make_pair(1,cost+1)));
                    // 벽을 부순적이 있고, 벽일 때 -> 이미 한번 부셨기 때문에 부수지 못함
                    }else if(wall==1 && map[ny][nx]==1){
                        //do nothing
                    }
                }
            }
        }
    }
    return -1;

}

int main(){
    
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    
    cin >> n >> m;

    for(int i=0;i<n;i++){
        string text;
        cin >> text;
        for(int j=0;j<text.length();j++){
            map[i][j]=text[j]-'0';
        }
    }

    cout << bfs() << '\n';



}
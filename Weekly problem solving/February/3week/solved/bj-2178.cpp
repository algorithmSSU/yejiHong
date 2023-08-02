#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define SIZE 100
int N,M;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int m[SIZE][SIZE]={0,};
int visited[SIZE][SIZE]={0,};
int dist[SIZE][SIZE]={0,};

void bfs(){
    queue< pair<int ,int> >q;
    visited[0][0]=1;
    dist[0][0]=1;
    q.push(make_pair(0,0));

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int i=0; i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny<0||ny>=N||nx<0||nx>=M){
                continue;
            }
            if(visited[ny][nx]==0 && m[ny][nx]==1){
                visited[ny][nx]=1;
                dist[ny][nx]+=dist[cy][cx]+1;
                q.push(make_pair(ny,nx));
            }
        }
    }

};


void print(int a,int b){
    int y = a-1;
    int x = b-1;
    cout << dist[y][x] << endl;
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c;
            cin >>c;
            if(c=='0'){
                m[i][j]=0;
            }else{
                m[i][j]=1;
            }
        }
    }
    

    bfs();
    print(N,M);
    return 0;
}
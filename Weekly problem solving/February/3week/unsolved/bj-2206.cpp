// 시간초과
// 접근법 다시 생각해보기
// https://www.acmicpc.net/board/view/27386

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_SIZE 1001

int map[MAX_SIZE][MAX_SIZE] ={0,};
int m[MAX_SIZE][MAX_SIZE] = {0,};
int visited[MAX_SIZE][MAX_SIZE]={0,};
//int dist[MAX_SIZE][MAX_SIZE]={0,};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
vector<int> goal_dist;
int N, M;


void bfs(){

    queue <pair <int, int> > q;
    int dist[MAX_SIZE][MAX_SIZE]={0,};
    q.push(make_pair(0,0));
    visited[0][0] = 1;
    dist[0][0]=1;
    int count = 0;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;

        q.pop();

        if(cy==N-1 && cx==M-1){
            goal_dist.push_back(dist[cy][cx]);
        }

        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny<0 || ny >=N || nx<0 || nx>=M)
                continue;
            if(m[ny][nx]==0 && visited[ny][nx]==0){
                dist[ny][nx] = dist[cy][cx]+1;
                //cout << "ny:" << ny << "nx:" << nx << endl;
                
                visited[ny][nx]=1;
                q.push(make_pair(ny,nx));
            }
        }
    }
}
void print(int y,int x){
    for(int i=0;i<y;i++){
        cout << "\n";
        for(int j=0;j<x;j++){
            cout << map[i][j];
        }
    }
}

void copy(int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            m[i][j] = map[i][j];
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    string str;
    vector< pair<int, int> > wall;
    for(int i=0;i<N;i++){
        cin >> str;
        int temp =str.size();
        for(int j=0;j<temp;j++){
            if(str[j]=='0'){
                map[i][j] = 0;
            }else{
                map[i][j] = 1;
                wall.emplace_back(i,j);
            }
        }
    }

    if(wall.size()==0){
        bfs();

        
    }else{
        copy(N, M); // 사본 만들어놓고
        int tmp = wall.size();
        for (int i = 0; i < tmp; i++)
        {
            int y = wall[i].first;
            int x = wall[i].second;
            // cout << y << "," << x << endl;

            m[y][x] = 0;
            bfs();
            copy(N, M);
            for (int i = 0; i < N; i++)
            {
                memset(visited[i], 0, sizeof(int) * M);
            }
        };
    };
    if (goal_dist.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        sort(goal_dist.begin(), goal_dist.end());

        cout << goal_dist[0] << endl;
    }

    return 0;


    //print(N,M);
    

}
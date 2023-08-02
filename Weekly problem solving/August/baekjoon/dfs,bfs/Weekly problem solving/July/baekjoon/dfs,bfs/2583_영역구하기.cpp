#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, K;
int map[101][101];
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
vector<pair<int, int> > coordinate[101];
bool visited[101][101]={false,};

int bfs(int y,int x){
    int cnt = 1;
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        visited[cy][cx]=true;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny>=0 && nx>=0 && ny<M && nx<N){
                if(!visited[ny][nx] && map[ny][nx]==0){
                    cnt++;
                    visited[ny][nx]=true;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
    return cnt;
}

int main(){
    cin >> M >> N >> K;

    

    for(int i=0;i<K;i++){
        int y1,x1,y2,x2;
        cin >> x1 >> y1 >> x2 >> y2;
        //--x2;
        //--y2;

        for(int i=y1;i<y2;i++){
            for(int j=x1;j<x2;j++){
                map[i][j]=1;
            }
        }
    }

    vector<int> answer;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j] && map[i][j]!=1){
                int temp = bfs(i,j);
                answer.emplace_back(temp);
            }
        }
    }


    sort(answer.begin(),answer.end(),less<int>());


    cout << answer.size() << '\n';
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << " ";
    }
    cout << '\n';



    
}
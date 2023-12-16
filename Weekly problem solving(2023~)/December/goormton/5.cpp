#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n;
int MAP[1001][1001];

void input(){
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> MAP[i][j];
    }
  }
}

int dy[4]= {0,0,-1,1};
int dx[4]= {-1,1,0,0};
bool visited[1001][1001]={false,};

int bfs(int y,int x){
  queue<pair<int,int>> q;
  int con = 1;
  q.push(make_pair(y,x));
  visited[y][x] = true;

  while(!q.empty()){
    int cy = q.front().first;
    int cx = q.front().second;

    q.pop();

    visited[cy][cx] = true;

    for(int i=0;i<4;i++){
      int ny = cy+dy[i];
      int nx = cx+dx[i];
      if(ny>=0 && nx>=0 && ny<n && nx<n && !visited[ny][nx]){
        if(MAP[ny][nx]==MAP[cy][cx]){
          // 같은 숫자일 경우에만 이동
          visited[ny][nx] = true;
          q.push(make_pair(ny,nx));
          con++;
        }
      }
    }
  }

  return con;

}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  input();

  map<int,int> answer;
  for(int i=1;i<=10;i++){
    answer[i]=0;
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(!visited[i][j]){
        // 아직 방문하지 않았을 경우에만
        int temp = bfs(i,j);
        answer[MAP[i][j]] = max(answer[MAP[i][j]],temp);
      }
    }
  }

  for(auto it : answer){
    cout << it.second << " ";
  }

}
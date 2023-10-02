#include <iostream>
#include <vector>


using namespace std;


int map[501][501];
bool visited[501][501]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int dp[501][501];
int N,M;

int dfs(int y,int x){
  if(y==N-1 && x==M-1){
    return 1;
  }
  if(visited[y][x]){
    return dp[y][x];
  }
  visited[y][x]=true;

  for(int i=0;i<4;i++){
    int ny= y+dy[i];
    int nx= x+dx[i];

    if(ny>=0 && nx>=0 && ny<N && nx<M){
      if(map[ny][nx]<map[y][x]){
        dp[y][x]= dp[y][x] + dfs(ny,nx);
      }
    }
  }
  return dp[y][x];

}


int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
    }
  }
  int answer= 0;

  answer = dfs(0,0);
  cout << answer << endl;

}
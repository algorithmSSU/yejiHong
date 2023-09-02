#include <iostream>
#include <vector>

using namespace std;


int map[501][501]={0,};
bool visited[501][501]={false,};
int dp[501][501]={0,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

int n,m;

int dfs(int y,int x){
  
  if(y==n && x==m){
    return 1;
  }

  if(visited[y][x]){
    return dp[y][x];
  }

  visited[y][x] = 1;

  for(int i=0;i<4;i++){
    int ny = y+dy[i];
    int nx = x+dx[i];
    if(ny>=0 && nx>=0 && ny<=n && nx<=m){
      if(map[y][x]>map[ny][nx]){
        dp[y][x]=dp[y][x]+dfs(ny,nx);
      }
    }
  }
  return dp[y][x];
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> map[i][j];
    }
  }

  


  int answer = 0;
  answer = dfs(1,1);
  cout << answer << '\n';

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout << dp[i][j];
    }cout << '\n';
  }

}
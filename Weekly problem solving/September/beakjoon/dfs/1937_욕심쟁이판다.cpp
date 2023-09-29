#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int map[501][501];
bool visited[501][501]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int N;
int dp[501][501]={0,};



void input(){
  cin >> N;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> map[i][j];
    }
  }
}




int dfs(int y,int x){
  if(dp[y][x]){
    return dp[y][x]; // dp에 값이 있으면 그냥 바로 dp[y][x] return 
  }
  // 값이 없으면 돌자!

  dp[y][x]=1;// 현재 위치한 곳까지 세주기 때문에 1
  for(int i=0;i<4;i++){
    int ny= y +dy[i];
    int nx= x +dx[i];

    if(ny>=0 && nx>=0 && ny<N && nx<N){
      if(map[ny][nx]>map[y][x]){
        dp[y][x]=max(dp[y][x],dfs(ny,nx)+1); // 한 연결이 die 되면 여길로 리턴 값이 들어옴
        //여기서 호출했으니까!
      }
    }
  }

  // 상하좌우 돌았는데 방문할 곳이 없다 -> 오케이 이 연결은 여기까지...die
  return dp[y][x]; // 제일 멀리간곳부터 +1 씩 해서 위로 올려줌(전 이동한 곳의 위치값에 +1)
  
}


void init(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      visited[i][j]=false;
    }
  }
}

int solution(){
  int answer = -1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(!visited[i][j]){
        int temp = dfs(i,j);
        answer = max(answer,temp);
      }
      
      //init();
    }
  }
  return answer;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int answer = 0;

  input();
  answer = solution();
  cout << answer << endl;


  // for(int i=0;i<N;i++){
  //   for(int j=0;j<N;j++){
  //     cout << dp[i][j];
  //   }
  //   cout << '\n';
  // }
  

}
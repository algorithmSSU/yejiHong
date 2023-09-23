#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dx[8] = {-1,0,1,-1,0,1,-1,1};
int dy[8] = {-1,-1,-1,1,1,1,0,0};
pair<int,int> map[1002][1002];
int visited[1002][1002];
queue<pair<int,int> > q;
int N, K;

void bfs(){
  while(!q.empty()){
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for(int i=0;i<8;i++){
      int ny =cy+dy[i];
      int nx =cx+dx[i];
      if(ny>=0 && nx>=0 && ny<N && nx<N && map[ny][nx].first!=1){
        map[ny][nx].second+=1;
      }
    }
  }
}


int check(){
  int cnt=0;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(map[i][j].second==K){
        cnt++; 
      }
    }
  }
  return cnt;
}


void input(){

  cin >> N >> K;


  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> map[i][j].first;
      if(map[i][j].first==1){
        q.push(make_pair(i,j));
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int answer= 0;

  input();
  bfs();
  answer =check();
  cout << answer << '\n';
  
  

  




}
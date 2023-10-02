#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int map[201][201]={0,};
bool visited[201][201]={false,};
int before_a, before_b, after_a, after_b;

int dy[6]={-2,-2,0,0,2,2};
int dx[6]={-1,1,-2,2,-1,1};
int answer= 0;

void bfs(int y,int x){
  queue<pair<pair<int,int>,int> > q;
  int cnt = 0;
  q.push(make_pair(make_pair(y,x),cnt));

  while(!q.empty()){
    int cy = q.front().first.first;
    int cx = q.front().first.second;
    int nc = q.front().second;
    
    nc+=1;
    
    visited[cy][cx]=true;
    q.pop();

    if(cy == after_a && cx == after_b){
      answer = nc;
      return;
    }


    for(int i=0; i<6;i++){
      int ny = cy+dy[i];
      int nx = cx+dx[i];
      if(ny>=0 && nx>=0 && ny<n && nx<n && !visited[ny][nx]){
        visited[ny][nx]=true;
        q.push(make_pair(make_pair(ny,nx),nc));
        //cout << nc << endl;
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;

  cin >> before_a >> before_b >> after_a >> after_b;

  bfs(before_a,before_b);

  cout << answer-1 << endl;


  
}
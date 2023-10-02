#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N,M;
int map[1001][1001];
bool visited[1001][1001][2];
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

int bfs(){
  queue<pair<pair<int,int>,pair<int,int> > >q;
  q.push(make_pair(make_pair(0,0),make_pair(1,0)));

  visited[0][0][0]= true;
  visited[0][0][1]= true;
  while(!q.empty()){
    int cy = q.front().first.first;
    int cx = q.front().first.second;
    int cost = q.front().second.first;// 거리계산
    int check = q.front().second.second;// 벽뿌셨는지 체크

    q.pop();

    if(cy==N-1 && cx==M-1){
      return cost;
    }

    for(int i=0;i<4;i++){
      int ny = cy+dy[i];
      int nx = cx+dx[i];

      if(ny>=0 && nx>=0 && ny<N && nx<M && !visited[ny][nx][check]){
        if(map[ny][nx]==0 && check==0){
          visited[ny][nx][check] = true;
          q.push(make_pair(make_pair(ny,nx),make_pair(cost+1,check)));
        }
        else if(map[ny][nx]==0 && check==1){
          visited[ny][nx][check] = true;
          q.push(make_pair(make_pair(ny,nx),make_pair(cost+1,check)));
        }
        else if(map[ny][nx]==1 && check==0){
          visited[ny][nx][check] = true;
          q.push(make_pair(make_pair(ny,nx),make_pair(cost+1,1)));//벽 부쉈다~ 1!
        }
        else if(map[ny][nx]==1 && check== 1){
          //
        }
      }
    }
  }
  return -1;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin >> N >> M;

  for(int i=0;i<N;i++){
    string str;
    cin >> str;
    for (int k = 0; k < str.length(); k++)
    {
      map[i][k] = str[k] - '0';
    }
  }

  int answer;
  answer = bfs();
  cout << answer << '\n';




}
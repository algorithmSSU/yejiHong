#include <iostream>
#include <queue>
#include <math.h>
#include <memory.h>
using namespace std;


int map[51][51] = {
    0,
};
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool visited[51][51] = {
    false,
};
int cnt = 0;
int n, l, r;
bool flag= true;
int people=0;

vector<pair<int,int> > walk;// bfs로 움직인 구간 위치 정보 저장

void reset()
{
  // 방문 초기화
  for (int i = 0; i < 51; i++)
  {
    memset(visited[i], false, sizeof(bool) * 51);
  }
}

void input()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }
}

void bfs(int y, int x)
{
  queue<pair<int, int> > q;
  q.push(make_pair(y, x));

  while (!q.empty())
  {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    visited[cy][cx] = true;

    for (int i = 0; i < 4; i++)
    {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (ny >= 0 && nx >= 0 && ny < n && nx < n && !visited[ny][nx])
      {
        int diff = abs(map[cy][cx] - map[ny][nx]);
        if (diff >= l && diff <= r)
        { // l<=diff<=r 이면 체크
          visited[ny][nx] = true;
          people += map[ny][nx];
          q.push(make_pair(ny, nx));
          walk.emplace_back(make_pair(ny,nx));
        }
      }
    }
  }
}


void print(int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << map[i][j];
    }
    cout << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> l >> r;
  input();
  int day = 0;
  // 탐색
  // 체크된 것들끼리 평균
  // 체크된 위치에 평균값 저장
  while(flag){
    flag= false;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(!visited[i][j]){
          walk.clear();
          walk.emplace_back(i,j);
          people= map[i][j];
          bfs(i,j);
        }
        if(walk.size()>=2){
          flag = true;
          for(int i=0;i<walk.size();i++){
            map[walk[i].first][walk[i].second] = people/walk.size();
          }
        }
      }
    }
    if(flag){
      day++;
    }
    reset();
  }
  cout << day << endl;
}
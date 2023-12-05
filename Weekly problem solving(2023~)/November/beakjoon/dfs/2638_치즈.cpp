#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 109

int map[MAX][MAX];
int con[MAX][MAX];
int N,M;
bool visited[MAX][MAX];
vector<pair<int,int>> cheeze;
queue<pair<int,int>> melt;
vector<pair<int,int>> Melt;

void input(){
  // 세로, 가로
  cin >> N >> M;

  // 맵 안에 치즈정보채우기
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
      if(map[i][j]==1){
        cheeze.emplace_back(i,j);
      }
    }
  }
}

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void printAll(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout << map[i][j] << " ";
    }
    cout << '\n';
  }
}


void init(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      visited[i][j] = false;
    }
  }
}

void connect(int y,int x){
  visited[y][x] = true;

  for(int i=0;i<4;i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny>=0 && nx>=0 && ny<N && nx<M && !visited[ny][nx]){
        visited[ny][nx] = true;
        if(map[ny][nx]==0){
          connect(ny,nx);
        }else if(map[ny][nx]==1){
          melt.push(make_pair(ny,nx));
        }
    }
  }
}

void melting(){
  Melt.clear();
  while(!melt.empty()){
    int y = melt.front().first;
    int x = melt.front().second;
    melt.pop();

    int eside = 0;
    for(int i=0;i<4;i++){
      int ny = y+dy[i];
      int nx = x+dx[i];
      // 🌟공기(=0) 과 인접하면서 위에서 방문했던 공기(=바깥공기) 인 경우 카운팅해준다.🌟
      if(ny>=0 && nx>=0 && ny<N && nx<M && map[ny][nx]==0 && visited[ny][nx]){
        eside++;
      }
    }
    // 2변 이상 노출시 녹는다
    if(eside>=2){
      Melt.emplace_back(y,x);
    }
  }
}

void transaction(){
  for(int i=0;i<Melt.size();i++){
    int y = Melt[i].first;
    int x = Melt[i].second;
    map[y][x] = 0;
  }
}

bool check(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(map[i][j]==1){
        return false;
      }
    }
  }
  return true;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Time = 0;
  input();
  while(true){
    
    if(check()){
      break;
    }
    Time++;
    //공기를 돌면서 치즈바깥부분 표시해주기
    connect(0,0);
    melting();
    transaction();
    init();
  }

  //printAll();
  cout << Time << '\n';


  

}
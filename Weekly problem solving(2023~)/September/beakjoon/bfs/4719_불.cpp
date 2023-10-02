#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000
int R, C;
char MAP[MAX][MAX];
int Fire_MAP[MAX][MAX];
bool Visit[MAX][MAX];

pair<int, int> Start;
queue<pair<int, int> > Fire_Q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void input(){
  cin >> R >> C;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin >> MAP[i][j];
      bool flag = false;
      if(MAP[i][j]=='J'){
        Start.first = i;
        Start.second = j;
      }else if(MAP[i][j]=='F'){
        flag = true;
        Fire_Q.push(make_pair(i,j));
        Fire_MAP[i][j]=0;
      }
      if(!flag){
        Fire_MAP[i][j] = 1e9;
      }
    }
  }
}

void init(){
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      Visit[i][j]= false;
    }
  }
}


void make_FireMap(){
  while(!Fire_Q.empty()){
    int cy =Fire_Q.front().first;
    int cx =Fire_Q.front().second;

    Fire_Q.pop();

    Visit[cy][cx] = true;

    for(int i=0;i<4;i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny>=0 && nx>=0 && ny<R && nx<C){
        if(!Visit[ny][nx] && MAP[ny][nx]!='#'){
          Visit[ny][nx]=true;
          if(Fire_MAP[ny][nx]>Fire_MAP[cy][cx]+1){
            Fire_MAP[ny][nx] = Fire_MAP[cy][cx]+1;
            Fire_Q.push(make_pair(ny,nx));
          }
        }
      }
    }
  }
}


int run_jihoon(int a, int b){
  queue<pair<pair<int,int>,int> > j;
  j.push(make_pair(make_pair(a,b),0));


  while(!j.empty()){
    int cy = j.front().first.first;
    int cx = j.front().first.second;
    int cost = j.front().second;

    if(cy==0 || cx==0 || cy==R-1 || cx==C-1){
      return cost +1;
    }

    j.pop();
    Visit[cy][cx]=true;

    for(int i=0;i<4;i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny>=0 && nx>=0 && ny<R && nx<C){
        if(!Visit[ny][nx] && MAP[ny][nx]!='#'){
          if(Fire_MAP[ny][nx] > cost+1){
            Visit[ny][nx]=true;
            j.push(make_pair(make_pair(ny,nx),cost+1));
          }
        }
      }
    }
  }
  return -1;
}


void solution(){
  int answer = 0;
  input();
  make_FireMap();
  init();

  answer = run_jihoon(Start.first,Start.second);
  if(answer == -1){
    cout << "IMPOSSIBLE" << '\n';
  }else{
    cout << answer << endl;
  }

}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  

  solution();
}



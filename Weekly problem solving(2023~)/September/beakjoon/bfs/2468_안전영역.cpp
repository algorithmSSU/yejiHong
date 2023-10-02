#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101]={0,};
int test_map[101][101]={0,};
bool visited[101][101]={false,};
int N, High, Low;
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

void bfs(int y,int x){
  queue<pair<int,int> > q;
  q.push(make_pair(y,x));

  while(!q.empty()){
    int cy = q.front().first;
    int cx = q.front().second;

    visited[cy][cx]=true;

    q.pop();

    for(int i=0;i<4;i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny>=0 && nx>=0 && ny<N && nx<N && !visited[ny][nx]){
        if(test_map[ny][nx]==1){
          visited[ny][nx] = true;
          q.push(make_pair(ny,nx));
        }
      }
    }
  }
}

void init(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      test_map[i][j]=0;
      visited[i][j]=false;
    }
  }

  
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  High = -1e9;
  cin >> N;

  int Area = 0;
  int area = 0;

  //   입력과 동시에 가장 최대 값 저장해두기
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> map[i][j];
      High = map[i][j] < High ? High : map[i][j];
    }
  }

  //  가장 큰 높이 만큼 횟수를 반복
  //  가장 많은 갯수의 안전영역을 가지는 영역값을 구해보자
  for(int h = 1;h<=High;h++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){

        // h 보다 작으면 잠김 -> 0
        if(map[i][j]<h){
          test_map[i][j]=0;
          // 그렇지 않으면 잠기지 않음 -> 1
        }else{
          test_map[i][j]=1;
        }
      }
    }


    // bfs  탐색
    area = 0; // 영역세주는 변수도 초기화
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(test_map[i][j] && !visited[i][j]){
          bfs(i, j);
          area++;
          
        }
      }
    }

    Area = max(Area,area);

    //  방문영역초기화
    init();

    
  }

  cout << Area << '\n';

}
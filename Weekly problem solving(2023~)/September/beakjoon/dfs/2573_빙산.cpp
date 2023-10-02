#include <iostream>
#include <vector>

using namespace std;

int map[301][301];
bool visited[301][301]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int R,C;


void init(){
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      visited[i][j]=false;
    }
  }
}

void dfs(int y,int x){
  visited[y][x]=true;

  for(int i=0;i<4;i++){
    int ny= y+dy[i];
    int nx= x+dx[i];
    if(ny>=0 && nx>=0 && ny<R && nx<C && !visited[ny][nx]){
      if(map[ny][nx]!=0){
        dfs(ny,nx);
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C;

  vector<pair<int,int> > ice;

  int ice_sum = 0;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin >> map[i][j];
      if(map[i][j]!=0){
        ice_sum+=map[i][j];
        ice.push_back(make_pair(i,j));
      }
    }
  }


  bool flag = true;
  int section = 0;
  int year=0;

  while(flag){

    // 방문 초기화 및 연결요소 갯수 초기화
    init();
    section=0;



    // 연결요소 확인하기
    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
        if(map[i][j]!=0 && !visited[i][j]){
          section++; // 연결요소 갯수
          dfs(i,j);
        }
      }
    }


    // 모두 녹았을 때 종료
    if(ice_sum==0){
      if(section<2){ // 두 덩어리 이상으로 분리되지 않았으면 0 출력
        cout << 0 << '\n';
      }
      break;
    }



    // 연결요소 갯수 2개 이상일 때 해당 년도 출력 후 종료
    if(section>=2){
      cout << year << '\n';
      break;
    }

    // 년도 계산
    year++;

    // 빙산 녹이기
    vector<pair<int,int> > target; // 한번에 녹여줘야하기 때문에 저장해둘 배열
    for(int i=0;i<ice.size();i++){
      int zero = 0;
      int cy = ice[i].first;
      int cx = ice[i].second;


      // 상하좌우 확인하고
      for(int j=0;j<4;j++){
        int ny = dy[j]+cy;
        int nx = dx[j]+cx;

        if(ny>=0 && ny>=0 && ny<R && nx<C){
          if(map[ny][nx]==0){
            zero++;   
          }
        }
      }

      // 상하좌우 중 0인 면적이 현재 값보다 많으면 현재 값은 0로 -> 타겟배열에 담음
      if(map[cy][cx]<=zero){
        target.emplace_back(cy,cx);
        ice_sum-=map[cy][cx];


      // 상하좌우 중 0인 면적이 현재 값보다는 작으면 현재 값에서 뺴주기
      }else if(map[cy][cx]>zero){ // 
        map[cy][cx]-=zero;
        ice_sum-=zero;
      }
    }

    // 모든 빙하 돌고, 상하좌우 0인 면적이 특정 위치 빙하값보다 클 경우 0로 
    for(int t = 0; t<target.size();t++){
      map[target[t].first][target[t].second] = 0;
    }

  }

}
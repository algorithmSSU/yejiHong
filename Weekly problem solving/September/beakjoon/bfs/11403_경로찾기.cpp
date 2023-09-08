#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int n;
int map[MAX][MAX]={0,};
bool visited[MAX][MAX]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};


// 플로이드와샬 문제
// i-> k -> j

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> map[i][j];
    }
  }

  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(map[i][k] && map[k][j]){
          map[i][j]=1;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << map[i][j] << " ";
    }
    cout << '\n';
  }

}
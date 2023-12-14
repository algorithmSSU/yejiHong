#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100009
int team[MAX];
bool visited[MAX];
bool done[MAX];
int cny;

// 모든 노드의 정점을 시작정점으로 해서 연결정보 알아내기
void dfs(int node){
  visited[node] = true;

  int next = team[node]; // node번쨰 값 = next 값

  if(!visited[next]){ // 방문을 안했으면 방문하러 ㄱㄱ
    dfs(next);
  }else if(!done[next]){ // 이미 방문dmf 
    for(int i=next; i!=node; i=team[i]){
      cnt++;
    }
  }
  done[node]=true;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;

  for(int t=0;t<test;t++){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
      cin >> team[i];
    }

  }

  

}
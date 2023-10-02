#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int N;
vector<pair<int,int> > graph[10001];
bool visited[10001]={false,};

//dfs
stack<pair<int,int> > s;
int MaxCost=-1e9;
int Maxgoal=-1e9;
int MaxNode = 0;


void dfs(int start, int cost){
  //가장 큰 거리찾기
  if(MaxCost < cost){
    MaxCost = cost;
    MaxNode = start;
  }
  //MaxCost = max(MaxCost,cost);


  visited[start]=true;
  for(int i=0;i<graph[start].size();i++){
    int next = graph[start][i].first;
    int next_cost = graph[start][i].second;
    if(!visited[next]){
      dfs(next,cost+next_cost);
    }
  }
}

int main(){
  cin >> N;

  for(int i=0;i<N-1;++i){
    int a,b,cost;
    cin >> a >> b >> cost;
    graph[a].emplace_back(b,cost);
    graph[b].emplace_back(a,cost);
  }


  int dot1= 0;
  int dot2 = 0;

  dfs(1,0);
  dot1 = MaxCost;
  
  // 초기화
  memset(visited,false,sizeof(visited));
  MaxCost=-1e9;

  
  dfs(MaxNode,0);

  cout << MaxCost << endl;

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> tree[100001];
int visited[100001]={0,};
int answer[100001]={0,};
int n,m,s;
int v = 0;

void dfs(int s){
  if(!visited[s]){
    visited[s]=true;
    answer[s]=++v;
  }else{
    return;
  }
  
  for(int i=0;i<tree[s].size();i++){
    int next = tree[s][i];
    if(!visited[next]){
      dfs(next);
    }
  }
  
}


int main(){
  cin >> n >> m >> s;
  for(int i=1;i<=m;i++){
    int x,y;
    cin >> x >> y;
    tree[x].emplace_back(y);
    tree[y].emplace_back(x);
  }


  for(int i=1;i<=n;i++){
    sort(tree[i].begin(),tree[i].end());
  }

  dfs(s);

  for(int i=1;i<=n;i++){
    cout << answer[i] << '\n';
  }
  



}
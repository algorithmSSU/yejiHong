#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int arr[1002]={0,};
bool visited[2002]={false,};
int dp[1002]={0,};
int n;
int ans=0;

void bfs(int start_idx){
  queue<int> q;
  q.push(start_idx);
  while(!q.empty()){
    int idx = q.front();
    q.pop();
    visited[idx]=true;

    for(int i=1;i<=arr[idx];i++){
      int next_idx = idx+i;
      dp[next_idx]=min(dp[next_idx],dp[idx]+1); // 원래 dp[i] 값과 
      if(next_idx<10){
        q.push(next_idx);
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(int i=1;i<=n;i++){
    cin >> arr[i];
    dp[i]=1e9;
  };

  dp[1]=0;

  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bfs(i);
    }
  }

  if(dp[n]==1e9){
    cout << -1 << '\n';
  }else{
    cout << dp[n] << '\n';
  }

  for(int i=1;i<=n;i++){

    cout << dp[i] << " ";
  }





}
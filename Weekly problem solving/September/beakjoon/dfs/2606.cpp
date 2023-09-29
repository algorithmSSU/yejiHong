#include <iostream>
#include <vector>
using namespace std;


vector<int> arr[101];
int N;
int M;
bool visited[101]={false,};
int dp[101]={0,};


int cnt =0;

int dfs(int start){
  visited[start]=true;
  for(int i=0;i<arr[start].size();i++){
    int next = arr[start][i];
    if(!visited[next]){
      dp[start]+=dfs(next)+1;
    }
  }
  return dp[start];
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  cin >> M;

  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    arr[a].emplace_back(b);
    arr[b].emplace_back(a);
  }

  int answer =0;
  answer = dfs(1);
  cout << answer << endl;

  

}
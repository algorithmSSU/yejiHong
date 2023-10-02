#include <iostream>
#include <vector>

using namespace std;

const int MAX  = 100009;
long long int n;
long long int start;
long long int arr[MAX] = {
    0,
};
bool visited[MAX] = {
    false,
};
long long int answer = 0;

void dfs(int idx){
  if(idx < 1 || idx > n){
    return;
  }
  visited[idx]=true;
  dfs(idx+arr[idx]);
  dfs(idx-arr[idx]);

}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> arr[i];
  }
  cin >> start;
  dfs(start);

  for(int i=1;i<=n;i++){
    if(visited[i]){
      answer++;
    }
  };

  cout << answer << endl;
  


}
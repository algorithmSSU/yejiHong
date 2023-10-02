#include <iostream>
#include <vector>

using namespace std;

bool visited[10]={false,};
int ans[10]={false,};
int n,m;
void backtracking(int idx, int cnt){
  if(cnt==m){
    for(int i=0;i<cnt;i++){
      cout << ans[i] << " "; 
    }
    cout << '\n';
    return;
  }else{
    for(int i=idx;i<=n;i++){
      ans[cnt]=i;
      backtracking(idx,cnt+1);

    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;

  backtracking(1,0);




}
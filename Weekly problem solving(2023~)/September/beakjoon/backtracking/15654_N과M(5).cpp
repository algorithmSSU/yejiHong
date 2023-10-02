#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
int arr[11];
int answer[11];
bool visited[11]={false,};

void backTracking(int cnt){
  if(cnt==m){
    for(int i=0;i<m;i++){
      cout << answer[i] << " ";
    }
    cout << '\n';
    return;
  }else{
    for(int i=0;i<n;i++){
      if(!visited[i]){
        visited[i]=true;
        answer[cnt]=arr[i];
        backTracking(cnt+1);
        visited[i]=false;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  };

  sort(arr,arr+n);

  backTracking(0);

  



  

}
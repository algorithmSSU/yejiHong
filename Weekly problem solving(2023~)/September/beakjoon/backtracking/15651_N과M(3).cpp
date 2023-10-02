#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[11];
bool visited[11]={false,};

void BackTracking(int cnt)
{
  if(cnt==m){
    for(int i=0;i<m;i++){
      cout << arr[i] << " ";
    }
    cout << '\n';
    return;
  }else{
    for(int i= 1;i<=n;i++){
      arr[cnt]=i;
      BackTracking(cnt+1);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  BackTracking(0);


}
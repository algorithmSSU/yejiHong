#include <iostream>
#include <vector>
using namespace std;
int n;
bool visited[10];
int arr[10];
void BT(int cnt){
  if(cnt==n){
    for(int i=0;i<cnt;i++){
      cout << arr[i] << " ";
    }
    cout << '\n';
    return;
  }else{
    for(int i=1;i<=n;i++){
      if(!visited[i]){
        visited[i]=true;
        arr[cnt]=i;
        BT(cnt+1);
        visited[i]=false;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;

  BT(0);


}
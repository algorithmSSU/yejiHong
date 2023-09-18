#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[21][101]={0,};
int lose[21];
int joy[21];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  // 체력소모
  for(int i=1;i<=N;i++){
    cin >> lose[i];
  }
  // 기쁨
  for(int i=1;i<=N;i++){
    cin >> joy[i];
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=100;j++){// 세준의 체력
      int cur_loss = lose[i];
      int cur_enjoy = joy[i];
      if(j>cur_loss){
        arr[i][j] = max(arr[i-1][j-cur_loss]+cur_enjoy,arr[i-1][j]);
      }else{
        arr[i][j] = arr[i-1][j];
      }
    }
  }

  cout << arr[N][100] << endl;




  
  
}
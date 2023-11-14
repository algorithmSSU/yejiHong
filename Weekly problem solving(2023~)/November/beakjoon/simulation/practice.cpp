#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int w,h;
  cin >> h >> w;

  int arr[501];
  int rain[501]={0,};
  for(int i=0;i<w;i++){
    cin >> arr[i];
  }
  

  int Result = 0;
  for(int i=1;i<w;i++){
    int left = 0;
    int right = 0;
    // 왼쪽~현재까지 최대값
    for(int j=0;j<i;j++){
      left = max(left,arr[j]);
    }
    // 오른쪽~현재까지의 최대값
    for(int j=w-1;j>i;j--){
      right = max(right,arr[j]);
    }
    int now = min(left,right) - arr[i];
    rain[i] = max(0,now);
    Result +=rain[i];
    // i 번째 위치가 왼쪽 최고 높이, 오른쪽 최고 높이 보다 더 높을 경우
    // now 는 - 가 됨 
    // 따라서 이런 경우 음수를 기록하지 않고, 0을 기록하도록함(채워지는 빗물이 없다는 뜻)
  }

  // for(int i=0;i<w;i++){
  //   cout << rain[i] << " ";
  // }
  cout <<Result << endl;
  
}


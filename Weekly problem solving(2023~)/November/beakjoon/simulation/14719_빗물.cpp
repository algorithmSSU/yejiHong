#include <iostream>
#include <vector>
#include <iostream>


using namespace std;

int H,W;
int arr[501];
int sum[501];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int answer = 0;
  cin >> H >> W;

  for(int i=0;i<W;i++){
    cin >> arr[i];
  }

  for(int i=1;i<W;i++){
    int left = 0;
    int right =0;

    // 왼쪽 최대값 구해주고
    for(int j=0;j<i;j++){
      left = max(left,arr[j]);
    }
    // 오른쪽 최대값 구해주고
    for(int j=W-1;j>i;j--){
      right = max(right,arr[j]);
    }
    answer+=max(0,min(left,right)-arr[i]);
  }
  cout << answer << endl;

}
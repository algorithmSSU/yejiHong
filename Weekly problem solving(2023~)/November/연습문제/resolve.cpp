#include <iostream>
#include <algorithm>

using namespace std;


#define MAX 100009


int arr[MAX];
int n,s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  

  // 입력을 받으면서 동시에, s값 이상이되면 맨 앞에서부터 s 값 이상인 값을 구할 때 까지 범위를 좁혀주면서 
  // s 값 이상인 구간의 길이의 최소 값을 구해준다.

  int sum = 0;
  int left = 0;
  int len = 1e9;


  for(int right = 0; right<n; right++){
    cin >> arr[right];
    sum+=arr[right];
    while(sum>=s && left<=right){
      len = min(len,(right-left+1));
      sum-=arr[left];
      left++;
    }
  }
  if(len>=1e9){
    cout << 0 << endl;
  }else{
    cout << len << endl;
  }

}
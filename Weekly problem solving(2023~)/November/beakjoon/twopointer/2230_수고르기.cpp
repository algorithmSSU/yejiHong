#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100005

int N,M;
int arr[MAX];
int mn = 0x7fffffff; // int형으로 표현할 수 있는 크기..네
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;

  for(int i=0;i<N;i++){
    cin >> arr[i];
  }

  sort(arr,arr+N);
  
  int end = 0;
  
  for(int start = 0; start < N; start++){
    while(end < N  && arr[end]-arr[start]<M)
      end++;
    if(end == N)
      break; // end 가 범위를 벗어날 시 종료 --> 1
    mn = min(mn,arr[end]-arr[start]);
    
  }
  cout << mn << endl;
  



  return 0;

}
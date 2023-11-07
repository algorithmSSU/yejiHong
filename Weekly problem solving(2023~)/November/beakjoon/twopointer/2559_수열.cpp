#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001
int N, K;
int arr[MAX]={0,};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;


  for(int i=1;i<=N;i++){
    int temp;
    cin >> temp;
    arr[i]=arr[i-1]+temp;
  }

  int p1 = 0;
  int p2 = K;
  int maxRange = -1e9;
  while(K!=N+1){
    int range = arr[K++]-arr[p1++];
    maxRange = max(maxRange, range);
  }

  cout << maxRange << endl;

}

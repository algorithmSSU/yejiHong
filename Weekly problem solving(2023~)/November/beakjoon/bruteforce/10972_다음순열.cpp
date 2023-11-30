#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[100009];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  cin >> n;
  for(int i=0;i<n;i++){
    cin >> arr[i];
    dp[i]=arr[i];

  }

  if(next_permutation(arr,arr+n)){
    for(int i=0;i<n;i++){
      cout << arr[i] << ' ';
    }
  }else{
    cout << -1 << endl;
  }
}
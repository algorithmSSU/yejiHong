#include <iostream>
#include <vector>
using namespace std;

int arr[1001]={0,};
int nums[1001]={0,};

// 또다른방법
int solution(int arr[], int N){
  int occur[101]={0,};
  for(int i=0;i<N;i++){
    if(occur[100-arr[i]]==1){
      return 1;
    }
    occur[arr[i]] = 1;
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int cnt=0;
  cin >> n;
  
  for(int i=0;i<n;i++){
    int num;
    cin >> num;
    arr[num]=1;
    nums[i]=num;
  }

  for(int i=0;i<n;i++){
    int idx = 100-nums[i];
    if(arr[idx]==1){
      arr[nums[i]]=0;
      cnt++;
    }
  }
  cout << cnt << endl;
}
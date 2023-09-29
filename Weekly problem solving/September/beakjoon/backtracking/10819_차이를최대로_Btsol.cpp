#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int n;
vector<int> numbers;
int arr[11];
int Max=-1;
bool visited[11];


int cal(int *arr,int size){
  int answer = 0;
  for(int i=0;i<size-1;i++){
    answer+=abs(arr[i]-arr[i+1]);
  }
  return answer;

}


void BT(int cnt){
  if(cnt==n){
    int ans = cal(arr,n);
    Max = max(Max,ans);
    return;
  }
  for(int i=0;i<n;i++){
    if(!visited[i]){
      visited[i]=true;
      arr[cnt]=numbers[i];
      BT(cnt+1);
      visited[i]=false;
    }
    
  }

}



int main(){
  ios_base::sync_with_stdio(false);
  cin >> n;

  for(int i=0;i<n;i++){
    int num;
    cin >> num;
    numbers.emplace_back(num);
  }

  BT(0);
  cout << Max << endl;

  return 0;
  



    
}
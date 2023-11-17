#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

// 다시.....

using namespace std;

int arr[1000001];
int answer[1000001];
int main(){
  int N;
  cin >> N;
  stack<int> s;



  for(int i=0;i<N;i++){
    int num;
    cin >> num;
    arr[i] = num; // oh
    while(1){
      if(s.empty()){
        s.push(i);// 인덱스를??
        break;
      }
      // 스택이 비지 않았으면 스택의 top 과 비교
      int idx = s.top();
      // num 이 더 클 경우에는 Index 에 해당하는 원소를 넣어주고 인덱스를 pop
      if(num>arr[idx]){
        arr[idx] = num;
        s.pop();
      }
      // num 이 작거나 같으면 스택에 push 하고 다음 원소 확인
      else{
        s.push(i);
        break;
      }
    }
  }
  while(!s.empty()){
    int idx = s.top();
    arr[idx] = -1;
    s.pop();
  }
  for(int i=0;i<N;i++){
    cout << arr[i] << " ";
  }
  cout << '\n';
  return 0;
}
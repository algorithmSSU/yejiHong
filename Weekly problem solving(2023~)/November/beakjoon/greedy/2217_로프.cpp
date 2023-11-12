#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;


  // 와진짜 빨라짐 good 
  priority_queue<int,vector<int>,less<int>> q; // 오름차순


  for(int i=0;i<n;i++){
    int line;
    cin >> line;
    q.push(line);
  }


  int sum=0;
  int Max = 0;
  int cnt = 0;
  while(!q.empty()){
    sum = q.top();
    q.pop();
    cnt++;
    int cur = cnt * sum;
    Max = max(cur,Max);
  }

  cout << Max << '\n';

  


}
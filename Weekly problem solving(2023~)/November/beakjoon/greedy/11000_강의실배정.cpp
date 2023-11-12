#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int,int>> times;
  for(int i=0;i<N;i++){
    int s,t;
    cin >> s >> t;
    times.emplace_back(s,t);
  }

  // 먼저 시작하는 것부터 
  sort(times.begin(),times.end());


  priority_queue<int,vector<int>,greater<int>> q;
  q.push(times.front().second);

  int cnt = 1;
  for(int j=1;j<times.size();j++){
    if(q.top() <= times[j].first){
      q.pop();
      q.push(times[j].second);
    }else if(q.top()>times[j].first){
      cnt++;
      q.push(times[j].second);
    }
  }
  cout << cnt << endl;

  

}
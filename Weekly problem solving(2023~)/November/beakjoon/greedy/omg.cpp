#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){


  vector<int> v = {1,2,3,4,5};

  sort(v.begin(),v.end(),greater<>()); // greater -> 내림차순
  for(auto it : v){
    cout << it << endl;
  }


  priority_queue<int,vector<int>,less<int>> q; // less -> 내림차순 , greater -> 오름차순
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  while(!q.empty()){
    cout << q.top() << endl;
    q.pop();
  }

}
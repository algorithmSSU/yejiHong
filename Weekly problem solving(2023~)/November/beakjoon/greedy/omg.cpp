#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


bool compare(int a, int b){
  return a>b; //default a<b, a>b 내림차순?
}

bool comp(pair<int,int>&a, pair<int,int>&b){
  if(a.first==b.first){ // 같을 경ㅇ우에
    return a.second > b.second; // 두번째 값을 내림차순,큰거부터 
  }
  return a.first < b.first; // 오름차순
}
int main(){


  // vector<int> v = {1,2,3,4,5};

  // sort(v.begin(),v.end(),greater<>()); // greater -> 내림차순
  // for(auto it : v){
  //   cout << it << endl;
  // }


  // priority_queue<int,vector<int>,less<int>> q; // less -> 내림차순 , greater -> 오름차순
  // q.push(1);
  // q.push(2);
  // q.push(3);
  // q.push(4);
  // q.push(5);

  // while(!q.empty()){
  //   cout << q.top() << endl;
  //   q.pop();
  // };


  // char test = '1';
  // if(isdigit(test)){
  //   cout << " 숫자다 "<< test-'0' << endl;
  // }

  vector<pair<int,int>> v;
  v.emplace_back(4,2);
  v.emplace_back(99,3);
  v.emplace_back(13,5);
  v.emplace_back(8,2);
  v.emplace_back(8,4);
  v.emplace_back(8,0);
  v.emplace_back(8,13);
  v.emplace_back(8,3);


  sort(v.begin(),v.end(),comp);
  for(auto it : v){
    cout << it.first << " " << it.second << endl;
  }
  
}
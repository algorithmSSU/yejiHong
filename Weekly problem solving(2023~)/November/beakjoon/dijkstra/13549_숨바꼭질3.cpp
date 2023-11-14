#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, K;

bool visited[10000001]={false,};

long long hideAndSeek(int start){
  //priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  queue<pair<long long,int>> q;
  long long T;
  q.push(make_pair(start, 0)); // 위치, 시간

  while(!q.empty()){
    
    long long pos = q.frontb().first;
    int time = q.front().second;
    q.pop();
    visited[pos]= true;


    if(pos==K){
      T = time;
      //cout << "ok" << endl;
      break;
    }

    long long next_double = pos * 2;
    long long next_go = pos + 1;
    long long next_back = pos - 1;

    if(0<=next_double && next_double<=100001){
      visited[next_double] = true;
      q.push(make_pair(next_double,time));
    }
    if(0<=next_back && !visited[next_back]){
      visited[next_back] = true;
      q.push(make_pair(next_back,time+1));
    }
    if(next_go<=K && !visited[next_go]){
      visited[next_go] = true;
      q.push(make_pair(next_go,time+1));
    }

  }
  return T;
  
}



int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;


  int answer = 0;
  answer = hideAndSeek(N);
  cout << answer << endl;

  

}
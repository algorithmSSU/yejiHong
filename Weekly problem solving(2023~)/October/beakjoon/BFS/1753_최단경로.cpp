#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int> > arr[300001];
int v,e;
int start;
int dist[20001];

void shortestPath(int cost, int now){
  //queue<pair<int,int> > q;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >> q;
  q.push(make_pair(cost,now));

  while(!q.empty()){
    int cost = q.top().first;
    int cur = q.top().second;
    
    q.pop();


    for(int i=0;i<arr[cur].size();i++){
      int next = arr[cur][i].second;
      int next_cost = arr[cur][i].first+cost;

      if(dist[next] > next_cost){
        dist[next] = next_cost;
        q.push(make_pair(next_cost,next));
      }
    }
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> v >> e;
  cin >> start;

  for(int i=0;i<e;i++){
    int from,to,cost;
    cin >> from >> to >> cost;
    arr[from].emplace_back(cost,to);
  }


  fill(dist,dist+20001,1e9); // 최대 값으로 채워줌


  dist[start]=0;
  shortestPath(0,start);

  for(int i=1;i<=v;i++){
    if(dist[i]==1e9){
      cout << "INF" << '\n';
    }else{
      cout << dist[i] << '\n';
    }
  }


  
  

}
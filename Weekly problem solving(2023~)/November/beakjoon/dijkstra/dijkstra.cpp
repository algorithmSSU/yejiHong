#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> graph[100]; // node,cost
int dist[100];

void dijkstra(int start){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; // 🌟 
  dist[start] = 0;
  q.push(make_pair(0,start));
  while(!q.empty()){
    int cur = q.top().second; // 현재 노드
    int cost = q.top().first; // 현재 노드의 비용
    q.pop();
    
    for(int i=0;i<graph[cur].size();i++){
      int next = graph[cur][i].first;
      int next_cost = graph[cur][i].second + cost;
      if(dist[next] > next_cost){

        //
        cout << "======update======" << '\n' << "now : " << cur  << ", next : " << next << endl;
        dist[next] = next_cost;
        q.push(make_pair(next_cost,next));
      }
    }
  }
}



int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);


  // graph 설정
  graph[1].emplace_back(3,6);
  graph[1].emplace_back(4,3);
  graph[2].emplace_back(1,3);
  graph[3].emplace_back(4,3);
  graph[4].emplace_back(2,1);
  graph[4].emplace_back(3,1);
  graph[5].emplace_back(2,4);
  graph[5].emplace_back(4,2);

  fill(dist,dist+100,0x7fffffff);


  // 시작정점을 5로 설정
  dijkstra(5);


  // 각 정점 별 최단 경로 출력
  for(int i=1;i<=5;i++){
    cout << i <<"번 정점 최단경로 : " << dist[i] << endl;
  }

}
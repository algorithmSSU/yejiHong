#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define CITY 300003
int N,M,K,X;
vector<int> CityMap[CITY];
int dist[CITY];
vector<int> ans;

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; // 오름차순
    q.push(make_pair(0,start));
    while(!q.empty()){
        int node = q.top().second;
        int cost = q.top().first;
        q.pop();

        for(int i=0;i<CityMap[node].size();i++){
            int next = CityMap[node][i];
            int next_cost = cost+1;
            // cost 바로 연결되어 있으면 1
            if(dist[next]>next_cost){
                dist[next]=next_cost;
                q.push(make_pair(next_cost,next));
            }
        }
    }
}

void solution(){
    cin >> N >> M >> K >> X;
    // 순서대로 도시의 개수, 도로의 개수, 거리정보, 출발도시번호

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        CityMap[a].emplace_back(b);
    }

    fill(dist,dist+CITY,1e9);
    dijkstra(X);
    priority_queue<int,vector<int>,greater<int>> pq; // 오름차순
    for(int i=1;i<=N;i++){
        if(dist[i]==K)
            pq.push(i);
    }
    if(pq.empty()){
        cout << -1 << endl;
    }
    
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    };

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution();

}
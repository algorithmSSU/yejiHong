#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;

vector<pair<int,int> > arr[1001]; // 각 노드에 연결된 [정점,비용] 저장
bool visited[1001]={false,};
int dist[1001]; // 시작점에서 각 노드까지의 최단거리를 저장해줄 배열
int start;
int dest;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;



void input(){
    cin >> N >> M; // 도시의 수, 버스의 수
    for(int i=0;i<M;i++){
        int from,to,cost;
        cin >> from >> to >> cost;
        arr[from].emplace_back(to,cost);
    }

    cin >> start >> dest; // 시작, 도착 
    fill(dist,dist+N+1,1e9); // 거리기록하는 배열 모두 최대값으로 설정
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    input(); // 입력받기

    pq.push(make_pair(0,start));// 출발점 저장[비용,정점번호]
    dist[start]=0;// 시작점의최단거리


    // search
    while(!pq.empty()){
        int cost = pq.top().first;//탐색할 정점의 비용
        int now = pq.top().second;//탐색할 정점의 번호
        pq.pop();

        if(!visited[now]){
            visited[now]=true;
            if(now==dest){//지금이 도착지면 loop 돌지 않음
                continue;
            }
            for(int i=0;i<arr[now].size();i++){
                int next = arr[now][i].first; // 다음 인접 정점
                int next_cost=arr[now][i].second; //비용

                if(dist[next] > dist[now]+next_cost){ // 현재 위치 비용 업데이트
                    dist[next] = dist[now]+next_cost;
                    pq.push(make_pair(dist[next],next));
                }
            }
        }
    }
    cout << dist[dest] << '\n';
    return 0;
     




}
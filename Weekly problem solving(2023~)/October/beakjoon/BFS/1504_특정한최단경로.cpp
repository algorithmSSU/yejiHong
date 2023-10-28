#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define INF 99999999
#define MAX 801
int N,E,a,b;
vector<pair<int,int>> graph[MAX];
int dist[MAX];

void init(){
    for(int i=0;i<MAX;i++){
        dist[i]=INF;
    }
}


void digk(int start){
    init();
    dist[start]=0;

    queue<pair<int,int> > q;
    q.push(make_pair(start,0));

    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;

        q.pop();

        for(int i =0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;

            if(dist[next]>cost+next_cost){
                dist[next] = cost+next_cost;
                q.push(make_pair(next,next_cost+cost));
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> E;

    for(int i=0;i<E;i++){
        int v1,v2,cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].emplace_back(make_pair(v2,cost));
        graph[v2].emplace_back(make_pair(v1,cost));
    }

    cin >> a >> b;


    int startToa;
    int startTob;
    int aTob;
    int aTon, bTon;
    int answer=0;
    // 1->a->N
    // 1->b->N

    digk(1);
    startToa = dist[a];
    startTob = dist[b];
    // 시작지점부터 중간에 어딜 들릴것인지
    

    digk(a);
    // a->b b->a
    aTob = dist[b];
    aTon = dist[N];


    digk(b);
    bTon = dist[N];
    // 중간을 어디로 두고 끝으로 갈것인지

    // start -> a-b -> N
    // start -> b-a -> N

    answer = min(startToa+aTob+bTon, startTob+aTob+aTon);
    if(answer >= INF){
        cout << -1 << endl;
    }else{
        cout << answer << endl;
    }
    

    
    

    

    

    






    
}
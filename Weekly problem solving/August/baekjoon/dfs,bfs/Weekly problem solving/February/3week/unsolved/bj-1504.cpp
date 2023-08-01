// https://yabmoons.tistory.com/386
// 특정한 최대 경로

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define SIZE 801

int dist[SIZE]={0,};
int N,M;
vector<pair<int, int>> v[SIZE];

int dijkstra(int start,int end){
    int d = 0;

    queue<int>q;
    q.push(start);

    while(!q.empty()){
        int cur= q.front();
        q.pop();

        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int cost = v[cur][i].second;
            
            if(next==end){
                d=cost;
                return d;
            }
            q.push(next);


        };
    };
    return d;

};

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    

    cin >> N >> M;

    for(int i=1;i<=M;i++){
        int v1,v2,edge;
        cin >> v1 >> v2 >> edge;
        v[v1].emplace_back(v2,edge);
        v[v2].emplace_back(v1,edge);
    };




    

};
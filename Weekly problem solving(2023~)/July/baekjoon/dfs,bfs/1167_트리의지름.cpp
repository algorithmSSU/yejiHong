#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<pair<int,int> > arr[100001];
int maxDist = 0;
int maxNode;
bool visited[100001]={false,};
void dfs(int node,int dist){
    visited[node]=true;
    for(int i=0;i<arr[node].size();i++){
        int next_node = arr[node][i].first;
        int next_cost = arr[node][i].second;

        if(maxDist < dist){
            maxDist = dist;
            maxNode = node;
        }

        if(!visited[next_node]){
            dfs(next_node,dist+next_cost);
        }
    }
    
}

int main(){
    cin >> n;
    int v1,v2,cost;
    for(int i=1;i<=n;i++){
        cin >> v1;
        while(1){
            cin >> v2;
            if(v2==-1)
                break;
            cin >> cost;
            arr[v1].emplace_back(make_pair(v2,cost));
            arr[v2].emplace_back(make_pair(v1,cost));
        }
    }

    // 정점 1에서 가장 거리가 먼 정점 찾기
    dfs(1,0);
    memset(visited,false,sizeof(visited));
    maxDist = 0;
    dfs(maxNode,0);

    cout << maxDist << '\n';

    return 0;
}
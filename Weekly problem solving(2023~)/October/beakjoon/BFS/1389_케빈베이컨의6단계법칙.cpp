#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<int> graph[101];
int visited[101]={false,};

int bfs(int start){
    queue<pair<int,int> > q;
    q.push(make_pair(start,0));
    visited[start]=true;
    int costSum=0;

    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        costSum +=cost;

        q.pop();

        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(make_pair(next,cost+1));
            }
        }
    }
    return costSum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer= 1e9;
    int result_idx=0;

    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    for(int i=1;i<=n;i++){
        int temp = bfs(i);
        if(answer > temp){
            result_idx= i;
            answer=temp;
        }
        memset(visited,false,sizeof(visited));
    };

    cout << result_idx << endl;

}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[200001];
int visited[200001]={0,};

int n,m,s;

bool comp(int a,int b){
    return b < a;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    int visit = 1;
    visited[start]=visit++;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0;i<map[cur].size();i++){
            int next = map[cur][i];
            if(!visited[next]){
                visited[next] = visit++;
                q.push(next);
            }
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> n >> m >> s;

    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        map[x].emplace_back(y);
        map[y].emplace_back(x);
    }

    for(int i=1;i<=m;i++){
        sort(map[i].begin(),map[i].end(),comp);
    }
    
    bfs(s);

    for(int i=1;i<=n;i++){
        cout << visited[i] << "\n";
    }
    
}
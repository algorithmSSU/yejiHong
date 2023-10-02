#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n,m,start;
vector<int> node[100001];
bool visited[100001]={false,};
int result[100001]={0,};
int cnt=1;

void bfs(int start){
    queue<int> q;
    q.push(start);
    result[start]=cnt;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        visited[now]=true;

        for(int i=0;i<node[now].size();i++){
            int next = node[now][i];
            if(!visited[next]){
                cnt++;
                result[next]=cnt;
                visited[next]=true;
                q.push(next);
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> start;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        node[a].emplace_back(b);
        node[b].emplace_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(node[i].begin(),node[i].end());
    }

    bfs(start);
    
    for(int i=1;i<=n;i++){
        cout << result[i] << '\n';
    }

    

}
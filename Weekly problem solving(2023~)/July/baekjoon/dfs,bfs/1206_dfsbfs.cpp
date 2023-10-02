#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> v[10001];
bool visited[10001]={false,};
vector<int> d;
vector<int> b;
void dfs(int start){
    visited[start]=true;
    d.emplace_back(start);
    for(int i=0;i<v[start].size();i++){
        int cur = v[start][i];
        if(!visited[cur]){
            dfs(cur);
        }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        b.emplace_back(now);
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i];
            if(!visited[next]){
                visited[next]= true;
                q.push(next);
            };
            
        }
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int range,line,start;
    
    
    cin >> range >> line >> start;
    

    for(int i=0;i<line;i++){
        int x,y;
        cin >> x >> y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    };

    for(int i=0;i<line;i++){
        sort(v[i].begin(),v[i].end());
    }


    dfs(start);
    memset(visited,false,sizeof(visited));
    bfs(start);


    for(int i=0;i<d.size();i++){
        cout << d[i] << ' ';
    };
    cout << '\n';

    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << ' ';
    };
    cout << '\n';
}
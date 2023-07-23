#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001]={false,};


int dfs(int start){
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++){
        int next = graph[start][i];
        if(visited[next]==false){
            dfs(next);
        }
    }
    return 1;

    
}


int main(){

    int dot;
    int edge;
    cin >> dot >> edge;

    for(int i=0;i<edge;i++){
        int x,y;
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    int cnt = 0;
    for(int i=1;i<=dot;i++){
        if(visited[i]==false){
            cnt+=dfs(i);
        }
    }

    cout << cnt << '\n';




}
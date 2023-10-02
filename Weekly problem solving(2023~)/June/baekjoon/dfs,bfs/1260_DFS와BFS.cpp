#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


bool visited_d[10001]={false,};
bool visited_b[10001]={false,};
vector<int> tree[10001];

vector<int> log_d;
vector<int> log_b;

void dfs(int start){
    visited_d[start]=true;
    log_d.emplace_back(start);
    
    sort(tree[start].begin(),tree[start].end());
    for(int i=0;i<tree[start].size();i++){
        int cur = tree[start][i];
        if(!visited_d[cur]){
            dfs(cur);
        }
    }
};


void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        visited_b[now]=true;
        log_b.emplace_back(now);

        for(int i=0;i<tree[now].size();i++){
            int cur = tree[now][i];
            if(!visited_b[cur]){
                visited_b[cur]=true;
                q.push(cur);
            }
        }
        
    }
};

int main(){
    std::cin.tie(0);
    ios_base::sync_with_stdio(false);

    int v,e,s;
    

    std::cin >> v >> e >> s;

    for(int i=0;i<e;i++){
        int v1,v2;
        std::cin >> v1 >> v2;
        tree[v1].emplace_back(v2);
        tree[v2].emplace_back(v1);
    };

    dfs(s);
    bfs(s);

    for(int i=0;i<log_d.size();i++){
        std::cout << log_d[i] << " ";
    };
    std::cout << '\n';


    for(int j=0;j<log_b.size();j++){
        std::cout << log_b[j] << " ";
    };
    std::cout << '\n';




}
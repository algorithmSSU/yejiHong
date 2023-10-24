#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int k;
int v, e;
vector<int> graph[200001];
int visited[200001];

#define RED 1
#define BLUE 2

void bfs(int start){
    queue<int> q;
    int color = RED;
    visited[color] = color;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(visited[cur]==RED){
            color = BLUE;
        }else if(visited[cur]==BLUE){
            color = RED;
        }

        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(!visited[next]){
                visited[next] = color;
                q.push(next);
            }
        }
    }
}


bool isBgraph(){
    for(int i=1;i<=v;i++){
        for(int j=0;j<graph[v].size();j++){
            int next = graph[i][j];
            if(visited[i] == visited[next]){
                return 0;
            }   
        }
    }
    return 1;
}


void init(){
    // 색깔 정보 저장해두는 배열 초기화
    memset(visited,0,sizeof(visited));

    // 그래프 정보 초기화
    for(int i=0;i<=v;i++){
        graph[i].clear();
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> k; // TEST Case 갯수
    vector<bool> answer;

    while(k--){
        cin >> v >> e;
        for(int i=0;i<e;i++){
            int a, b;
            cin >> a >> b;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }

        for(int j=1;j<=v;j++){
            if(!visited[j]){
                bfs(j);
            }
        }

        // 이분그래프확인
        bool Test = isBgraph();
        // 결과 담기
        answer.emplace_back(Test);
        // 초기화
        init();
    }

    for(int i=0;i<answer.size();i++){
        if(answer[i]==false){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
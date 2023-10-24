#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <memory>

using namespace std;

#define MAX 200001

vector<int> graph[MAX];
int visited[MAX]; // 색상정보저장
int K, v, e;

#define RED 1
#define BLACK 2


void dfs(int start){
    if(!visited[start]){
        visited[start]= RED;
    }

    // 시작 노드와 연결된 연결 노드들의 정점은 다른 색깔로 라벨링

    for(int i=0;i<graph[start].size();i++){
        int next = graph[start][i];
        if(!visited[next]){
            if(visited[start]==RED){
                visited[next]=BLACK;
            }else if(visited[start]==BLACK){
                visited[next]=RED;
            }
            dfs(next);
        }
    }
}

void init(){
    // visited 배열 초기화
    memset(visited,0,sizeof(visited));



    // graph 배열 초기화
    for(int i=0;i<=v;i++){
        graph[i].clear();// ??
    }
}


bool isBGraph(){
    for(int i=1;i<=v;i++){
        for(int j=0;j<graph[i].size();j++){
            int next = graph[i][j];
            if(visited[i] == visited[next]){
                return false;
            }
        }
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    vector<bool> answer;

    while(K--){
        cin >> v >> e;

        // edge 갯수 만큼 정점 정보 받기
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }

        // 입력받은 그래프 탐색
        for(int j=1;j<=v;j++){
            // 방문하지 않았다면 정점 방문하기
            if(!visited[j]){
                dfs(j);
            }
        }

        bool result = isBGraph(); // 이분그래프맞냐? 확인
        init(); // 초기화

        // if(result==true){
        //     cout << "YES" << endl;
        // }else{
        //     cout << "NO" << endl;
        // }


        answer.emplace_back(result);
    }

    for(auto it : answer){
        if(!it){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
using std::pair;

#define SIZE 1000
bool visited[SIZE];
vector<pair<int, int>> v[SIZE];

void dfs(int start, int dist);

int max_dist;
int max_node;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int index;
    int dot, edge;
    int first = 1;
    cin >> n;

    for (int i = 0; i < n;i++){
        cin >> index;
        while(1){
            cin >> dot;
            if(dot==-1){
                break;
            }
            cin >> edge;
            v[index].push_back(make_pair(dot, edge));
        };
    };

    dfs(first, 0); // 임의의 정점 1부터 시작, 초기 비용은 0으로 셋팅
    memset(visited, false, sizeof(visited));

    cout << "max_node: "<< max_node << endl;

    dfs(max_node, 0); // max_node를 시작으로, 초기 비용은 0으로 셋팅
    cout << "max_dist: "<< max_dist << endl;
    
};



void dfs(int start, int dist){
    int next, cost;
    visited[start] = true;

    if(max_dist<dist){
        max_dist = dist;
        max_node = start;
    };

    for (int i = 0; i < v[start].size();i++){
        next = v[start][i].first;
        cost = v[start][i].second + dist; // 이동할 때 마다 그 앞에서 발생한 비용도 더해주기

        if(!visited[next]){
            visited[next] = true;
            dfs(next, cost);
        };
    };
};
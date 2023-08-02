#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
using std::pair;
#define SIZE 1000
bool visited[SIZE];
vector<pair<int, int>> v[SIZE];

void dfs(int start, int dist);

int max_dist;
int max_node;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int first = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n;i++){
        int index, dot, edge;
        cin >> index;
        while(1){
            cin >> dot;
            if(dot==-1){
                break;
            };
            cin >> edge;
            v[index].push_back({dot, edge});
        };
    };


    dfs(2, 0);
    //cout << max_node;
    

    
    memset(visited, false, sizeof(visited));
    dfs(max_node, 0);
    cout << max_dist;

    return 0;
};

void dfs(int start,int dist){
    visited[start] = true;
    
    if(max_dist <dist){
        max_dist = dist;
        max_node = start;
    }

    for (int i = 0; i < v[start].size();i++){
        int nv = v[start][i].first;
        int nc = v[start][i].second + dist;

        if(!visited[nv]){
            visited[nv] = true;
            dfs(nv, nc);
        }
    }
}
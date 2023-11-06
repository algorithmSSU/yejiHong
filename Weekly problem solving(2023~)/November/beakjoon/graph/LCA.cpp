#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;

#define MAX 100001

int n,m;
vector<int> adj[MAX];
int parent[MAX][18]; // parent[i][j] : i번 노드의 2^j 번째 조상
int level[MAX], maxlevel;

void set_Tree(int node, int pnode, int lv){
    level[node] = lv;
    parent[node][0] = pnode;

    // maxlevel 만큼 돌면서 parent 배열 업데이트 
    for(int i=1;i<=maxlevel; i++){
        parent[node][i] = parent[parent[node][i-1]][i-1];
        // parent node의 부모
    }

    
    // 인접 리스트에서 노드위치에 저장된 배열의 크기만큼 돌기
    for(int i = 0; i<adj[node].size(); i++){
        int childnode = adj[node][i];
        if(childnode == pnode){ // childnode 가 부모노드이면
            continue;
        }
        // childnode 가 부모노드가 아니면 다리 childnode 부터 다시 트리 형성할 수 있게 재귀
        set_Tree(childnode, node, lv+1); 
    }
}


int LCA(int a, int b){
}


int main(){

}
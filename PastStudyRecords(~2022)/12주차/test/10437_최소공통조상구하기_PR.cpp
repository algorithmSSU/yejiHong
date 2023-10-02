#include <iostream>
#include <vector>
#define max 100
using namespace std;
/*
입력 값
10  노드의 갯수
9   간선의 갯수
1 2
2 3
4 5
1 4
2 6
4 7
6 9
6 10
10 8
*/
vector<int> adj[max];
bool visit[max] = {false};
int depth[max];   // 깊이를 저장
int parents[max]; // 각 노드들의 부모를 저장
int V, E;

// 노드들의 깊이와 부모를 설정해주는 DFS 함수
void DFS(int node, int dep)
{
    visit[node] = true;
    depth[node] = dep;
    for (int i = 0; i < adj[node].size(); i++)
    {
        int next_node = adj[node][i]; // 연결된 노드
        if (visit[next_node])         // 방문했으면 그냥 넘어감
        {
            continue;
        }                          // 만약 방문만 정점이면 탐색x
        parents[next_node] = node; // 다음노드의 부모는 현재노드가 된다. (위에서 부터 탐색하므로)
        DFS(next_node, dep + 1);   // 다음노드와 깊이를 +1해준다.
    }
};

int LCA(int node_a, int node_b)
{

    // 만약 두 노드가 같으면 노드 반환
    if (node_a == node_b)
    {
        return node_a;
    }

    /* 두 노드가 같아 질 때 까지 아래 과정 수행*/

    //두 노드의 깊이가 같을 때
    if (depth[node_a] == depth[node_b])
    {
        return LCA(parents[node_a], parents[node_b]);
    }

    //만약 node_a가 더 깊이가 깊을 때
    else if (depth[node_a] > depth[node_b])
    {
        return LCA(parents[node_a], node_b);
    }

    // 만약 node_b가 더 깊이가 깊을 때
    else
    {
        return LCA(node_a, parents[node_b]);
    }
}
int main(void)
{
    cin >> V >> E;
    // 인접 리스트 생성
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1, 0);         // 1이 루트이므로 1 먼저 탐색하여 깊이를 구해준다.
    cout << LCA(4, 7); //노드4와 노드7의 최소 공통 조상 출력
}

/*

1. 노드의 깊이를 확인한다.
2. 만약 하나가 다른 노드보다 작다면 깊이 -1을 해준다.
3. 만약 깊이가 같다면 두 노드 모두 깊이 -1을 해준다.
4. 깊이 -1을 해주면서 노드가 같아지는 지점을 찾는다.
5. 같아지는 지점이 곧 최소 공통조상이 된다.


*/
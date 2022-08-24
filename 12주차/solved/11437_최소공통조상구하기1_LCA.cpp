#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000
vector<int> graph[MAX];      // 연결 그래프
int parent[MAX];             // 각 노드별 부모를 담을 배열
int depth[MAX];              // 각 노드별 깊이 담을 배열
bool visited[MAX] = {false}; // 방문체크를 위한 배열
vector<int> ans;
int N, M;

void dfs(int s, int d);
int LCA(int node_a, int node_b);

/*각 노드별 부모와 깊이를 계산해주자*/
void dfs(int start, int dep)
{
    visited[start] = true;
    depth[start] = dep;
    for (int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if (visited[next])
        {
            continue;
        }
        parent[next] = start;
        dfs(next, dep + 1);
    }
};

// LCA 함수 부분이 이해가 잘 안됨;

/*깊이를 맞춰서 최소 공통 조상을 찾자*/
int LCA(int node_a, int node_b)
{

    // 부모를 node_a에 위치시키고 있음
    if (node_a == node_b)
    {
        return node_a;
    };

    // 깊이가 같으면 노드끼리 비교할 수 있음?..
    if (depth[node_a] == depth[node_b])
    {
        return LCA(parent[node_a], parent[node_b]);
    }
    else if (depth[node_a] > depth[node_b])
    {
        return LCA(parent[node_a], node_b);
        // node_a의 부모, node_b
    }
    else
    {
        return LCA(node_a, parent[node_b]);
    };
};




int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    };

    dfs(1, 0); // root node 1부터 깊이 1
    cin >> M;
    for (int j = 0; j < M; j++)
    {
        int a, b, result;
        cin >> a >> b;
        result = LCA(a, b);
        ans.push_back(result);
    };

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    };
};

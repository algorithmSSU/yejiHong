#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100009;
vector<int> arr[MAX];
bool visited[MAX] = {
    false,
};
int load_info[MAX] = {
    0,
};
int node_count[MAX] = {
    0,
};
int edge[MAX] = {
    0,
};
int n, m;

//
int walk = 0; // 간선의 수
int node = 0; // 방문노드 수

void dfs(int start, int load)
{
  load_info[start] = load; // 일단 경로정보에 경로번호를 넣어준다. (끝까지 돌았을때까지 )
  node_count[load]++;      // 경로에 방문 노드 수
  edge[load] += arr[start].size();
  for (int i = 0; i < arr[start].size(); i++)
  {
    int next = arr[start][i];
    if (!visited[next])
    {
      visited[next] = true;
      // edge[load]++; // 간선의 수
      dfs(next, load);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < m; ++i)
  {
    int a, b;
    cin >> a >> b;
    arr[a].emplace_back(b);
    arr[b].emplace_back(a);
  }

  int start_number = 0;
  // dfs 탐색
  for (int i = 1; i <= n; ++i)
  {
    if (!visited[i])
    { // 방문하지않았다면
      visited[i] = true;
      dfs(i, ++start_number);
      edge[start_number] /= 2;
    }
  }

  int index = 1;
  for (int i = 2; i <= start_number; ++i)
  {
    if (edge[i] * node_count[index] > edge[index] * node_count[i])
    {
      index = i;
    }
    else if (edge[i] * node_count[index] == edge[index] * node_count[i])
    {
      if (node_count[i] < node_count[index])
      {
        index = i;
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (load_info[i] == index)
    {
      cout << i << " ";
    }
  }

  return 0;
}
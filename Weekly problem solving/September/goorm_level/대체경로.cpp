#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1009;
int n, m, start, dest;
int danger = 0;
vector<int> arr[MAX];
bool visited[MAX] = {
    false,
};

void init()
{
  for (int i = 0; i < MAX; i++)
  {
    visited[i] = false;
  }
}

int bfs()
{
  queue<pair<int, int>> q;
  int cost = 1; // 출발지점도 카운팅해주므로

  if (danger == start || danger == dest)
  {
    return -1;
  }
  // 언제나 시작점부터 출발
  q.push(make_pair(start, cost));
  while (!q.empty())
  {
    int cur = q.front().first;
    int c = q.front().second;
    visited[cur] = true;

    q.pop();
    if (cur == dest)
    {
      return c;
    }

    for (int i = 0; i < arr[cur].size(); i++)
    {
      int next = arr[cur][i];

      if (!visited[next] && next != danger)
      {
        visited[next] = true;
        q.push(make_pair(next, c + 1));
      }
    }
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> start >> dest;

  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    arr[x].emplace_back(y);
    arr[y].emplace_back(x);
  }

  for (int i = 1; i <= n; i++)
  {
    danger = i;
    cout << bfs() << '\n';
    init();
  }
}
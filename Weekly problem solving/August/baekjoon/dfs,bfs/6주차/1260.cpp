#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
#define SIZE 2000

int N, M, n;
bool visited_dfs[SIZE];
bool visited_bfs[SIZE];
vector<int> a[SIZE];

void dfs(int start);
void bfs(int start);

int main()
{

    cin >> N >> M >> n;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        sort(a[x].begin(), a[x].end());
        sort(a[y].begin(), a[y].end());
    };

    dfs(n);
    cout << "\n";
    bfs(n);
};

void dfs(int start)
{
    visited_dfs[start] = true;
    cout << start << " ";

    for (int i = 0; i < a[start].size(); i++)
    {
        int e = a[start][i];
        if (!visited_dfs[e])
        {
            dfs(e);
        };
    };
};

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    cout << start << " ";
    visited_bfs[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        // visited[x] = true;

        for (int i = 0; i < a[x].size(); i++)
        {
            int e = a[x][i];
            if (!visited_bfs[e])
            {
                visited_bfs[e] = true;
                cout << e << " ";
                q.push(e);
            }
            else if (visited_bfs[e])
            {
                continue;
            }
        }
    }
}
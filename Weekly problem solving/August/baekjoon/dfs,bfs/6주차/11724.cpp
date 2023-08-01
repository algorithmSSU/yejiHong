#include <iostream>
#include <vector>
using namespace std;

bool visited[1001];
vector<int> v[1001];

void dfs(int i);

/*  use DFS Algorithm


  undirected graph, that is (1,2) == (2,1)
  Nodes connected to the vertex After all visits,
  exit dfs and search for nodes connected to the next node*


  After visiting all nodes connected to the corresponding vertex
  (vistied[i]=true;) Then, by checking the visited nodes
  If it is not visited, the count
  (the number of connected elements) is increased and the node starts again
  All nodes connected to the corresponding node are visited and visited[i]=true.



    1225513446*/

int main()
{
    int count;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    };

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i);
            // cout << count << endl;
        }
    }

    cout << count << endl;
};

void dfs(int k)
{
    visited[k] = true;
    for (int i = 0; i < v[k].size(); i++)
    {
        int y = v[k][i];
        if (visited[y] == false)
        {
            dfs(y);
        }
    }
}

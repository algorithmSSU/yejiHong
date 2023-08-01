#include <vector>
#include <stack>
using namespace std;

vector<int> arr[100001];
bool visited[100001] = {
    false,
};
int record[100001] = {
    0,
};
int foot = 0;

void dfs(int start)
{
    visited[start] = true;
    record[start] = ++foot;
    for (int i = 0; i < arr[start].size(); i++)
    {
        int next = arr[start][i];
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

int main()
{

    int v, e, start;
    scanf("%d %d %d",&v, &e, &start);
    //cin >> v >> e >> start;

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        arr[a].emplace_back(b);
        arr[b].emplace_back(a);
    };

    for (int i = 0; i < e; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    };

    dfs(start);
    for (int i = 1; i <= v; i++)
    {
        printf("%d\n",record[i]);
    };
}
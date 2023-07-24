#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
vector<int> v[100001];
int record[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    vector<int> ans;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].emplace_back(a);
    };

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        int cnt = 0;
        bool visited[100001] = {
            false,
        };
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            cout << cur << endl;
            q.pop();
            visited[cur] = true;
            if (v[cur].size() == 0)
            {
                break;
            }
            for (int j = 0; j < v[cur].size(); j++)
            {
                int next = v[cur][j];
                if (!visited[next])
                {
                    record[i]++;
                    // cnt++;
                    q.push(next);
                    visited[next]=true;
                }
            }
        }

        max = record[i] < max ? max : record[i];
    };

    for (int i = 1; i <= n; i++)
    {
        if (record[i] == max)
            cout << i << " ";
    }

    return 0;
}
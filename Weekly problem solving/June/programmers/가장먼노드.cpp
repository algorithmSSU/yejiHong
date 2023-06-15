#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int maxlen = 20001;
vector<int> tree[20001];
int *dist;
bool visited[20001] = {
    0,
};

int d = 1;

void bfs(int start)
{

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < tree[now].size(); i++)
        {
            int cur = tree[now][i];
            if (visited[cur] == 0) // 방문하지않았으면
            {
                visited[cur] = true;
                q.push(cur);
                dist[cur] = dist[now] + 1;
                // cout << cur <<dist[now]+1 << endl;
            }
        }
    }
}

int solution(int n, vector<vector<int> > edge)
{
    int answer = 0;

    dist = new int[n + 1];
    dist[1] = 1;

    for (int i = 0; i < edge.size(); i++)
    {
        tree[edge[i][0]].emplace_back(edge[i][1]);
        tree[edge[i][1]].emplace_back(edge[i][0]);
    }

    bfs(1);

    int maxv = 0;
    for (int i = 0; i < n; i++)
    {
        maxv = maxv < dist[i] ? dist[i] : maxv;
    };

    for (int i = 0; i <= n; i++)
    {
        if (maxv == dist[i])
        {
            answer++;
        }
    }

    return answer;
};

int main(){

};
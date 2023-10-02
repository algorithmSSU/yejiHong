#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;
/*
edge가 작은게 앞으로 올 수 있도록 정렬
edge가 작은게 먼저 방문

크루스칼 알고리즘 구현 문제
union find
*/

#define VERTEX 10001
#define EDGE 100001

int dist[VERTEX] = {
    0,
};
int v, e;
priority_queue<pair<int, pair<int, int>>> pq;
int dfs(int start)
{
    int total = 0;
    dist[start] = 0;

    int next_vertex, next_cost;
    int element = pq.size();
    while (!pq.empty())
    {
        element--;
        next_vertex = pq.top().second.second;
        next_cost = pq.top().first;
        dist[next_vertex] = dist[pq.top().second.first] + next_cost;
        total += next_cost;
        pq.pop();

        if (next_vertex == v)
        {
            return total;
        }
        if (element == element - 1)
        {
            return total;
        }
    };
    return total;
}
int main()
{

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        pq.push(make_pair(cost, make_pair(start, end)));
    }

    int answer;
    answer = dfs(1);

    cout << answer << endl;
}
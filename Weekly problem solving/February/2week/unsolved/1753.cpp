#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
#include <stack>

// 메모리 초과..?
using namespace std;
using std::pair;

int v, e, s; //
vector< pair<int, int> > input[20001];
const int INF = 1000;
int dist[20001];

void dfs(int start)
{
    dist[start]=0;

    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int cur = s.top();
        s.pop();

        for(int i=0;i<input[start].size();i++){
            int next,cost;
            next =input[start][i].first;
            cost =input[start][i].second;
            dist[next]=min(dist[start]+cost,dist[next]);
            s.push(next);
        }

    }
}

int main()
{

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    cin >> s;

    int *visited = new int[v];
    memset(dist, 0x3f, sizeof(int) * 20001);

    for (int i = 0; i < e; i++)
    {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        input[v1].push_back(make_pair(v2, c));
    };

/*
    for (int i = s; i <= v; i++)
    {
        dfs(i);
    }
*/


    dfs(s);
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] >= 0x3f)
        {
            cout << "INF" << endl;;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
}
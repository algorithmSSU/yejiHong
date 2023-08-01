#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <memory.h>

using namespace std;
using std::fill;
bool visit[1000] = {false};
vector<int> graph[1000];
void dfs(int num);
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int d, edge;

    //cin >> d >> edge;

    
    do{
        cin >> d >> edge;
        for (int i = 0; i < edge; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        };
        memset(visit, false, sizeof(visit));

        dfs(1);

    } while (d != 0 && edge != 0);
    

    /*
        while(d!=0 && edge!=0){

            cin >> d >> edge;
            for (int i = 0; i < edge;i++){
                int x, y;
                cin >> x >> y;
                graph[x].push_back(y);
                graph[y].push_back(x);
            };
            dfs(1);
        };
    */
};

void dfs(int num)
{
    queue<int> q;
    int cnt = 0;
    q.push(num);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        visit[now] = true;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (!visit[next])
            {
                q.push(next);
                cout << "next: " << next << endl;
                cnt++;
            };
        };
    };
    cout << cnt << endl; // 일단 테스트
}
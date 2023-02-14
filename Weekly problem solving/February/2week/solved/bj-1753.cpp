/*다익스트라구현*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using std::pair;



#define INF 1000000      // 경로가 없는 경우 비용 =>최대값으루
#define MAX_VERTEX 20001 // 최대 vertex 개수
#define MAX_EDGE 300001


vector< pair<int, int> > input[MAX_EDGE];
int dist[MAX_VERTEX];

void dijkstra(int start)
{
    dist[start]=0;

    priority_queue< pair<int, int> > q;
    q.push(make_pair(0,start));
    while(!q.empty()){
        int cur = q.top().second;
        int start_to_cur = -q.top().first;
        q.pop();


        if(dist[cur]<start_to_cur){
            continue;
        }
        for(int i=0;i<input[cur].size();++i){
            int next;
            int start_to_next;
            next =input[cur][i].second;// 정점
            start_to_next = input[cur][i].first + start_to_cur; // edge cost + 현재위치 cost
            if (start_to_next < dist[next])
            {
                dist[next] = start_to_next;
                q.push(make_pair(-start_to_next, next));
            }
        }

    }
}

int main()
{
    int v, e, s;
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    cin >> s; // start vertex

    for(int i=0;i<v+1;i++){
        dist[i]=INF;
    }


    for (int i = 0; i < e; i++)
    {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        input[v1].push_back(make_pair(c, v2));
        // edge cost 를 첫번째 원소, 연결된 정점을 두번째 원소로
    };

    dijkstra(s);


    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << endl;;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
    return 0;
}
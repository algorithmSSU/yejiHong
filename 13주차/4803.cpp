#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <memory.h>
#include <set>


/*입출력 좀더 보완 하기*/


using namespace std;
using std::fill;
bool visit[1000] = {false};
//vector<vector<int>> graph(1000); //2중벡터사용
void dfs(int num, vector<vector<int>> g);

int d, edge;
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    do
    {
        vector<vector<int>> graph(1000); // 2중벡터사용
        cin >> d >> edge;

        if(d==0 && edge ==0){
            break;
        };

        for (int i = 0; i < edge; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        };

        memset(visit, false, 1000);

        dfs(1,graph);

        //fill(graph.begin(), graph.end(), vector<int>(1000, 0));

    } while (d != 0 && edge != 0);

};

void dfs(int num, vector<vector<int>> graph)
{
    queue<int> q;
    stack<int> s;
    bool sub = false;
    int cnt = 0;
    q.push(num);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        visit[now] = true;
        s.push(now);

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];

            //cout << "s.top: " << s.top() << endl;
            //cout << "next:" << next << endl;
            //s.push(next);
            if (!visit[next])
            {
                //visit[next] = true;
                q.push(next);
                cnt++;
            };
        };
    };
    int s_size = s.size();
    set<int> check;
    while(!s.empty()){
        check.insert(s.top());
        s.pop();
    };
    
    if(s_size!=check.size()){
        cout << "No trees." << endl;
    }else if(cnt== d-1){
        cout << "There is one tree" << endl;
    }else if(d>cnt){
        cout << "A forest of" << cnt << "trees" << endl;
    };

    //cout << cnt << endl; // 일단 테스트
}
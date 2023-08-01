#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <memory.h>
#include <set>
#include <string.h>

/*트리 문제 채점 16% 틀림

질문에서 반례 참고해서 수정해야함
-> 반례 해결

근데 아직도 틀렸다고 나옴 */

using namespace std;
using std::fill;
bool visit[1000] = {false};
// vector<vector<int>> graph(1000); //2중벡터사용
void dfs(int num, vector<vector<int>> g, int cnt);
void result(int num,int cnt,int count);
vector<int> ans;
int tree_count[1000];

int d, edge;
int count = 0;
int tree;
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    do
    {
        vector<vector<int>> graph(1000); // 2중벡터사용
        cin >> d >> edge;
        count++;
        tree = 0;
        int answer = 0;

        if (d == 0 && edge == 0)
        {
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

        for (int i = 1; i <= d;i++)
        {
            dfs(i, graph, count);
            memset(visit, false, 1000);
        };

        answer = tree - 1;
        if(answer==d-1 || answer==1){
            ans.push_back(2);
        }else if(answer==-1){
            ans.push_back(1);
        }else{
            ans.push_back(3);
        }

    } while (d != 0 && edge != 0);

    

    int c = 0;

    for (int i = 0; i < ans.size();i++){
        c++;
        int temp = ans[i];
        result(temp, c ,tree_count[c]);
    };
};

void dfs(int num, vector<vector<int>> graph,int count)
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

        if(graph[now].size()==0){ // 연결이 없는 정점은 돌 필요 x
            return;
        };

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];

            // cout << "s.top: " << s.top() << endl;
            //s.push(next);
            if (!visit[next])
            {
                // visit[next] = true;
                q.push(next);

                cnt++;
            };
        };
    };
    int s_size = s.size();
    set<int> check;
    while (!s.empty())
    {
        check.insert(s.top());
        s.pop();
    };

    if(s_size == check.size()){ // 중복이 없으면
        tree++;
    };

    tree_count[count] = tree - 1;
}

void result(int num,int cnt,int count){
    if (num==1){
        cout << "Case " << cnt << ": " << "No trees." << endl;
    };
    if (num==2){
        cout << "Case " << cnt << ": " << "There is one tree." << endl;
    };
    if (num==3){
        cout << "Case " << cnt << ": "<< "A forest of " << count << " trees." << endl;
    }
}
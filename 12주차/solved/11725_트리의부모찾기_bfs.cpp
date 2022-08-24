#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

/*

* 입출력 가속기를 사용할 때는 main 함수에서 사용할 예정인
함수를 main 함수 보다 먼저 선언, 정의 해주어야 하는 듯?

* bfs, dfs 가물가물하다 ..공부하자


*/



int n;
vector<int> arr[MAX];
bool visited[MAX];
int ans[MAX];
void bfs();
void bfs()
{
    queue<int> q;
    visited[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < arr[cur].size(); i++)
        {
            int next = arr[cur][i];
            if (!visited[next])
            {
                ans[next] = cur;
                visited[next] = true;
                q.push(next);
            };
        };
    };
};


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    };

    bfs();

    for (int i = 2; i <= n;i++){
        cout << ans[i] << endl;
    }
};

/*

루트 => 1
1부터 시작하면 1이랑 연결되어 있는 노드 부터 돌 수 있음.

양방향그래프라 (1,2) 같은 경우 (2,1)로도 연결이 되어 있음
따라서 중복을 방지하기 위해 방문을 체크해주어야함.



루트(1) 부터 1과 연결된 서브 노드들의 인덱스에 부모노드(1) 값을 저장
또 다시 그 서브 노드와 연결된 서브 노드들에 방문하면서
서브 노드들의 인덱스에 부모 노드 값을 저장
이런 방식으로 노드 마다 부모 노드를 저장


*/
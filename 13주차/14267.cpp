#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using std::pair;

/*테스트 케이스는 다 맞는데 왜지..*/

vector<int> graph[100000];
vector<int> info[100000];
int N, M;
int new_arr[100000] = {0,};

void solution();

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        graph[i].push_back(temp);
        if (temp != -1)
        {
            graph[temp].push_back(i);
        }
        else
        {
            continue;
        }
    };

    for (int j = 0; j < M; j++)
    {
        int i, w;
        cin >> i >> w;
        info[i].push_back(w);
    };


    solution();
};
void solution()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int now = q.front();
        if (!info[now].empty())
        {
            new_arr[now] += new_arr[now - 1] + info[now][0];
        }
        else
        {
            new_arr[now] = new_arr[now - 1];
        }
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (now < next)
            {
                q.push(next);
            };
        };
    };
    for (int i = 1; i <= N; i++)
    {
        cout << new_arr[i] << " ";
    };
};
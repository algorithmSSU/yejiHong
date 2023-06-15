#include <iostream>
#include <queue>
#include <vector>

/*일단 생각을 좀 더 스케치해보장*/

using namespace std;
using std::pair;

#define MAX 50001

int N, M;
vector<int> info[MAX];
pair<int, int> node[MAX];

// bool visited[MAX];

vector<int> dfs(int num);
int compare(vector<int> a, vector<int> b);

vector<int> dfs(int num)
{
    vector<int> log;
    bool visited[MAX] = {false};
    queue<int> q;
    q.push(num);
    visited[num] = true;

    while (!q.empty())
    {
        int now = q.front();
        log.push_back(now);
        q.pop();

        for (int i = 0; i < info[now].size(); i++)
        {
            int next = info[now][i];

            if (!visited[next])
            { // 방문하지 않았으면
                visited[next] = true;
                q.push(next);
            };
        };
    };

    /*
        cout << "\nlog print" << endl;
        for (int i = 0; i < log.size();i++){
            cout << log[i] << " ";
        };
        cout << "\n";
    */
    return log;
};

int compare(vector<int> a, vector<int> b)
{
    vector<int> b_rank;
    int ans = 50001;
    int answer = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i];
        for (int j = 0; j < b.size(); j++)
        {
            if (x == b[j])
            {
                int temp;
                temp = i + j;
                // ans = ans > temp ? temp : ans;
                // b_rank.push_back(j);
                if (ans > temp)
                {
                    ans = temp;
                    answer = a[i];
                }
                else if (ans == temp)
                {
                    answer = answer < a[i] ? answer : a[i];
                }
            };
        };
    };
    return answer;
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        info[x].push_back(y);
        info[y].push_back(x);
    };
    cout << "-M-" << endl;

    cin >> M;

    for (int j = 0; j < M; j++)
    {
        int x, y;
        cin >> x >> y;
        node[j] = make_pair(x, y);
    };

    for (int i = 0; i < M; i++)
    {
        int a, b;
        vector<int> routelog;
        vector<int> routelog2;
        a = node[i].first;
        b = node[i].second;
        routelog = dfs(a);
        routelog2 = dfs(b);
        cout << compare(routelog, routelog2) << " ";
    }
};

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
bool visit[100001] = {
    0,
};

// 인덱스 숫자 유효성 판별부터!!


int bfs(int n)
{
    int answer = 0;
    queue<pair<int, int> > q;
    int time = 0;
    q.push(make_pair(n, time));

    while (!q.empty())
    {
        int p = q.front().first;
        int t = q.front().second;
        q.pop();

        if (p == k)
        {
            answer = t;
            break;
        }

        int a, b, c;
        a = p - 1;
        b = p + 1;
        c = p * 2;

        if (a > 0 && !visit[a])
        {
            visit[a] = true;
            q.push(make_pair(a, t + 1));
        };
        if (b <= k + 1 && !visit[b])
        {
            visit[b] = true;
            q.push(make_pair(b, t + 1));
        };
        if (c <= k + 1 && !visit[c])
        {
            visit[c] = true;
            q.push(make_pair(c, t + 1));
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;

    cin >> n >> k;

    ans = bfs(n);
    cout << ans << '\n';
}
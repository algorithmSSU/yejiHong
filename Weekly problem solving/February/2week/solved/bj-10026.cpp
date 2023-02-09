#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <memory.h>
using namespace std;
using std::pair;

int n;
char **map = new char *[n];
int visited[100][100] = {
    0,
};

vector< pair<int, int> > G;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, char color)
{
    stack< pair<int, int> > s;

    s.push(make_pair(y, x));
    visited[y][x] = 1;

    while (!s.empty())
    {
        int cy = s.top().first;
        int cx = s.top().second;
        s.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            {
                continue;
            };
            if (map[ny][nx] == color && visited[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                s.push(make_pair(ny, nx));
            }
        }
    }
}
int main()
{

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        map[i] = new char[n];
    };

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int s = str.length();
        for (int j = 0; j < s; j++)
        {
            if (str[j] == 'G')
            {
                G.push_back(make_pair(i, j));
            };
            map[i][j] = str[j];
        };
    };

    int count = 0;
    vector<int> counting;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 'R' && visited[i][j] == 0)
            {
                dfs(i, j, 'R');
                count++;
            };
            if (map[i][j] == 'G' && visited[i][j] == 0)
            {
                dfs(i, j, 'G');
                count++;
            }
            if (map[i][j] == 'B' && visited[i][j] == 0)
            {
                dfs(i, j, 'B');
                count++;
            };
        };
    };

    counting.push_back(count); // 적록색약 아닌 사람이 보는 갯수
    cout << count << " ";

    int gsize = G.size();
    for (int i = 0; i < gsize; i++)
    {
        map[G[i].first][G[i].second] = 'R';
    };

    for (int i = 0; i < n; i++)
    {
        memset(visited[i], 0, sizeof(int) * n);
    };

    int wk = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 'R' && visited[i][j] == 0)
            {
                dfs(i, j, 'R');
                wk++;
            }
            if (map[i][j] == 'B' && visited[i][j] == 0)
            {
                dfs(i, j, 'B');
                wk++;
            };
        };
    };

    counting.push_back(wk);
    cout << wk << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string.h>
#include <memory.h>
#include <queue>
using namespace std;

int row, col;

char m[501][501];
int visited[501][501] = {
    0,
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> next;

int bfs(int y, int x, int gy, int gx)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= row || ny < 0 || nx >= col || nx < 0)
            {
                continue;
            }
            else
            {
                if (m[ny][nx] != 'X' && visited[ny][nx] == 0)
                {
                    visited[ny][nx] = visited[cy][cx] + 1;
                    q.push(make_pair(ny, nx));
                };

                if (ny == gy && nx == gx)
                {
                    return visited[ny][nx];
                };
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int r = 0; r < 501; r++)
        {
            memset(m[r], 0, sizeof(char) * 501);
            memset(visited[r], 0, sizeof(int) * 501);
        }
        cin >> row >> col;
        string input;
        for (int y = 0; y < row; y++)
        {
            cin >> input;
            for (int x = 0; x < input.length(); x++)
            {
                m[y][x] = input[x];
            };
        };

        // R찾으러
        int case1
            // R->외곽
            int case2
        // 외곽->B
        // B->외곽
        // 외곽->도착지
    }
}

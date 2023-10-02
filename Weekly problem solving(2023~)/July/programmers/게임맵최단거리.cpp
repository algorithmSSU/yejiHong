#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    int row = maps.size();
    int col = maps[0].size();

    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {-1, 1, 0, 0};
    bool visited[101][101] = {
        false,
    };

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        visited[cy][cx] = true;

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && nx >= 0 && ny < row && nx < col)
            {
                if (maps[ny][nx] == 1 && !visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    maps[ny][nx] = maps[cy][cx] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    if (visited[row - 1][col - 1])
    {
        if (maps[row - 1][col - 1] == 0 || maps[row - 1][col - 1] == 1)
        {
            answer = -1;
        }
        else
        {
            answer = maps[row - 1][col - 1];
        }
    }
    else
    {
        answer = -1;
    }

    return answer;
}

int main(){

    return 0;
}
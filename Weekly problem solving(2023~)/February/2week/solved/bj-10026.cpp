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

void bfs(int y, int x, char color)
{
    queue< pair<int, int> > q;

    q.push(make_pair(y, x));
    visited[y][x] = 1;

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

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
                q.push(make_pair(ny, nx));
            }
        }
    }
};


int normal(){
    int count = 0;
    vector<int> counting;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 'R' && visited[i][j] == 0)
            {
                bfs(i, j, 'R');
                count++;
            };
            if (map[i][j] == 'G' && visited[i][j] == 0)
            {
                bfs(i, j, 'G');
                count++;
            }
            if (map[i][j] == 'B' && visited[i][j] == 0)
            {
                bfs(i, j, 'B');
                count++;
            };
        };
    };

    return count;
}


int weakness(int green_freq){

    int count =0;

    for (int i = 0; i < green_freq; i++)
    {
        map[G[i].first][G[i].second] = 'R';
    };

    for (int i = 0; i < n; i++)
    {
        memset(visited[i], 0, sizeof(int) * n);
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 'R' && visited[i][j] == 0)
            {
                bfs(i, j, 'R');
                count++;
            }
            if (map[i][j] == 'B' && visited[i][j] == 0)
            {
                bfs(i, j, 'B');
                count++;
            };
        };
    };

    return count;

};



int main()
{

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int res1,res2 = 0;
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

    res1= normal();
    res2= weakness(G.size());
    
    cout << res1 << " " << res2 << endl;


    //=======이차원 배열 할당 해제==========
    for(int i=0;i<n;i++){
        delete[] map[i];
    }

    delete[] map;

    return 0;
}
#include <iostream>
#include <queue>   // use bfs algorithm
#include <stdio.h> // use printf, scanf
#include <cstring> // use memset

#define MAX_SIZE 100

using namespace std;

int N, M;
int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

// 우,하,좌,상
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool IsInside(int ny, int nx)
{
    return (0 <= nx && 0 <= ny && nx < M && ny < N);
}

void bfs(int y, int x)
{
    queue<pair<int, int>> q; // 이용할 큐, (y,x)
    // 처음 y,x를 방문 했기 때문에
    visited[y][x] = true;
    dist[y][x] = 1;

    q.push(make_pair(y, x));
    while (!q.empty())
    {
        // 큐의 현재 원소를 꺼내기
        y = q.front().first;
        x = q.front().second;
        q.pop();

        // 해당 위치의 주변을 확인
        for (int i = 0; i < 4; i++) // 상하좌우 4개
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 지도를 벗어나지 않고, 이동할 수 있는 칸이면서, 아직 방문하지 않았다면
            if (IsInside(ny, nx) && graph[ny][nx] && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1; // 이전 방문값 + 1
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    /* 그래프 및 방문기록, 거리 초기화 */
    memset(graph, false, sizeof(graph)); // 모든 자리의 값을 false 로
    memset(visited, false, sizeof(visited));
    memset(dist, false, sizeof(dist));

    /* 미로(그래프)의 크기 입력*/
    scanf("%d %d", &N, &M);

    /* 그래프 정보 입력 */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &graph[i][j]); // 0 -> false, 1 -> true
        }
    }

    /* 그래프를 BFS를 통해 탐색 */
    bfs(0, 0);

    /* 최소 블럭 개수를 출력 */
    printf("%d\n", dist[N - 1][M - 1]);
    return 0;
}

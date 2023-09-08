#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <memory.h>
#include <map>

using namespace std;

const int MAX = 51;
int n, k, q;
char arr[MAX][MAX];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool visited[MAX][MAX] = {
    false,
};
int cnt = 0;

map<char, int> dict;

vector<pair<pair<int, int>, char>> Q;

void bfs(int y, int x)
{
  queue<pair<int, int>> pos;
  pos.push(make_pair(y, x));
  while (!pos.empty())
  {
    cnt++; // 연결요소카운팅
    int cy = pos.front().first;
    int cx = pos.front().second;
    visited[cy][cx] = true;
    pos.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (ny >= 0 && nx >= 0 && ny <= n && nx <= n && !visited[ny][nx])
      {
        if (arr[ny][nx] == arr[cy][cx])
        {
          visited[ny][nx] = true;
          pos.push(make_pair(ny, nx));
        }
      }
    }
  }
}

void del_visited()
{
  // 그리고 다시 방문배열초기화
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      visited[i][j] = false;
    }
  }
  cnt = 0;
}

void del_All()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (visited[i][j])
      {
        arr[i][j] = '.';
      }
    }
  }

  del_visited();

  // 갯수세주는것도 초기화
  cnt = 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> q;

  for (int i = 1; i <= n; ++i)
  {
    string str;
    cin >> str;
    for (int j = 1; j <= str.length(); ++j)
    {
      arr[i][j] = str[j - 1];
      dict[str[j]]++; // 요소갯수를 세준다.
    }
  }

  for (int i = 0; i < q; i++)
  {
    int y, x;
    char word;
    cin >> y >> x >> word;
    arr[y][x] = word;

    // 이 부분부터 탐색
    dict[word]++;
    if (dict[word] >= k)
    { // 지우는 기준 = k 보다 요소갯수가 많을 경우만 탐색
      // cout << "====" << word << ":" << dict[word] << "====" << endl;
      bfs(y, x);
      if (cnt >= k)
      { // 기준을 넘었다면 방문과 방문한 지점의 요소 삭제
        del_All();
      }
      del_visited(); // 기준을 넘지 않았으면 그냥 방문만 지워준다.
    }
  }

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      cout << arr[i][j];
    }
    cout << '\n';
  }
}
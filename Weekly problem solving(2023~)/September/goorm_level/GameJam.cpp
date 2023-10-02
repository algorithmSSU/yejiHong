#include <iostream>
#include <vector>
#include <memory.h>


using namespace std;

const int MAX = 204;
int cnt[MAX][MAX], visited[MAX][MAX], pos[2][2];
char command[MAX][MAX];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int Play(int y, int x, int N)
{
  memset(visited, 0, sizeof(visited));
  int score = 0;
  visited[y][x] = 1;

  while (1)
  {
    int dir = -1;
    switch (command[y][x])
    {
    case 'R':
    {
      dir = 0; // y,x = 0,1 오른쪽방향으로 증가
      break;
    }
    case 'L':
    {
      dir = 1; // y,x = 0,-1 왼쪽방향으로 감소
      break;
    }
    case 'D':
    {
      dir = 2; // y,x = 1,0 아래 방향으로 내려감
      break;
    }
    case 'U':// y,x = -1,0 위 방향으로 올라감, 즉 y축 감소
    {
      dir = 3;
      break;
    }
    };

    int moveCnt = cnt[y][x];
    while (moveCnt--)
    {
      // y나 x가 n보다 크면 방향대로 더해줌
      // 그러다가 y,x가 n 보다 크면 n을 빼주고(그럼 맨 앞으로 인덱스변경), 0보다 작아지면 맨끝부터 가게 n을 더해준다.
      y += dy[dir], x += dx[dir];
      if (y > N)
        y -= N;
      if (x > N)
        x -= N;
      if (y == 0)
        y += N;
      if (x == 0)
        x += N;
      if (visited[y][x]) // 방문이 되어 있는 곳이면 이동 종료
        goto out; //out 지점으로 한번에 이동?
      visited[y][x] = 1;// 방문이 되어 있지 않으면 방문 체크
    }
  }

out:
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      if (visited[i][j]) // 방문체크를 한 갯수 만큼 score 을 올려준다.
        score++;
  return score;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      cin >> pos[i][j];

  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      cin >> cnt[i][j] >> command[i][j]; // 정수,문자 타입 순서대로 적으면 각각 받게된다..
      /* 이렇게도 되는구나.. 신기*/
  

  int goormScore = Play(pos[0][0], pos[0][1], N); // 시작 위치
  int playerScore = Play(pos[1][0], pos[1][1], N); // 시작 위치

  if (goormScore > playerScore)
    cout << "goorm " << goormScore << '\n';
  else
    cout << "player " << playerScore << '\n';
  return 0;
}
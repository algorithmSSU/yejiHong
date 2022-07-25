#include <iostream>
#include <algorithm>
using namespace std;

int chess[51][51];
/*
black = 0
white = 1
*/

int check(int x, int y)
{
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if ((i + j) % 2 == chess[i][j])
                cnt1++; // 탐색을 시작하는 첫번째 블록이 흰색 일때
            if ((i + j + 1) % 2 == chess[i][j])
                cnt2++; // 탐색을 시작하는 첫번째 블록이 검정색 일때
        }
    }

    return min(cnt1, cnt2); // 둘 중 최소값 반환
}

int main()
{
    int N, M;
    int mini = 2500; // 최소 값
    char c;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    { // B는 '0', W는 '1'로 저장
        for (int j = 0; j < M; j++)
        {
            cin >> c;
            if (c == 'B')
                chess[i][j] = 0;
            else
                chess[i][j] = 1;
        }
    }

    for (int i = 0; i <= N-8; i++)
    { // check(x, y)함수에 탐색을 시작할 인덱스 전달
        for (int j = 0; j <= M-8 ; j++)
        {
            if (mini > check(i, j))
                mini = check(i, j); // 가장 작은 값인지 판별
            
        }
    }

    cout << mini;
}
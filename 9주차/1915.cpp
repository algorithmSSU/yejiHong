#include <iostream>
#include <string>
#include <math.h>

#include <algorithm>
using namespace std;

#define MAX 1010

int N, M;
int MAP[MAX][MAX];

int main()
{

    cin >> N >> M;

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        //문자열 길이만큼 돌면서 CHAR 을 배열에 저장
        for (int j = 0; j < M; j++)
        {
            MAP[i][j] = s[j] - '0';
            //만약 1이 등장하면 최소 크기는 1
            if (MAP[i][j] == 1)
            {
                ans = 1;
            };
        };
    };

    // 1,1 부터 시작 -> 나머지에 대한 계산은 이미 ans에 넣어놔야함.
    // 위에서 1이 출현하면 최소는 1로 해두어서
    // 아래와 같은 예외 방지
    // 3 3
    // 0 0 0
    // 0 0 0
    // 1 0 0

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            if (MAP[i][j] == 1)
            {
                MAP[i][j] = min(min(MAP[i - 1][j - 1], MAP[i - 1][j]), MAP[i][j - 1]) + 1;
                ans = max(MAP[i][j], ans);
            };
        };
    };

    cout << pow(ans, 2); // 넓이

    cout << "\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << MAP[i][j];
        }
        cout << "\n";
    }
};

/*

입력받은 행렬에서
현재 위치에서 왼쪽 대각선 vs 위 -> 최소값 = a
현재 위치에서 왼쪽 값 -> b
a, b 중 더 작은 값을 MAP[i][j]에 업데이트
그리고 ans와 MAP[i][j] 값 중 최대 값으로 ans를 업데이트


*/
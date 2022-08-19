#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;
int child, snack;
int check(int mid);
void solution();

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> child >> snack;
    for (int i = 0; i < snack; i++)
    {
        int temp;
        cin >> temp;
        s.push_back(temp);
    };

    sort(s.begin(), s.end());

    solution();
};

int check(int mid)
{
    int share = 0;
    for (int i = 0; i < snack; i++)
    {
        share += s[i] / mid;
    };
    return share < child;
};

void solution()
{

    int left = 1;
    int right = s.back();
    int answer = 1;

    while (left <= right)
    {
        int mid = 0;
        
        mid = (left + right) / 2;

        if (check(mid))
        {
            right = mid - 1;
        }
        else
        {
            answer = answer > mid ? answer : mid; // answer이 더크면 answer 아니면 mid;
            left = mid + 1;
        };
    };

    if(answer==1){
        cout << 0 << endl;
    }else{
        cout << answer << endl;
    };
};

/*

min, max 값 설정
(min : 1 / max : 15)

while(min<=max 일때),

mid 값 설정(min+max/2)

mid값으로 모든 과자를 나누었을 때
모든 몫의 합 < 아이들 수 -> max 값 범위를 줄여줌 (max = mid -1)
모든 몫의 합 > 아이들 수 -> min 값 범위를 늘려줌 (min = mid +1)
answer = mid;

answer이 1이면, min<=max 일 때 아이들 수 만큼 나누어줄 수 없었던 것
-> 0으로 출력
위의 경우가 아니면
-> answer 출력




*/
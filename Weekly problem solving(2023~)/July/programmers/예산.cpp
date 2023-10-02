// 문제 이해 조금 부족
// 예산을 딱 맞아 떨어지게 쓸 필요없이, 대신 부서별 신청 금액은 딱 맞게
// 최대한 많이 해줄 수 있는 지 확인하는거면 정렬 후 작은것부터 뺴주면 됨...

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;
    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++)
    {
        if (budget - d[i] < 0)
        {
            break;
        }
        answer++;
        budget -= d[i];
    }
    return answer;
}
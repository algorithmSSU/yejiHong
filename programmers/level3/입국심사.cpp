#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    sort(times.begin(), times.end());

    long long min = 1;
    long long max = n * (long long)times.back();

    // max : 대기시간이 제일 긴 곳 * 대기 인원 수 


    // 최소 시간이 max 값을 넘을 때
    // 최대값과 최소값이 바뀌는 구간이 가장 최소 시간이다.

    while (min <= max)
    {

        long long avg = (max + min) / 2;
        long long tmp = 0;

        for (int i = 0; i < times.size(); i++)
        {
            tmp += (avg / (long long)times[i]);
        };

        // 주어진 시간 동안 각 심사데스크에서 몇명을 받을 수 있는 지 검사

        // 모든 심사데스크에서 대기 인원 수 이상으로 받았다면,
        if (tmp >= n)
        {
            max = avg - 1;
            answer = avg;
        }
        // 모든 심사데스크에서 대기 인원 수 미만으로 받았다면,
        else
            min = avg + 1;
    }
    return answer;
};

/*
min: 1
max: 60

avg : 30
max: 29
min : 1

avg : 15
max : 29
min : 16

avg : 22
max : 29
min : 23

avg : 26
max : 29
min : 27

avg : 28
max : 27
min : 27
anwer = 28

avg : 27
max : 27
min : 28


return answer; (28).
.

avg : 34
max : 29
min : 29


*/
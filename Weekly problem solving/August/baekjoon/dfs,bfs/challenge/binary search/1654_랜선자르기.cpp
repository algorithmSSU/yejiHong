#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<long long> num);
vector<long long> nums;
long long n, m;
int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        nums.push_back(temp);
    };

    sort(nums.begin(), nums.end());

    long long answer;
    answer = solution(nums);
    cout << answer << endl;

    return 0;
};

long long solution(vector<long long> num)
{
    long long max = num.back(); // 자를 수 있는 최대 크기
    long long min = 1;
    long long answer = 1;

    while (min <= max)
    {
        long long tmp = 0;
        long long middle = (long long)(max + min) / 2;
        //cout << middle << endl;

        for (int i = 0; i < num.size(); i++)
        {
            tmp += ((long long)num[i] / middle);
        };
        // cout << "tmp:" << tmp << endl;
        if (tmp < m)
        {
            max = middle - 1;
            answer = middle - 1;
        }
        else
        {
            min = middle + 1;
            answer = middle;
        };
    };
    return answer;
};

/*

-> 문제 파악을 제대로 하고 들어갈 것!!

N개의 랜선을 M개의 랜선으로 만드는 방법 중
(모든 랜선의 길이가 같아야 한다.)

랜선의 최대 길이를 구하는 문제


idea
MAX = 주어진 랜선 길이 중 최장 랜선
MIN = 1

int middle = MAX+MIN /2; (대충중간 크기로 먼저 시작)
middle을 N개의 랜선으로 나누었을 때 각각의 몫의 합이
M보다 작으면 middle을 만드는데 개입되는 MAX 를 조정해준다.(MAX = middle-1) &  answer = middle-1로 설정
또는 M보다 크면 middle을 만드는데 개입되는 MIN을 조정해준다. (MIN = middle+1) & answer = middle로 설정

이렇게 MIN 값이 MAX 값 보다 클 때 루프는 종료된다.

return answer;





이전에 풀었던 문제 유형과 비슷
적용의 문제였당.. 이해를 빠르게 해보자..


*/
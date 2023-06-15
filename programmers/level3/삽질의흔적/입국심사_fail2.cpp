#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times);

int main()
{

    long long answer;
    int n;
    vector<int> t;

    n = 5;
    t.push_back(1);
    t.push_back(2);

    answer = solution(n, t);
    cout << answer << endl;
    return 0;
};

long long solution(int n, vector<int> times)
{

    vector<long long> numbers;
    long long answer = 0;

    int info_size = times.size();

    int waiting_p = n - info_size; // 실제로 대기를 해야 하는 사람 수

    int start = 2;
    while (start != waiting_p + 2)
    {
        for (int i = 0; i < times.size(); i++)
        {
            long long temp;
            temp = times[i] * start;
            numbers.push_back(temp);
            // cout << temp << endl;
        }
        start++;
    };

    sort(numbers.begin(), numbers.end());

    answer = numbers[waiting_p - 1];

    return answer;
};
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times);

int main(){

    vector<int> t;
    int n;
    n = 6;
    t.push_back(7);
    t.push_back(10);
    cout << solution(n, t) << endl;
}

long long solution(int n, vector<int> times)
{

    vector<long long> numbers;
    long long answer = 0;

    long long info_size = times.size();

    long long waiting_p = n - info_size; // 실제로 대기를 해야 하는 사람 수

    for (long long i = 2; i < waiting_p + 1; i++)
    {
        for (int j = 0; j < times.size(); j++)
        {
            long long temp;
            temp = times[j] * i;
            numbers.push_back(temp);
        };
    };

    sort(numbers.begin(), numbers.end());

    answer = numbers[waiting_p - 1];

    return answer;
};
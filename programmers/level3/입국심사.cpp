#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long solution(int n, vector<int> times);

int main(){

    int answer = 0;
    int n;
    vector<int> t;

    n = 6;
    t.push_back(7);
    t.push_back(10);

    answer = solution(n, t);
    return answer;
};

long long solution(int n, vector<int> times){

    long long answer = 0;

    int info_size = times.size();

    int waiting_p = n - info_size; // 실제로 대기를 해야 하는 사람 수

    
    



    return answer;
};
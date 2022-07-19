/*1로 시작, 연속1이 아닌 수*/

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

long long d[91];

int main(){

    int num;
    cin >> num;

    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= num;i++){
        d[i] = d[i - 1] + d[i - 2];
    };
    cout << d[num] << endl;
};

/*
https://guiyum.tistory.com/15

진짜 진짜 이해 안감

*/
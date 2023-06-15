#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


string w[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
map<int,int> calendar;



int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int m,d, dd =0;
    string answer;
    cin >> m >> d;

    int mon = 0;
    for(int i=0;i<m;i++){ // 입력된 월의 직전 달까지 모든 일수를 구하기
        mon+=month[i];
    };
    mon+=d; // 입력된 일수더해주기
    mon=mon-1; // 요일 인덱스가 0번째부터 있으니까 인덱스 조정해주기

    cout << w[mon%7] << endl;

}


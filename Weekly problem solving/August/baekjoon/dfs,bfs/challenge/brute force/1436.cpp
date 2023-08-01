#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    int n, cnt = 0;
    cin >> n;

    for(int i = 665;;i++){
        string number = to_string(i);
        if(number.find("666")!=-1){ // ==-1 이면 찾는 게 없다는 뜻
            cnt++; // 이때 카운트를 세주고
        };
        if(cnt==n){
            cout << i << endl;
            break;
        }
    }
};

/*

for(시작 숫자; 언제까지 증가시킬건지; 얼마씩 증가시킬건지);
중간에 언제까지 증가시킬건지를 공란으로 두면 -> while 과 같은 효과


- 풀이 요약
-> 수를 계속 증가시키면서 string으로 바꿔서
string안에 666이 있는지 확인하면서 카운트를 세주면 됨.
1 :666
2 :1666
3 :2666
4 :3666
이런식

- 포인트
find() 함수
문자열과 find함수를 같이 쓰면 정말 간단하게 해결할 수 있음

string text;
text.find("666") -> 있으면 : 인덱스 반환, 없으면 : -1 반환

*/
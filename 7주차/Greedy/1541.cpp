#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
문자열 중에 - 가 있으면
마이너스를 만나기 전, 후 숫자들을 분리해서
before = 마이너스를 만나기 전 숫자들의 합
after = 마이너스 이후의 숫자들의 합
before - after = 정답
*/

int main(int argc, char** argv){
    std:string input;
    int num = 0; // input에서  입력할 숫자들
    int answer = 0; // 리턴할 답
    int flag = 1; // 양수 음수 부호를 결정하는 변수
    cin >> input;
    for(char c : input){
        if(c == '+'){
            answer += num;
            num = 0;
        }
        else if(c=='-'){
            flag = -1;
            answer += num;
            num = 0;
        }
        else{
            num = num * 10 + (c - '0')*flag;
        }
    }
    answer += num;
    cout << answer << endl;
    return 0;
}
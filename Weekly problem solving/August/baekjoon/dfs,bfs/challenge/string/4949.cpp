#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> str;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    
    while(1){
        bool ans = true; // 정상/비정상 체크
        stack<char> check; // 괄호 저장할 stack
        getline(cin, text); // 공백포함! 한 줄 씩 입력받기
        if(text.length()==1 && text[0]=='.'){
            break;
        };

        for (int i = 0; i < text.length();i++){
            char temp;
            temp = text[i];
            if(temp =='(' || temp == '['){
                check.push(temp);
            }
            if(temp==')'){
                if(check.empty()|| check.top()=='['){
                    ans = false;
                }else{
                    check.pop();
                }
            }
            if(temp==']'){
                if(check.empty()||check.top()=='('){
                    ans = false;
                }else{
                    check.pop();
                };
            };
        };
        if(check.empty() && ans){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
            while(!check.empty()){
                check.pop();
                ans = true;
            };
        };
    };

    return 0;
};

/*
key point 

1. 모든 왼쪽 소괄호 '(' 는 오른쪽 소괄호')'와만 바로 만나야한다.
예를 들어 '(' 이거 다음에 ']'이게 오면 안된다.

2. 모든 왼쪽 대괄호 '['는 오른쪽 대괄호 ']'와만 바로 만나야한다.
예를 들어 '[' 다음에 ')' 이게 오면 안된다.

3. 모든 (소,대)괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.

4. 모든 괄호들의 짝은 1:1 매칭만 가능하다.


-> 오른쪽(소,대)괄호들은 stack에 넣어주고,
왼쪽(소,대) 괄호를 만나면 stack에 원소가 있는지,
stack의 최상단 요소가 짝에 맞는 것인지! 확인


*/
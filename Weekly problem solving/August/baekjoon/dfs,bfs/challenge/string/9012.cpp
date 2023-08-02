#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){

    stack<char> s;

    int n;
    cin >> n;
    string ps;


    for (int i = 0; i < n;i++){
        int check = 0;
        bool option = true;
        int open=0, close = 0;
        cin >> ps;
        for (int i = ps.length()-1; i >= 0;i--){
            s.push(ps[i]);
        };
        while(!s.empty()){
            char temp;          
            temp = s.top();
            if(temp=='('){
                open++;
            }else if(temp==')'){
                close--;
            }
            if(abs(open)<abs(close)){
               option = false;
            };
            s.pop();
        };
        check = open + close;
        if(check==0 && option==true){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        };
    };
};

/*

<괄호체크 알고리즘>
stack 자료 구조 이용
1. 모든 괄호를 더했을 때 0이 나와야 함
(쪽수가 맞아야함, (:1/ ):-1 로 취급)
2. 괄호를 하나씩 체크할 때 (괄호갯수보다 )괄호 갯수가 많으면 안됌
(아무리 쪽수가 맞더라도, 닫는 괄호 갯수가 여는 괄호 갯수보다 많으면 안됌)


*/
#include <iostream>
#include <string>
using namespace std;

int main(){

    string text;

    while(1){
        getline(cin, text);
        cout << text << endl;
        if(text==""){
            break;
        }
    };
};

/*

1. cin.getline()
***char 형 문자열을 받을 경우에만 사용할 수 있다.***

2. getline(string)
***string 형 문자열을 받을 경우에 사용할 수 있다.***
***getline은 공백이 포함된 문자열을 입력받기 편하다.***






*/
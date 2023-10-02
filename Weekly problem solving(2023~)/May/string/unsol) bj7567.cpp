#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(){

    stack<char> s;
    stack<char> n;

    string input;
    cin >> input;

    for(int i =0;i<input.length();i++){
        s.push(input[i]);
    };
    
    bool flag= true;
    int score=0;
    while(!s.empty()){
        char cur;
        cur = s.top();
        s.pop();
        if(cur!='('){
            flag = false;
        }
        if(flag){
            if(s.top()==')'){

            }
        }else{
            if(s.top()=='('){
                
            }

        }


    }





}
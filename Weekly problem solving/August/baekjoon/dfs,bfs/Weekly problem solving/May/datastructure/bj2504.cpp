#include <iostream>
#include <string>
#include <stack>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    string input;
    cin >> input;

    int sum=0;
    int temp=1;
    bool check = true;

    stack<char> s;

    for(int i=0;i<input.length();i++){
        if(input[i]=='('){
            s.push(input[i]);
            temp*=2;
        }else if(input[i]==')'){
            if(s.empty() || s.top()!='('){
                check=false;
                break;
            }else{
                if(input[i-1]=='('){
                    sum+=temp;
                }
                s.pop();
                temp/=2;
            };
        }else if(input[i]=='['){
            s.push(input[i]);
            temp*=3;
        }else if(input[i]==']'){
            if(s.empty()||s.top()!='['){
                check=false;
                break;
            }else{
                if(input[i-1]=='['){
                    sum+=temp;
                }
                s.pop();
                temp/=3;
            }
        }
    };

    if(check==false || !s.empty()){
        cout << '0' << endl;
    }else{
        cout << sum << endl;
    }

}
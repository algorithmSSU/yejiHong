//unsol

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
    string input;
    cin >> input;

    stack<pair<char,int> > s;


    int ans = 0;
    for(int i=0;i<input.length();i++){
        int cur_score=1;
        if(s.empty()){
            s.push(make_pair(input[i],i));
        }else{
            int ic=1;
            if(s.top().first=='(' && input[i]==')'){
                ic = i - s.top().second;
                if(ic!=1 || ic%2==1){
                    cout << 0 << endl;
                    break;
                }else{
                    cur_score*=2;
                    s.pop();
                }
                
            }else if(s.top().first=='[' && input[i]==']'){
                ic = i - s.top().second;
                if(ic!=1 ||  ic%2==1){
                    cout<< 0 << endl;
                    break;
                }else{
                    cur_score*=3;
                    s.pop();
                }
            }
        }
    }



}
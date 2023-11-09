#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str, bomb, temp;
    cin >> str >> bomb;
    
    
    stack<char> s;
    for(size_t i=0;i<str.length();i++){
        s.push(str[i]);
        if(s.top()== bomb.back()){
            int bs = bomb.size();
            while(!s.empty() && bs--){
                s.pop();
            }
        }
    };

    string ans="";
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    //reverse(ans.begin(),ans.end());



    if(ans.empty()){
        cout << "FRULA" << endl;
    }else{
        for(int i=ans.length()-1;i>=0;i--){
            cout << ans[i];
        }
        cout <<'\n';
    }
    
}
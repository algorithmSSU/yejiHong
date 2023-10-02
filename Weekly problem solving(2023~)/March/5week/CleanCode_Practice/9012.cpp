#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

void check(string s){
    stack<char> st;
    int count=0;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    };

    while(!st.empty()){
        char cur;
        cur = st.top();
        
        if(cur=='('){
            count++;
        }else if(cur==')'){
            count--;
        }
        if(count>0){
            break;
            v.push_back("NO");
            return;
        }
        st.pop();
    };

    if(count==0){
        v.push_back("YES");
    }else{
        v.push_back("NO");
    }
    
}


int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        check(s); 
    };

    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }

}
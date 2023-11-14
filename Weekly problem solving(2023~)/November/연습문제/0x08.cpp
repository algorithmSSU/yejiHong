#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solution(string s){
  stack<char> st;
  for(auto c : s){
    if(c=='(' || c=='{'){
      st.push(c);
    }else if(c==')') {
      if(!st.empty() && st.top()=='('){
        st.pop();
      }else{
        cout << "error" << endl;
        return;
      }
    }else if(c=='}'){
      if(!st.empty() && st.top()=='{'){
        st.pop();
      }else{
        cout << "error" << endl;
        return;
      }
    }
  }
  if(!st.empty()){
    cout << "error" << endl;
  }else{
    cout << "ok" << endl;
  }

}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  solution(s);

}
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

///  ing


int solution(string s){


  stack<pair<char,int>> st;
  bool flag = false;
  int buf = 1;
  for(int i=0;i<s.size();i++){


    if(s[i] == '(' || s[i] =='['){
      if(st.top()=='(' || st.top()=='[' ){
        flag = true;
        st.push(make_pair(s[i],i));
      }
    }else if(s[i]==')'){
      if(st.empty()){
        return 0;
      }else if(st.top().first=='('){
        if(st.top().second+1<i){

        }
      }
    }
  }
  
  
}

int main(){
  string s;
  cin >> s;


}
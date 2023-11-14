#include <iostream>
#include <vector>
#include <stack>
using namespace std;


bool solution(string s){
  stack<char> st;

  for(auto c : s){
    if(c=='(' || c=='['){
      st.push(c);
    }else if(c==')'){
      if(!st.empty()  && st.top()=='('){
        st.pop();
      }else{
        return false;
      }
    }else if(c==']'){
      if(!st.empty() && st.top()=='['){
        st.pop();
      }else{
        return false;
      }
    }
  }
  if(!st.empty()){
    //cout << "비워져있지않음" << endl;
    return false;
  }
  return true;

}

int main(){

  vector<string> Result;
  while(1){
    string str;
    getline(cin,str);
    cin.clear();

    if(str=="."){
      break;
    }

    bool answer = solution(str);
    if(answer){
      Result.emplace_back("yes");
    }else{
      Result.emplace_back("no");
    }
    
  }
  for(auto it : Result){
    cout << it << endl;
  }
  return 0;


}
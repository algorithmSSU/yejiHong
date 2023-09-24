#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
  int n;
  vector<string> answer;

  cin >> n;

  for(int i=0;i<n;i++){
    string input;
    cin >> input;

    stack<char> s;
    bool flag = true;
    for(int j=0;j<input.length();j++){
      if(input[j]==')' && s.empty()){
        flag = false;
        break;
      }
      if(input[j]=='('){
        s.push('(');
      }else if(input[j]==')' && !s.empty()){
        s.pop();
      }
    }
    if(s.empty() && flag){
      answer.push_back("YES");
    }else if(!s.empty() || flag==false){
      answer.push_back("NO");
    }
  }

  for(int i=0;i<answer.size();i++){
    cout << answer[i] << '\n';
  }

  
}
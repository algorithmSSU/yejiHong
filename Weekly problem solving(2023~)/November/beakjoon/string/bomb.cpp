
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
  cin.tie(0);
  cout.tie(0);

  string str;
  string bomb;

  cin >> str >> bomb;


  int strlen = str.length();
  int bomblen = bomb.length();
  // 스택사용금지..


  string temp ="";

  for(int i=0;i<strlen;i++){
    temp+=str[i];
    if(temp.back() == bomb.back()){
      bool ch = true;

      // temp 크기가 bomb 보다 작으면 무시
      if(temp.size() < bomb.size()){
        continue;
      }

      // temp 크기가 더 크면 bomb 사이즈 만큼 temp 뒤<->bomb뒤 부터 비교
      for(int j=0;j<bomb.size();j++){
        if(temp[temp.size()-bomb.size()+j]!=bomb[j]){
          ch = false;
          break;
        }
      }
      if(ch){
        for(int j=0;j<bomb.size();j++){
          temp.pop_back();
        }
      }
    }
  }

  if(temp.empty()){
    cout << "FRULA" << endl;
  }else{
    cout << temp << endl;
  }
}
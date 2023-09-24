#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;
  getline(cin,str,'\n');

  string answer = "";

  for(int i=0;i<str.length();i++){
    if(str[i]>=65 && str[i]<=90){//대문자일경우
      int next = str[i]+13;
      if(next>90){
        char Next = next-91+65;
        answer+=Next;
      }else{
        answer+=next;
      }
    }else if(str[i]>=97 && str[i]<=122){//소문자일경우
      int next = str[i]+13;
      if(next>122){
        char Next = next-123+97;
        answer+=Next;
      }
      else{
        answer+=next;
      }
    }else{
      answer+=str[i];
    }
  }
  cout << answer << endl;
}
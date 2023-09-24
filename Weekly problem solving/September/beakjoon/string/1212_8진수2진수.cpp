#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
  string number[8] = {"000","001","010","011","100","101","110","111"};
  string str;
  string answer;
  cin >> str;

  for(int i=0;i<str.length();i++){
    int n = str[i]-'0';
    if(i==0){// 맨 앞은 0이 오면 안되니까 number 배열안 값을 정수로 바꿔서 출력
      cout << stoi(number[n]);
    }else{ // 인덱스에 해당하는 2진수 문자열이 출력되도록 출력
      cout << number[n];
    }
  }
  cout << '\n';



  
  
}
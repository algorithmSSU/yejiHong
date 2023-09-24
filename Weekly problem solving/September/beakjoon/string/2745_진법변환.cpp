#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main(){
  string str;
  int B;
  long long int answer = 0;


  cin >> str >> B;


  for(int i=0;i<str.length();i++){
    int num = str[i]-'0';
    if(num<10){
      answer += num*pow(B,str.length()-1-i);
    }else{
      num-=7;
      answer += num*pow(B,str.length()-1-i);
    }
  }
  cout << answer << endl;
  
}

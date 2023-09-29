#include <iostream>
#include <string>
using namespace std;

/*

'0' = asc값으로 48
'A' 를 정수형으로 바꿔주고 싶다면
int num = 'A'-0; 을 하자 (!'0'쓰지말고)

================char int ===================
'A' 의 아스키코드 값은 65 ~ 'Z' 의 아스키코드 값은 90
'a' 의 아스키코드 값은 97 ~ 'z' 의 아스키코드 값은 122
=============================================

*/




int main(){

  int A = 'A';
  int a = 'A'-0;
  int b = (int)'A';

  cout << "A : "<< A << endl;
  cout << "'A'-0 :" << a << endl;
  cout << "'A'-0 :" << typeid(a).name() << endl;
  cout << "(int)'A' : " << b << endl;
  cout << "z: " << (int)'z'  << endl;

  cout << isdigit('3') << endl;
  cout << isdigit('0') << endl;

  int num = 2;
  cout << to_string(num) << endl;

  
}
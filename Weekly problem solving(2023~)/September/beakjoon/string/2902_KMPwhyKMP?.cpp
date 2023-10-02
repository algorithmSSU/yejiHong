#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  string str;
  string ans="";
  cin >> str;

  for(int i=0;i<str.length();i++){
    int num = (int)str[i];
    
    if(num <= 90 && str[i]!='-'){
      ans+=str[i];
    }
  }
  cout << ans << '\n';

}



/*

int A = 'A';
int a = 'A'-'0';
int b = (int)'A';

cout << "A : "<< A << endl;
cout << "'A'-'0' :" << a << endl;
cout << "(int)'A' : " << b << endl;






*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
  string str;
  //str = "ababc";
  cin >> str;
  
  set<string> Set;

  string temp;
  for(int i =0;i<str.length();i++){
    for(int j=1;j<=str.length();j++){
      temp=str.substr(i,j);
      Set.insert(temp);
    }
  }
  cout << Set.size() << '\n';
}
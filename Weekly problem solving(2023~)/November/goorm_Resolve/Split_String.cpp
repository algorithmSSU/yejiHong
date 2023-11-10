#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// abcd
// a b cd
// a bc d
// ab c d

// ok , AGAIN!

map<string,int> splitTomap(string str){
  map<string,int> m;
  map<string,int>::iterator p;
  for(int i=1;i<str.length();++i){
    for(int j=i+1;j<str.length();++j){
      m[str.substr(0,i)]=1; // 0~i 까지
      m[str.substr(i,j-i)]=1; // i~j-i까지
      m[str.substr(j)]=1; // j~끝
    }
  }

  int idx = 0;

  for(p=m.begin(); p!=m.end(); p++){
    p->second+=idx++;
  }

  return m;
}


int solution(string str){
  map<string,int> m;
  m = splitTomap(str);

  int sumMax = 0;
  for(int i=1;i<str.length(); i++){
    for(int j=i+1;j<str.length(); j++){
      int sum = m[str.substr(0,i)]+ m[str.substr(i,j-i)] + m[str.substr(j)];
      sumMax = sumMax < sum ? sum : sumMax;
    }
  }

  return sumMax;
}




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  string str;
  cin >> n;
  cin >> str;


  int answer = solution(str);
  cout << answer << endl;







}
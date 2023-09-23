#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int n;
string str;

/*
🔴 부분문자열 string::substr
🔴 완전탐색 인덱스
*/

map<string,int> stringPiece_Map(){

  map<string,int> Map;// map 은 자동정렬된다!!!!
  map<string,int>::iterator iter;
  for(int i=1;i<str.length();++i){
    for(int j=i+1;j<str.length();++j){
      Map[str.substr(0,i)]=1; // 0부터 i개 추출 // 0 부터 1개
      Map[str.substr(i,j-i)]=1; // i 부터 j-i개 추출 // 1부터 1개
      Map[str.substr(j)]=1; // j부터 끝까지 추출 // 1번부터 끝까지
    }
  }

  // 인덱스 부여
  int setIndex=0;
  for(iter=Map.begin();iter!=Map.end();iter++){
    iter->second+=setIndex++;
  }
  

  return Map;
}

int bruteForece(){
  map<string,int> Map = stringPiece_Map();
  int Max = 0;
  for(int i=1;i<str.length();++i){
    for(int j=1+i;j<str.length();++j){
      int PieceSum = 0;
      PieceSum = Map[str.substr(0,i)] + Map[str.substr(i,j-i)] + Map[str.substr(j)];
      Max = max(Max,PieceSum);
    }
  }
  return  Max;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> str;

  int answer = 0;
  answer = bruteForece();
  cout << answer << '\n';
}
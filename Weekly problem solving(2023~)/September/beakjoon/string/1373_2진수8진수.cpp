#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

int main(){
  string str;
  string answer="";
  string arr[]={"000","001","010","011","100","101","110","111"};
  map<string,char> d;
  for(int i=0;i<8;i++){
    d[arr[i]]+=i+'0';
  }


  cin >> str;

  while(str.length()%3!=0){
    str.insert(0,"0");
  }

  for(int i=0;i<str.length();i+=3){
    string word = str.substr(i,3);
    answer+=d[word];
  }

  cout <<  answer << endl;
}
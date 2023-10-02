#include <iostream>
#include <vector>
#include <string>

using namespace std;


string func(string T,char before, char after){
  string str;
  str = T;
  if(str.find(before)!=str.npos){
    replace(str.begin(),str.end(),before,after);
  }
  return str;
}


int main(){
  string A,B;
  string A_min,B_min,A_max,B_max;
  int Min =0;
  int Max =0;
  cin >>A >>B;

  A_max = func(A,'5','6');
  B_max = func(B,'5','6');

  Max = stoi(A_max) + stoi(B_max);

  A_min = func(A,'6','5');
  B_min = func(B,'6','5');

  Min = stoi(A_min) + stoi(B_min);
  
  cout << Min << " " << Max << endl;




}
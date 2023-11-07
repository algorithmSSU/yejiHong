#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  int test_case;
  int T;
  cin >> T;

  for(test_case = 1; test_case <= T; ++test_case){
    string str;
    string str_half;
    int same = 0;

    cin >> str;

    int len = str.length();

    int len_h;
    if(len%2 == 0){
      len_h = (len/2)-1;
      for(int i=len_h;i>=0;i--){
        str_half+=str[i];
      }
      for(int i=0;i<=len_h;i++){
      if(str_half[i] == str[len_h+i+1]){ 
        same ++;
      }
    }
    }else if(len%2 == 1){
      len_h = len/2;
      for(int i=len_h;i>=0;i--){
        str_half+=str[i];
      }
      for(int i=0;i<=len_h;i++){
        if(str_half[i] == str[len_h+i]){ 
          same ++;
        }
      }
    }

    if(same == str_half.length()){
      cout << "#" << test_case << " " << 1 << endl;
    }else{
      cout << "#" << test_case << " " << 0 << endl;
    }
    
  }
  return 0;

}
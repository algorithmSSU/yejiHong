#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int solution(vector<int> ingredient){
  int cnt = 0;

  string patty = "1231";

  string temp;
  int len = ingredient.size();
  for(int i=0;i<len;i++){
    temp+=ingredient[i]+'0';
    if(temp.back()=='1' && temp.size()>=patty.size()){
      //cout << "here" << endl;
      int j = temp.size()-4;
      int same = 0;
      for(auto it : patty){
        if(it==temp[j]){
          same++;
          j++;
        }
      }
      if(same == patty.size()){
        cnt++;
        int j = temp.size()-4;
        temp.erase(j,4);
      }
    }
  }
  return cnt;
}

int main(){
  vector<int> ig = {1, 3, 2, 1, 2, 1, 3, 1, 2};
  int ans = solution(ig);
  cout << ans << endl;



  
}
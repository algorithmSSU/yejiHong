#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check[1001][1001];
int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int answer = 0;

  string str1,str2;
  string s1,s2;
  
  cin >> s1 >> s2;
  str1 += "_" + s1;
  str2 += "_" + s2;


  int str1_len = str1.length();
  int str2_len = str2.length();

  for(int i=0;i<str1_len;i++){
    for(int j=0;j<str2_len;j++){
      if(i==0 || j==0){
        check[i][j]=0;
        continue;
      }
      if(str1[i]==str2[j]){
        check[i][j] = check[i-1][j-1] +1; 
      }else{
        check[i][j] = max(check[i-1][j],check[i][j-1]);
      }
    }
  }


  cout << check[str1_len-1][str2_len-1] << '\n';

}
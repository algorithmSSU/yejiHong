#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  int answer =0;
  string base;

  cin >> N;
  cin >> base;

  // 기준문자열 속성
  int word[26]={0,};
  for(int i=0;i<base.length();i++){
    word[base[i]-'A']+=1;
  }


  for(int i=0;i<N-1;i++){
    string comp;
    cin >> comp;

    // 복사본
    int word_copy[26];
    copy(word,word+26,word_copy);

    int same = 0;
    for(int j =0;j<comp.length();j++){
      if(word_copy[comp[j]-'A']>0){
        word_copy[comp[j]-'A']--; // 하나줄여주기
        same++;
      }
    }

    int base_len = base.length();
    int comp_len = comp.length();

    if(base_len == comp_len){
      if(same == base_len || same == base_len-1){
        answer++;
      }
    }
    else if(base_len -1 == comp_len && same == base_len -1 ){
      answer++;
    }else if(base_len + 1 == comp_len && same == base_len){
      answer++;
    }else continue;
  }
  cout << answer << endl;
}

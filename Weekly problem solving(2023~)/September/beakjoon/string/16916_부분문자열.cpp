#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

원래 골4 문제인데 왜 브론즈가 되었지?
kmp 알고리즘이라고 따로 푸는 공식이 있었다.
먼저 이해하고 가야했다..

똑똑이들이싫다..

*/

vector<int> failure_table(string pat){
  int plen = (int)pat.length();

  vector<int> fail(plen,0);

  int j=0;
  
  for(int i=1;i<plen;i++){
    while(j>0 && pat[i]!=pat[j]){
      j=fail[j-1];
    }
    if(pat[i]==pat[j]){
      fail[i] = ++j;
    }
  }
  return fail;
}


int KMP(string text,string pat){
  vector<int> fail = failure_table(pat);
  int j=0;

  for(int i=0;i<text.length();i++){
    /*원본과 패턴이 일치하지 않는 경우*/
    while(j>0 && text[i]!=pat[j]){
      j=fail[j-1]; // 미리만들어 놓은 fail 에서 현재 패턴 인덱스 바로 전(-1) 위치에 있는 인덱스값으로 설정
    }

    /*원본과 패턴이 일치할 경우*/
    if(text[i]==pat[j]){ 
      if(j==pat.length()-1){ // 패턴 인덱스 == 패턴 전체 길이 => 원본과 비교한 결과 패턴 모두 일치
        return 1; // 끝!
      }else{ // 현재 패턴의 인덱스가 가리키는 위치 값과 원본 인덱스가 가리키는 값이 같지만, 아직 다 비교한게 아니므로
        j+=1; // 패턴의 인덱스를 옆으로 옮겨준다.
      }
    }
  }
  return 0;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s, p;
	cin >> s >> p;

  int answer =0;
  answer = KMP(s,p);
  cout << answer << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s;
int check = 4; // 4개 이상 넘어가면 리턴
int limit = 1e9;

int pelindrome(int cnt, int startIdx, int endIdx){
  if(cnt>=check){
    return 1e9;
  }
  if(startIdx>=endIdx){
    check=cnt;
    return cnt;
  }

  if(s[startIdx]!=s[endIdx]){
    limit = min(pelindrome(cnt+1,startIdx+1,endIdx),limit);
    limit = min(pelindrome(cnt+1,startIdx,endIdx-1),limit);
  }else{
    limit = min(pelindrome(cnt,startIdx+1,endIdx-1),limit);
  }

  return limit;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;

  int result = pelindrome(0,0,s.length()-1);

  if(result==1e9){
    result = -1;
  }
  cout << result << endl;
}
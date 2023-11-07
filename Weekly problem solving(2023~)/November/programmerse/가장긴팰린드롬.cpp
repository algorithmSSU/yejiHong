#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int len = s.length();
    
    int front = 0;
    int tail = len-1;
    int plen = -1e9;


    // 팰린드롬의 시작 인덱스, 끝인덱스를 저장하자. 아래 수정해야함
    int f_idx = 0;
    int t_idx = 0;
    
    while(1){
        
      int same = 0;
      if(front == tail){
        break;
      }
      while(s[front] == s[tail]){
        if(front==tail){
            same++;
            break;
        }
        same ++;
        
        //cout << s[front] << same << endl;
        front++;
        tail--;
        
      }
        
      plen = max(plen, same); // pailindrome 최대값 갱신
      front=0;
      tail--;

    }
    

    int answer = 0;

    if(plen%2==0){// 짝수이면
      answer = plen*2 - 1;
    }else if(plen%2==1){ // 홀수이면
      answer = plen*2;
    }
    return answer;
}

int main(){
  string str = "abacde";

  int answer= solution(str);

  
  cout << answer << endl;
}
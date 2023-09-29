#include <iostream>
#include <string>

using namespace std;

int n; 
int number[12];
int Operator[4];
int Minv = 1e9;
int Maxv= -1e9;

void search(int value, int cnt){
  //종료조건
  if(cnt==n-1){
    //연산끝나고 최소값, 최대값 갱신
    Maxv =max(Maxv,value);
    Minv =min(Minv,value);
  }

  //연산자만큼 돌아준다.
  for(int i=0;i<4;i++){
    // 연산자가 0 이면 없다는 거니까..
    if(Operator[i] == 0){
      continue;
    }

    Operator[i]--; // 0 이 아니면 있다는 거니까 빼주고 -> 다음턴엣 사용 못되게

    if(i==0){
      search(value+number[cnt+1],cnt+1);
    }else if(i==1){
      search(value-number[cnt+1],cnt+1);
    }else if(i==2){
      search(value*number[cnt+1],cnt+1);
    }else{
      search(value/number[cnt+1],cnt+1);
    }
    Operator[i]++;// 다시 사용할 수 있게...?
  }
  

}





int main(){
  cin >> n;


  // 숫자입력
  for(int i=0;i<n;i++){
    cin >> number[i];
  };

  // 연산자 입력
  for(int i=0;i<4;i++){
    cin >> Operator[i];
  }


  search(number[0],0);

  cout << Maxv << '\n' << Minv << '\n';
}

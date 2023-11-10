#include <iostream>
#include <bitset> // 🌟

using namespace std;
/**
 * 10진수를 2진수로, 이진법변환
 * 
 * 1. 2로 계속해서 나누기 -> 문자열반환
 * 2. 시프트연산자
 * 3. bitset 이용하기
 
*/

// 2로 계속해서 나누기
void sol_1(int num){
  string binary;

  while(num!=0){
    if(num%2==1){
      binary+='1';
    }else{
      binary+='0';
    }
    num/=2;
  }

  // 반대로 돌려주기 !
  reverse(binary.begin(),binary.end());
  cout << binary << endl;

}

// 시프트 연산자
void sol_2(int num){
  // 8bit 로 나타내고자할 때
  for(int i=3;i>=0;i--){
    int temp = (num >> i)&1;
    cout << temp;
  }
  cout << '\n';
}

// bitset
void sol_3(int num){
  bitset<4> binary (num);
  cout << binary << endl;
}



int main(){

  // int n =9; // 1001
  // cout << (n>>3) << endl;


  int num = 8;
  sol_1(num);
  sol_2(num);
  sol_3(num);

}
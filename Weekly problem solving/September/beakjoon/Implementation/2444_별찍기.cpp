#include <iostream>
#include <vector>

using namespace std;



void solution(int n){
  int len = 2*n-1; // 9
  int middle = len/2; // 4
  int mom = middle/2; //2


  int ct = middle;

  for(int i=0;i<=middle;i++){
    for(int j=0;j<=i+middle;j++){
      if(j<ct){
        cout << " ";
      }else if(j>=ct){
        cout << "*";
      };
    }
    cout << '\n';
    ct-=1;
  }

  int ctr = len-1;
  for(int i=0;i<middle;i++){
    for(int j=0;j<ctr;j++){
      if(j<=i){
        cout << " ";
      }else if(i<j){
        cout << "*";
      };
    };
    cout << '\n';
    ctr-=1;
  }


}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  solution(n);

  

}
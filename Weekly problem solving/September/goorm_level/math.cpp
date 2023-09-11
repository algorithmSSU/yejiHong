#include <iostream>
#include <math.h>
#include <string.h>



using namespace std;
int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 3;
  int Int[1000];
  char Char[1000];
  for(int i=0;i<n;i++){
    cin >> Int[i] >> Char[i];
  };

  for(int i=0;i<n;i++){
    cout << Int[i] << endl;
  }
}
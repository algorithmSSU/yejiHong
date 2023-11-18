#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int N,M;
int arr[5];

int main(){
  freopen("input.txt","r",stdin);
  cin >> N;
  for(int i=0;i<=N;i++){
    cin >> arr[i];
  }
  for(int j=0;j<=N;j++){
    cout << arr[j] << endl;
  }
}
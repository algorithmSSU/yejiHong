#include <iostream>
#include <vector>
#include <math.h>
using namespace std;



int map[257][257];
int n;
int blue=0;
int white;

void input(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> map[i][j];
    }
  }
}

void recur(int y,int x,int size){
  bool flag = false;
  int first_color = map[y][x];
  for(int i=y;i<y+size;i++){
    for(int j=x;j<x+size;j++){
      if (first_color != map[i][j])
      {
        flag = true;
        break;
      }
    }
  }

  if(flag){
    recur(y,x,size/2);
    recur(y,x+size/2,size/2);
    recur(y+size/2,x,size/2);
    recur(y+size/2,x+size/2,size/2);
  }else{
    if(first_color==1){
      blue++;
    }else{
      white++;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;


  input(n);
  recur(0,0,n);


  cout << white << '\n' << blue << '\n';

}
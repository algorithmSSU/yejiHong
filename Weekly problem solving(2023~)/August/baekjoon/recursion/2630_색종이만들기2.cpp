#include <iostream>
#include <vector>
#include <math.h>
using namespace std;



int map[129][129]={0,};
int blue;
int white;
int n;

void solve(int y,int x,int size){
  int sum = 0;
  for(int r = y; r<y+size; r++){
    for(int c = x;c<x+size; c++){
      sum+=map[r][c];
    }
  }
  if(sum==pow(size,2)){
    blue++;
  }else if(sum==0){
    white++;
  }else{
    solve(y,x,size/2);
    solve(y,x+size/2,size/2);
    solve(y+size/2,x,size/2);
    solve(y+size/2,x+size/2,size/2);
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> map[i][j];
    }
  }

  solve(0,0,n);
  cout << white << '\n' << blue << '\n';

  

}
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;
int r;
int c;
int map[4096][4096]={0,};
int cnt = 0;
void go(int y,int x,int size){
  if(y==r && x==c){
    cout << cnt << endl;
    return;
  }

  if(r<y+size && c<x+size && y<=r && x<=c){
    //4분면안에들면
    go(y,x,size/2);
    go(y,x+size/2,size/2);
    go(y+size/2,x,size/2);
    go(y+size/2,x+size/2,size/2);
  }else{
    cnt+=size*size;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> r >> c;
  go(0,0,pow(2,n));

  

}
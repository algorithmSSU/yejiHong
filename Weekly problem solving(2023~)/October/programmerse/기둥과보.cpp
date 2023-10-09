#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

  int map[101][101];
  memset(map,0,sizeof(map));
  vector<vector<int> > build_frame{
    {1,0,0,1},
    {1,1,1,1},
    {2,1,0,1},
    {2,2,1,1},
    {5,0,0,1},
    {5,1,0,1},
    {4,2,1,1},
    {3,2,1,1}
  };

  for(auto list : build_frame){
    int y = list[0];
    int x = list[1];
    if(list[2]==0)
      map[y][x]=1;
    if(list[2]==1)
      map[y][x]=2;
  }

  for(int i=0;i<=5;i++){
    for(int j=0;j<=5;j++){
      cout << map[i][j] << " ";
    }
    cout << '\n';
  }
}
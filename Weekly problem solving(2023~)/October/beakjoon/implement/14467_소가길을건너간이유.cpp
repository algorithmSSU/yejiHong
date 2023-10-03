#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n;

int main(){
  cin >> n;
  int cross = 0;

  map<int,bool> walk;

  for(int i=0;i<n;i++){
    int cow, pos;
    cin >> cow >> pos;
    if(walk.find(cow)!=walk.end()){
      if(walk[cow]!=pos){
        cross++;
        walk[cow]=pos;
      }else{
        continue;
      }
    }else{
      walk[cow]=pos;
    }
  }


  cout << cross << endl;
}
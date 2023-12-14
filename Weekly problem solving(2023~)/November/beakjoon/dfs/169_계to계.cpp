#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int Max = -1;
pair<int,int> eggs[10];
bool visited[10];

void kill(pair<int,int> egg, int br, int cnt){

  if(egg.first<=0 || cnt==N-1){
    if(egg.first<=0){
      br+=1;
    }

    Max = max(br,Max);
    cout << "return" << endl;
    return;
  }


  for(int i=0;i<N;i++){
    if(!visited[i]){
      // // 현재 계란과 깨려는 계란이 같은 경우는 패쓰
      // if(eggs[i].first == egg.first && eggs[i].second == egg.second){
      //   continue;
      // }
      visited[i]= true;
      int handle = egg.first - eggs[i].second; // 현재 계란 내구성
      int nextegg = eggs[i].first - egg.second; // 다음 계란 내구성
      if(nextegg<=0){ // 다음 계란이 깨지면
        br++;
      }
      pair<int,int> handle_new = make_pair(handle,egg.second);
      cout << handle_new.first << " " << handle_new.second << " " << br << endl;
      kill(handle_new,br,cnt+1);
      visited[i] = false;
    }

  }
  
}



void input(){
  cin >> N;
  for(int i=0;i<N;i++){
    int power,weight;
    cin >> power >> weight;
    eggs[i] = make_pair(power,weight); // 내구성, 무게
  }
}

void init(){
  for(int i=0;i<N;i++){
    visited[i] = false;
  }
}

int main(){

  input();
  
  for(int i=0;i<N;i++){
    pair<int,int> temp = eggs[i];
    kill(temp,0,0);
    init();
  }

  //kill(eggs[0],0);
  cout << Max << endl;


}
#include <iostream>
#include <vector>

using namespace std;

int arr[9]= {1,2,3,4,5,6,7,8,9};
bool visited[10];
int answer[10];

void backtracking(int cnt){
  if(cnt==3){
    for(int i=0;i<cnt;i++){
      cout << answer[i] << " ";
    }
    cout << '\n';
    return;
  }else{
    for(int i=0;i<9;i++){
      if(!visited[i]){
        visited[i]=true;
        answer[cnt]=arr[i];
        backtracking(cnt+1);
        visited[i]=false;
      }
    }
  }

}
int main(){
  backtracking(0);

  
}
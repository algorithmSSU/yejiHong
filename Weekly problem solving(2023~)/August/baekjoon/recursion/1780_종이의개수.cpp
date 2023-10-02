#include <iostream>
#include <vector>

using namespace std;


// 다시 풀어보기


int map[10000][10000]={0,};

int positive_one = 0;
int negative_one = 0;
int zero = 0;

void paper(int y,int x,int s){
  
  int check = map[y][x];
  bool flag = true;
  for(int i=y;i<s;i++){
    for(int j=x;j<s;j++){
      if(check!=map[i][j]){
        check = false;
        break;
      }
    }
  }
  if(flag){ // 다 같으면 
    if(check == 1){
      positive_one++;
    }else if(check == -1){
      negative_one++;
    }else if(check == 0){
      zero++;
    }
  }else{ // 다르면
    paper(y,x,s/3);
    paper(y,x+s/3,s/3);
    paper(y+s/3,x,s/3);
    paper(y+s/3,x+s/3,s/3);
    
    paper(y+s/3+s/3,x+s/3+s/3,s/3);
    paper(y+s/3+s/3,x+s/3,s/3);
    paper(y+s/3,x+s/3+s/3,s/3);

    paper(y,x+s/3+s/3,s/3);
    paper(y+s/3+s/3,x,s/3);
  }
}


long long int n;
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
  paper(0,0,n);
  
  cout << negative_one << '\n';
  cout << zero << '\n';
  cout << positive_one << '\n';
}
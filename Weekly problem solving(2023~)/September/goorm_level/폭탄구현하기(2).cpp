#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_SIZE = 201;
int n,k;
char map[MAX_SIZE][MAX_SIZE];
int imap[MAX_SIZE][MAX_SIZE]={0,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
queue<pair<int,int> > q;
void bomb(){
  while(!q.empty()){
    int cy = q.front().first;
    int cx = q.front().second;
    if(map[cy][cx]=='0'){
      imap[cy][cx]+=1;
    }else if(map[cy][cx]=='@'){
      imap[cy][cx]+= 2;
    }
    q.pop();
    
    for(int i=0;i<4;i++){
      int ny = cy+dy[i];
      int nx = cx+dx[i];
      
      if(ny>=0 && nx>=0 && ny<n && nx<n){
        if(map[ny][nx]=='#'){
          continue;
        }else if(map[ny][nx]=='0'){
          imap[ny][nx]+= 1;
        }else if(map[ny][nx]=='@'){
          imap[ny][nx]+= 2;
        }
      }
    }
    
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  // n : 한 변의 길이
  // k : 폭탄 떨어뜨릴 횟수

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> map[i][j];
    }
  }
  for(int i=0;i<k;i++){
    int y,x;
    cin >> y >> x;
    q.push(make_pair(y,x));
  }


  bomb();
  
  int max_area = -1e9;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      max_area = max_area < imap[i][j] ? imap[i][j] : max_area;
    }
  }

  cout << max_area << endl;






}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int R,C;
char map[21][21];
bool visited[21][21];

int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};

int Move = 0;

void dfs(pair<int,int> pos, string s,int cnt){

  int y = pos.first;
  int x = pos.second;
  cout << s << endl;

  //visited[y][x]=true;

  for(int i=0;i<4;i++){
    int ny = y+dy[i];
    int nx = x+dx[i];
    if(ny>=0 && nx>=0 && ny<R && nx<C){
      char tmp = map[ny][nx];
      bool check = true;
      for(int k=0;k<s.length();k++){
        if(s[k]==tmp){
          check =false;
          break;
        }
      }
      if(check){
        dfs(make_pair(ny,nx),s+=tmp,cnt+1);
      }else if(!check){
        int slen = s.length();
        Move = max(Move,slen);
      }
        
    }
  }

}




int main(){
  ios_base::sync_with_stdio(false);


  cin >> R >> C;
  for(int i=0;i<R;i++){
    string temp;
    cin >> temp;
    for(int j=0;j<temp.size();j++){
      map[i][j] = temp[j];
    }
  }

  pair<int,int> pos = make_pair(0,0);
  string s = "";
  s+=map[0][0];
  
  dfs(pos,s,1);

  cout << Move << endl;

}
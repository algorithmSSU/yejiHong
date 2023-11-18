#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000
string numb;
int changenum;
int Answer;
bool visited[MAX][11];

void Initialize(){
  Answer = 0;
  numb.clear();
  memset(visited,0,sizeof(visited));
}
void input(){
  cin >> numb;
  cin >> changenum;
}
int Invert(string s){
  int sum = 0;
  // for(int i=0;i<s.length();i++){
  //   sum = sum + (s[i]-'0');
  //   if(i!=s.length()-1)
  //     sum = sum * 10;
  // } // 굳이 뭐하러 이렇게 ??
  sum = stoi(s);

  return sum;
}
void dfs(string s,int depth){
  if(depth == changenum){
    int temp = Invert(s);
    if(temp > Answer){
      Answer = temp;
    }
    return;
  }
  for(int i=0;i<s.length()-1;i++){
    for(int j=i+1;j<s.length();j++){
      swap(s[i],s[j]);
      int temp = Invert(s);
      if(visited[temp][depth+1] == false){
        visited[temp][depth+1] = true;
        dfs(s,depth+1);
      }
      swap(s[i],s[j]);
    }
  }
}
void solution(){
  dfs(numb,0);
}
void solve(){
  int Tc;
  cin >> Tc;
  for(int T=1;T<=Tc;T++){
    Initialize();
    input();
    solution();
    cout << "#" << T << " " << Answer << endl;
  }
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;

}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


bool visited[1001]={false,};
vector<vector<int> > v;
int memo[1001]={0,};

void dfs(int start){
  stack<int> s;
  s.push(start);
  while(!s.empty()){
    int cur = s.top();
    visited[cur]=true;
    memo[cur]=1;
    for(int i=0;i<v[cur].size();i++){
      int next = v[cur][i];
      cout << next;
      if(!visited[next]){
        s.push(next);
        break;
      }
    }
    s.pop();
  }

}


int main(){

  
  v = {{1,3},{3,0,1},{2},{0}};
  dfs(0);
  for(int i=0;i<v.size();i++){
    cout << memo[i] << endl;
  };

  

  return 0;

  


}
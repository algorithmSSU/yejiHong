#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,m;
vector<int> numarr;
vector<int> picknum;
bool visited[15]={false,};

void backTracking(int idx,int cnt){
  if(cnt==m){
    for(int i=0;i<m;i++){
      cout << picknum[i] << " ";
    }
    cout << '\n';
    
    return;
  }else{
    for(int i=idx;i<n;i++){
      picknum.emplace_back(numarr[i]);
      backTracking(i,cnt + 1);
      picknum.pop_back();
    }
  }
}

void input(){
  for(int i=0;i<n;i++){
    int num;
    cin >> num;
    numarr.emplace_back(num);
  }
  sort(numarr.begin(),numarr.end());
  //cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;

  input();
  backTracking(0,0);
}
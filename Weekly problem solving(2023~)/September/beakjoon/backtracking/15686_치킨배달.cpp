#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,m;
bool visited[15]={false};
int map[51][51]={0,};
vector<pair<int,int> > house, chicken,chicken_pick;
int chickencount = 0;
int answer = 1e9;


int Min(int a,int b){
  if(a<b){
    return a;
  }
  return b;
}

void input(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> map[i][j];
      if(map[i][j]==1){
        house.emplace_back(make_pair(i,j));
      }
      if(map[i][j]==2){
        chicken.emplace_back(make_pair(i,j));
      }
    }
  }

  chickencount = chicken.size();
}

int solution(){
  int sum = 0;
  for(int i=0;i<house.size();i++){
    int hy = house[i].first;
    int hx = house[i].second;
    int compare = 1e9;
    for(int j=0;j<chicken_pick.size();j++){
      int cy = chicken_pick[j].first;
      int cx = chicken_pick[j].second;
      int dist = abs(hy-cy) + abs(hx-cx);
      compare = Min(compare, dist);
    }
    sum+=compare;
  }
  return sum;
}


void BackTracking(int idx, int cnt){
  if(cnt==m){
    answer = Min(answer, solution());
    return;
  }else{
    for (int i = idx; i < chickencount;i++){
      if(!visited[i]){
        visited[i]=true;
        chicken_pick.emplace_back(chicken[i]);
        BackTracking(i,cnt+1);
        visited[i]=false;
        chicken_pick.pop_back();
      }
    }
  }
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;

  input();
  BackTracking(0,0);

  cout << answer << endl;

}
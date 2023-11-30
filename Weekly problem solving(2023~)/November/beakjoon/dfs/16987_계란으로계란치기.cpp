#include <iostream>
#include <vector>
using namespace std;
int N;
pair<int,int> eggs[10];
int max_br=0;
bool visited[10];
int order[10];

void dfs(int hold){
  if(hold==N){
    int cnt = 0;
    for(int i=0;i<N;i++){
      if(eggs[i].first <= 0){
        cnt++;
      }
    }
    max_br = max(cnt,max_br);
    return;
  }

  if(eggs[hold].first <= 0){
    dfs(hold+1);
  }
  bool check = false;
  for(int i=0;i<N;i++){
    // 같은 계란을 깰 수 없음 + 이미깨버린거 무시
    if(hold==i || eggs[i].first<=0){
      continue;
    }
    eggs[i].first -= eggs[hold].second;
    eggs[hold].first -= eggs[i].second;

    check = true;
    dfs(hold+1);
    
    eggs[i].first+=eggs[hold].second;
    eggs[hold].first +=eggs[i].second;
  }
  if(!check){
    dfs(N);
  }
}




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(int i=0;i<N;i++){
    int d,w;
    cin >> d >> w;
    eggs[i] = make_pair(d,w); // 내구성, 무게
  }

  dfs(0);
  cout << max_br << endl;

}
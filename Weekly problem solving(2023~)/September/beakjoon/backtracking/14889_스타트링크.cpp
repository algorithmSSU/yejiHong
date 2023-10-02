#include <iostream>
#include <vector>

using namespace std;

int n;
int map[24][24];
bool visited[24]={false,};
int answer = 1e9;

void backTracking(int idx,int cnt){
  if(cnt==n/2){
    int start,link;
    start = 0;
    link = 0;

    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(visited[i]&&visited[j]){
          start+=map[i][j];
        }
        
        if(!visited[i]&&!visited[j]){
          link+=map[i][j];
        }
      }
    }

    int diff = abs(start-link);
    answer = answer > diff ? diff : answer;
    return;

  }else{
    for(int i=idx;i<n;i++){
      visited[i]=true;
      //cout << "idx: " << i << " " << "cnt: " << cnt << endl;
      backTracking(i+1,cnt+1);
      visited[i]=false;
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> map[i][j];
    }
  }

  backTracking(1,0);
  cout << answer << endl;
}
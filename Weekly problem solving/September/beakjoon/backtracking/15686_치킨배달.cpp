// 구글링 구글샘


#include <iostream>
#include <vector>
using namespace std;

const int MAX = 51;
int n,m;
vector<pair<int,int> > house;
vector<pair<int, int> > chicken;
bool visited[15]={false,};
pair<int,int> combi[15];
int answer = 1e9;


// 조합으로 구해진 치킨집 거리계산 
int solution(pair<int,int> chickens[]){
  int answer = 1
  int chicken_way_sum=0;
  for(int i=0;i<m;i++){
    for(int j=0;j<house.size();j++){
      int dist = abs(house[i].first - chicken[j].first) + abs(house[i].second -chicken[j].second);
      chicken_way_sum += dist;
    }
  };

  return chicken_way_sum;
}


// 조합구하기
void BT(int idx, int cnt){
  if(cnt==m){
    for(int i=0;i<m;i++){
      cout << combi[i].first <<"," << combi[i].second << endl;
      
    }
    cout << "________________" << endl;

    
    // m개의 치킨집 치킨거리계산
    int temp = solution(combi);
    answer = temp < answer ? temp : answer;
    return;
  }else{
    for(int i=idx;i<chicken.size();i++){
      if(!visited[i]){
        visited[i]=true;
        combi[cnt]=chicken[i];
        BT(idx+1,cnt+1);
        visited[i]=false;
      }
    }
  }
}




int map[MAX][MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> map[i][j];
      if(map[i][j]==1){//집
        house.emplace_back(i,j);
      }else if(map[i][j]==2){//음치킨
        chicken.emplace_back(i,j);

      }
    }
  }

  BT(0,0);
  cout << answer << endl;


}
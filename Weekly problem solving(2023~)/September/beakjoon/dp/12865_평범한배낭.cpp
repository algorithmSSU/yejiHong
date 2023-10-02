#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K;
vector<pair<int,int> > bag;
int arr[101][100001];
int allweight[101];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> K;//물건의갯수, 무게 총 량
  
  for(int i=0;i<N;i++){
    int w,v;
    cin >> w>> v;
    bag.emplace_back(w,v);
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=K;j++){
      int item_weight = bag[i-1].first;// 맨 첨 요소부터 해줘야하니까
      int item_value = bag[i-1].second; // 맨 첨 요소부터 해줘야하니까
      if(item_weight<=j){
        // 현재 아이템의 무게보다 가방에 넣을 수 있는 무게가 커지면 
        // 이전 아이템에서 현재 아이템 무게 만큼을 빼준 값에 + 현재 아이템의 가치 vs 이전 아이템에서 현재 가방무게에서 가졌던 가치
        arr[i][j]=max(arr[i-1][j-item_weight]+item_value,arr[i-1][j]);
      }else{
        // 현재 아이템 무게보다 가방 무게가 적으면 그냥 직전 아이템에서 현재 가방 무게에서 가졌떤 가치(=최대가치)
        arr[i][j]=arr[i-1][j];
      }
    }
  }
  cout << arr[N][K] << endl;
}
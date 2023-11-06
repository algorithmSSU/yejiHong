#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return b.first < a.first;
}


int main(int argc, char** argv)
{
   int  W, N;
  int answer = 0;
  vector<pair<int,int> > v;

  // 배낭크기, 귀금속 갯수
  cin >> W >> N;



  for(int i=0;i<N;i++){
    int weight, price;
    cin >> weight >> price;
    v.emplace_back(price,weight);// 가격, 무게
  }


  sort(v.begin(),v.end(),compare);


    int need = 0;
    for(int i=0;i<v.size();i++){
        int temp = W/v[i].second; // 가방무게/귀금속무게 = 안자르고 넣을 수 있는지.
        
        if(temp>0){ // 가방 채우기, 귀금속 통재로 넣을 수 있음
            need+=temp * v[i].second * v[i].first; // 1 * 귀금속 무게 * 귀금속 가격
            W-=v[i].second *temp; // 전체 가방 크기 - (무게 * 귀금속 갯수)
        }else if(temp==0){
            need+=v[i].first * W; // 남은 가방 크기만큼의 귀금속 무게 * 귀금속 가격
        }
    }
    cout << need << endl;
   return 0;
}
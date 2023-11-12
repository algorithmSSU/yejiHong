#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, B, C;
vector<int> test_rooms;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long int D=0; // 감독관수
  
  cin >> N;

  for(int i=0;i<N;i++){
    int num;
    cin >> num;
    test_rooms.emplace_back(num);
  }

  cin >> B >> C;

  for(auto it : test_rooms){
    int temp = it - B;
    D+=1;// 총감독관 1명은 반드시 상주
    if(temp>0){
      if(temp<=C){
        D+=1;
      }else if(temp>C){
        if(temp%C!=0){
          D+= temp/C;
          D+= 1;
        }else{ // 나누어 떨어지면 +몫
          D+= temp/C;
        }
      }
    }
  }

  cout << D << '\n';

  return 0;
  
}
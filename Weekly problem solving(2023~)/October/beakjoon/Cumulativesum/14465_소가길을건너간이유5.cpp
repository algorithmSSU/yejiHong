#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, B;
int load[100002];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K >> B;

  for(int i=0;i<B;i++){
    int idx;
    cin >> idx;
    load[idx]=-1;
  }


  int one=0;
  int Mincnt = 1e9;
  for(int i=1;i<=N-K+1;i++){
    one = 0;// one init
    for(int j=i;j<i+K;j++){
      if(load[j]==-1){
        one++;
      }
    }
    Mincnt = min(one,Mincnt);
    
  }

  cout << Mincnt << '\n';

}
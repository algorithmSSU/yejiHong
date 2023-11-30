#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int t[16], p[16];
int ans = 0;

void go(int day,int sum){
  if(day==N+1){
    ans = max(ans,sum);
    return;
  }

  // N보다 큰 거는 더해줄수가없구려
  if(day>N+1){
    return;
  }
  
  
  go(day+t[day],sum+p[day]);
  go(day+1,sum); // start 2일, start 3일..
}




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> t[i] >> p[i];
  }
  go(1,0);  

  cout << ans << endl;
}
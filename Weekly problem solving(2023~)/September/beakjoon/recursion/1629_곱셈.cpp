#include <iostream>
#include <vector>


// 아직 
using namespace std;
int a,b,c;
long long int ans = 1;

void cal(int a, int b,int c){
  while(b--){
    if(ans>c){
      break;
    }
    ans*=a;
  }
  cout << ans << " " << c << endl;
  cout << ans%c << '\n';

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c;

  cal(a,b,c);

}
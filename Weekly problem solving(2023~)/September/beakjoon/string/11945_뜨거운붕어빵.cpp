#include <iostream>
#include <vector>
#include <string>
using namespace std;



int N,M;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string ss[11];
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> ss[i];
    reverse(ss[i].begin(),ss[i].end());
  };

  for(int i=0;i<N;i++){
    cout << ss[i] << '\n';
  }

}
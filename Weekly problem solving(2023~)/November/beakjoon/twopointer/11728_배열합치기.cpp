#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
// A 와 B 배열크기

vector<int> a;
vector<int> b;
int main(){

  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin >> N >> M;

  for(int i=0;i<N;i++){
    int num;
    cin >> num;
    a.push_back(num);
  }

  for(int j=0;j<M;j++){
    int num;
    cin >> num;
    a.push_back(num);
  }

  sort(a.begin(),a.end());
  for(auto it : a){
    cout << it << " ";
  }

  
 

}
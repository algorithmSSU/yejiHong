#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> v = {1,4,2,3};
  int size = v.size();

  sort(v.begin(),v.end());

  do{
    for(int i=0;i<size;i++){
      cout << v[i] << ' ';
    }
    cout << '\n';

  }while(next_permutation(v.begin(),v.end()));
  
  
}
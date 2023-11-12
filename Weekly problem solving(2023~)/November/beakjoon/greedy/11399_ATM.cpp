#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  vector<int> arr;
  cin >> n;

  for(int i=0;i<n;i++){
    int num;
    cin >> num;
    arr.emplace_back(num);
  }
  sort(arr.begin(),arr.end());

  int sum=0;
  int result = 0;
  for(int i=0;i<arr.size();i++){
    sum+=arr[i];
    result +=sum;

  }

  cout << result << endl;

}
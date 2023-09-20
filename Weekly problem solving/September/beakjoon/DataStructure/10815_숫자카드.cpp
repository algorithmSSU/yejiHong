#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n,m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  map<int,int> dict;
  vector<int> answer;

  cin >> n;
  for(int i=0;i<n;i++){
    int num;
    cin >> num;
    dict[num]++;
  };

  cin >> m;
  for(int i=0;i<m;i++){
    int num;
    cin >> num;
    if(dict.find(num)!=dict.end()){
      answer.emplace_back(1);
    }else{
      answer.emplace_back(0);
    }
  }

  for(int i=0;i<answer.size();i++){
    cout << answer[i] << " ";
  }
  cout << '\n';
}
#include <iostream>
#include <vector>

using namespace std;


int n;
vector<int> isPelindrome;
vector<int> recall;
string s;
int sol(int left,int right,int cnt){
  if(left>=right){
    recall.emplace_back(cnt); // cnt는 몇번 호출되었는지, return 1값은 펠린드롬인지아닌지
    return 1;
  }else if(s[right]!=s[left]){
    recall.emplace_back(cnt);
    return 0;
  }else{//같다면
    return sol(left+1,right-1,cnt+1);
  }
}




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;

  for(int i=0;i<n;i++){
    cin >> s;
    isPelindrome.emplace_back(sol(0,s.length()-1,1));
  };
  
  for(int i=0;i<n;i++){
    cout << isPelindrome[i] << " " << recall[i] << endl;
  }

}
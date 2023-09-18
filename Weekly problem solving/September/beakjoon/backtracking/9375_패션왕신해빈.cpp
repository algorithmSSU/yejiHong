#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, m;
vector<int> answer;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    
    map<string,int> closet;
    map<string,int>::iterator p;
    int count = 0;
    int sub = 1;

    cin >> m;

    for(int j=0;j<m;j++){
      string name, kind;
      cin >> name >> kind;
      closet[kind]++;
      count ++;//하나씩만이라도 입는 경우 더해주기
    }

    if(m==0){
      answer.emplace_back(0);
    }else if(closet.size()==1){//종류가 하나밖에 없는 경우
      answer.emplace_back(count);
    }else{
      for(p=closet.begin();p!=closet.end();p++){
        sub *= (p->second+1); // 서로 다른 옷들끼린 곱해주기
      }
      //sub += count;
      answer.emplace_back(sub-1);
    }
    
  }
  for(int i=0;i<answer.size();i++){
    cout << answer[i] << '\n';
  }



}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int n;
vector<int> answer;
pair<int,int> arr[500001];
stack<pair<int,int> > s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i=0;i<n;i++){
    int temp;
    cin >> temp;
    arr[i]=make_pair(temp,i+1);
  };

  //stack
  s.push(make_pair(1e9,0));

  for(int i=0;i<n;i++){
    if(s.top().first > arr[i].first){
      answer.emplace_back(s.top().second);
      s.push(arr[i]);
    }else{
      // s의 맨꼭대기가 현재 값보다 작은 경우에 계속 대가리벗겨라
      while(s.top().first < arr[i].first){
        s.pop();
      }
      // 오케이 s의 맨꼭대기 나보다는 값 큰데 어디한번 보자
      // 초기값이네? == 나보다 큰 값은 없네? 
      if(s.top().first==1e9){
        answer.emplace_back(0);
      // 나보다 큰 값이 존재했네 == 이 아이의 인덱스를 저장
      }else{
        answer.emplace_back(s.top().second);
      }

      s.push(arr[i]);// 힛 그리고 나를 넣고 다음거랑 비교 
    }
  }

  for(int i=0;i<answer.size();i++){
    cout << answer[i] << " ";
  }
  cout << '\n';
}
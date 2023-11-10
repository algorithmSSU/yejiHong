#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


// 정렬함수
// a<b : 오름차순, a>b : 내림차순
bool compare(pair<int,int>&a , pair<int,int>&b){
  
  // 1의 갯수가 같으면, 10진수 크기로 내림차수
  if(a.first == b.first){
    return a.second > b.second;
  }

  // 그전에 1의 갯수로 내림차수
  return a.first > b.first;
  
}

// 10진수 입력받으면 (문자열형태로) 2진수로 바꿔줌
string deciTobin(int n){
  string answer;

  while(n!=0){
    if(n%2==1){
      answer.push_back('1');
    }else{
      answer.push_back('0');
    }
    n/=2;
  }
  reverse(answer.begin(),answer.end());
  
  return answer;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int k;
  vector<pair<int,int>> one_cnt_list;
  cin >> n >> k;

  while(n--){
    int num;
    cin >> num;

    string temp = deciTobin(num);
    int cnt = count(temp.begin(),temp.end(),'1');
    //cout << cnt << endl;
    one_cnt_list.emplace_back(cnt,num);
  }


  // 정렬
  // 1의 갯수로 내림차수 , 같으면 10진수 크기로 내림차수 
  sort(one_cnt_list.begin(),one_cnt_list.end(),compare);


  cout << one_cnt_list[k-1].second << endl;
  return 0;


}
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;



// 큰값~작은값 순서로 정렬되어 있는 숫자 배열 필요
vector<int> v;
int start_idx;
int str_arr[1000001]={0,};

void make_nums(string number){
  map<int,int> dict;
  for(int i=0;i<number.length();i++){
    int cur = number[i]-'0';
    if(dict.find(cur)==dict.end()){
      v.emplace_back(cur);
    }
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());//큰수부터 정렬
}

int findStartidx(string number,int k){
  int start_idx= 0;
  for(int i=0;i<v.size();i++){
    for(int j=0;j<number.length();j++){
      if(v[i]==number[j]-'0'){
        if(j<=k){
          start_idx=i;
          return start_idx;
        }
      }
    }
  }
  return -1;
}

void del(string number,int k,int idx){
  int cnt = 0;
  for(int i=idx;i<number.length()-1;i++){
    if(number[i]-'0'>number[i+1]-'0'){
      str_arr[i+1]=-1;
      cnt++;
      if(cnt>=k-1){
        return;
      }
    }
  }

}

string solution(string number, int k) {
    string answer = "";
    int start_idx;
    int remain_k;
    make_nums(number);
    // 시작 인덱스
    start_idx = findStartidx(number,k);
    // 남은 삭제 횟수
    remain_k = k-start_idx;
    del(number,remain_k,start_idx);

    //cout << "start_idx: " << start_idx << endl;
    for(int i=start_idx+1;i<number.length();i++){
      if(str_arr[i]!=-1){
        answer+=number[i];
      }
    }
    return answer;
}

int main(){
  string answer ="";
  string number = "1231234";
  int k = 3;

  answer = solution(number,k);

  cout << answer << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>



// https://www.acmicpc.net/board/view/127252
// 답변기다리기

using namespace std;
vector<string> output;


void process(){
  string order, source;
  string answer="";
  int n;
  deque<int> dq;

  cin >> order;
  cin >> n;
  cin >> source;

  string Num;// 숫자들끼리 합쳐줄거
  int number;
  for(int i=0;i<source.length();i++){
    if(isdigit(source[i])){
      Num+=source[i];
    }else{
      if(!Num.empty()){
        number = stoi(Num);
        dq.push_back(number);

        Num = "";// 숫자합쳐준 문자열 초기화
      }
    }
  }

  // order 을 뒤지자
  bool reverse = true; // 원래 정방향
  for(int j=0;j<order.length();j++){
    if(order[j]=='R'){
      reverse = !reverse;//반대로
    }else if(order[j]=='D'){
      if(!dq.empty()){ // dq가 비어있지 않으면,
        if(reverse){//정방향이면
          dq.pop_front();
        }else{
          dq.pop_back();
        }
      }else{ // dq가 비어있으면
        answer="error";
        break;
      }
    }
  }

  // deque iter 왜 안됨??

  if(answer.empty()){
    if(dq.empty()){
        answer+="[]";
    }else if(reverse){
      answer+='[';
      for(int i=0;i<dq.size();i++){
        if(i==dq.size()-1){
          answer+=to_string(dq[i]);
          
          break;
        }
        answer+=dq[i]+'0';
        answer+=',';
      }
      answer+=']';
    }else if(!reverse){
      answer+='[';
      for(int i=dq.size()-1;i>=0;i--){
        if(i==0){
          answer+=to_string(dq[i]);
          break;
        }
        answer+=to_string(dq[i]);
        answer+=',';
      }
      answer+=']';
    }
  }
  output.push_back(answer);

  
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        process();
    }
    for(int i=0;i<output.size();i++){
        cout << output[i] << '\n';
    };


    return 0;
}
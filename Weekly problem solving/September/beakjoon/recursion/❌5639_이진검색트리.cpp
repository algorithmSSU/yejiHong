#include <iostream>
#include <vector>
using namespace std;



// 졸라모르겠다 미친

vector<int> input;

void go(int start,int end){
  if(start>=end){
    return;
  }
  if(start==end-1){
    cout << input[start] << '\n';
    return;
  }
  int now = start+1;
  while(now<end){
    if(input[start]<input[now])
      break;
    now++;
  }

  go(start+1,now);
  go(now,end);
  cout << input[start] << '\n';
  return;
}

int main(){
  
  while(1){
    string s;
    getline(cin,s,'\n');
    if(s.empty()){
      break;
    }
    int num = stoi(s);
    input.emplace_back(num);
    //cout << "number: "<< num << endl;
  }

  go(0,input.size()-1);
  return 0;

}
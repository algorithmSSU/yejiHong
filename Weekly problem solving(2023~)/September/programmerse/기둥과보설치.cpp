#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char map[1001][1001];

vector<vector<int> > deletezip;
// 2: 아무것도 없음(삭제됨), 1: 보, 0: 기둥
void detail(vector<int> frame)
{
  int y = frame[0];
  int x = frame[1];
  int k = frame[2];
  int s = frame[3];

  if(k==0 && s==1){//기둥생성
    map[y][x]='-';
  }else if(k==0 && s==0){
    vector<int> temp = frame;
    deletezip.emplace_back();
  }else if(k==1 && s==1){//보생성
    map[y][x]='|';
  }else if(k==1 && s==0){//보삭제
    deletezip.emplace_back(frame);
  }
}

//삭제조건???
void delete_(vector<int> v){
  int y = v[0];
  int x = v[1];
  int kind = v[2]; // 종류
  if(kind == 0){ // 기둥 삭제
    if (map[y][x - 1] == 0 || map[y][x+1] == 0)
    { // 밑에기둥이면삭제못함
      return;
    }else if (map[y-1][x]==1 || map[y+1][x]==1 || map[y][x-1]==1 || map[y][x+1]==1){
      return;
    }else{
      map[y][x] = 2;//삭제
    }
  }
  if(kind == 1){ // 보 삭제
    if(map[y-1][x]==1 || map[y+1][x]==1){// 위아래 연결된 보 이면 삭제못함
      return;
    }else if(map[y][x-1]==0){ // 아래 기둥이 있으면 삭제못함
      return;
    }else{
      map[y][x]=2;
    }
  }
}


void draw(vector<vector<int> > build_frame)
{
  // rendering
  for (int i = 0; i < build_frame.size(); i++)
  {
    detail(build_frame[i]);
  }

  // delete
  for(int i=0;i<deletezip.size();i++){
    delete_(deletezip[i]);
  }

}

vector<vector<int> > solution(int n, vector<vector<int> > build_frame)
{
  vector<vector<int> > answer;



  for(int i=0;i<1001;i++){
    for(int j=0;j<1001;j++){
      map[i][j] = '*';
    }
  }



  draw(build_frame); // 그림그리고



  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      cout << map[i][j] << " ";
    }
    cout << '\n';
  }

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      vector<int> temp;
      if (map[i][j] == '|')
      {
        temp.emplace_back(i);
        temp.emplace_back(j);
        temp.emplace_back(1);
        answer.emplace_back(temp);
      }
      if (map[i][j] == '-')
      {
        temp.emplace_back(i);
        temp.emplace_back(j);
        temp.emplace_back(0);
        answer.emplace_back(temp);
      }
    }
  }

  return answer;
}

int main(){
     vector<vector<int> > test;
     vector<int> tmp;
     tmp.push_back(1);
     tmp.push_back(0);
     tmp.push_back(0);
     tmp.push_back(1);
     test.push_back(tmp);
  
     vector<int> tmp2;
     tmp2.push_back(1);
     tmp2.push_back(1);
     tmp2.push_back(1);
     tmp2.push_back(1);
     test.push_back(tmp2);
  
     vector<int> tmp3;
     tmp3.push_back(2);
     tmp3.push_back(1);
     tmp3.push_back(0);
     tmp3.push_back(1);
     test.push_back(tmp3);
  
     vector<int> tmp4;
     tmp4.push_back(2);
     tmp4.push_back(2);
     tmp4.push_back(1);
     tmp4.push_back(1);
     test.push_back(tmp4);
  
     vector<int> tmp5;
     tmp5.push_back(5);
     tmp5.push_back(0);
     tmp5.push_back(0);
     tmp5.push_back(1);
     test.push_back(tmp5);
  
     vector<int> tmp6;
     tmp6.push_back(5);
     tmp6.push_back(1);
     tmp6.push_back(0);
     tmp6.push_back(1);
     test.push_back(tmp6);
  
     vector<int> tmp7;
     tmp7.push_back(4);
     tmp7.push_back(2);
     tmp7.push_back(1);
     tmp7.push_back(1);
     test.push_back(tmp7);
  
     vector<int> tmp8;
     tmp8.push_back(3);
     tmp8.push_back(2);
     tmp8.push_back(1);
     tmp8.push_back(1);
     test.push_back(tmp8);
  

      vector<vector<int> > ans;
     ans = solution(5, test);

     for(int i=0;i<ans.size();i++){
      cout << ans[i][0] << ans[i][1] << ans[i][2] << " /";
     };

     }
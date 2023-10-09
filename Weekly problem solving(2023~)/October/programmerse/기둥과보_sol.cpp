#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool pillar[102][102];
bool beam[102][102];


// 기둥 설치 체크
bool checkPillar(int y,int x){
  if(x==0 || pillar[y][x-1]){
    return true;
  }
  if(beam[y][x] || (y>0 && beam[y-1][x])){
    return true;
  }
  return false;
}


// 보 설치 체크
bool checkBeam(int y,int x){
  if((x>0 && pillar[y][x-1]) || (x>0 && pillar[y+1][x-1])){
    return true;
  }
  if((y>0 && beam[y-1][x]) && beam[y+1][x]){
    return true;
  }
  return false;
}

// 지울 수 있는 지 체크
bool canDelete(int y,int x){
  for(int i=max(0,y-1);i<=y+1;i++){
    for(int j=x;j<=x+1;j++){
      if(pillar[i][j] && !checkPillar(i,j)){
        return false;
      }
      if(beam[i][j] && !checkBeam(i,j)){
        return false;
      }
    }
  }
  return true;
}


// 메인
vector<vector<int> > solution(int n, vector<vector<int> > build_frame){
  vector<vector<int> > answer;

  for(auto b : build_frame){
    int y = b[0];
    int x = b[1];
    int type = b[2];
    int action = b[3];

    if(type==0){
      if(anction == 1 && checkPillar(y,x)){
        pillar[y][x]=true;
      }
      else{
        pillar[y][x]=false;
        if(!canDelete(y,x)){
          pillar[y][x]= true;
        }
      }
    }else{
      if(anction==1 && checkBeam(y,x)){
        beam[y][x]=true;
      }
      else{
        beam[y][x]=false;
        if(!canDelete(y,x)){
          beam[y][x]=true;
        }
      }
    }
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if(pillar[i][j]){
        answer.push_back({i,j,0});
      }
      if(beam[i][j]){
        answer.push_back({i,j,1});
      }
    }
  }
  return answer;
}
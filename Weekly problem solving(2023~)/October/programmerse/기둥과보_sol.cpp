#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int Map[101][101];


// 기둥 : 1
// 보 : 2
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    map<pair<int,int>,int> pos;
    map<pair<int,int>,int>::iterator it;
    
    for(auto list:build_frame){
        if(list[2]==0 && list[3]==1){ // 기둥 + 설치
            int y = list[0];
            int x = list[1];
            // 바닥 위에 있거나, 보의 한쪽 끝부분 , 다른 기둥 위 => 기둥세우기 가능
            if(x==0 || Map[y-1][x]==2 || Map[y+1][x]==2 || Map[y][x-1]==1){
                Map[y][x] = 1;// 기둥 설치
                pos[make_pair(y,x)]++;
            }
        }
        else if(list[2]==1 && list[3]==1){// 보 + 설치
            int y = list[0];
            int x = list[1];
            // 한쪽 끝 부분이 기둥위에 있거나 양쪽 끝 부분이 다른 보와 연결
            if(Map[y-1][x-1]==1 || Map[y][x-1]==1 || Map[y+1][x-1] || Map[y-1][x] == 2|| Map[y+1][x] == 2){
                Map[y][x] = 2; // 보 설치
                pos[make_pair(y,x)]++;
            }
        }else if(list[1]==0 && list[3]==0){// 기둥 + 삭제
            int y = list[0];
            int x = list[1];
            // -|아닌경우 삭제 가능 (기둥이 보를 받치고 있지 않은 경우에 삭제)
            if(Map[y][x-1]!=2 && Map[y-1][x-1]!=2 && Map[y+1][x-1]!=2 && Map[y][x+1]!=2 && Map[y-1][x+1]!=2 && Map[y+1][x+1]!=2){
                Map[y][x] = 0; // 기둥 삭제
                pos[make_pair(y,x)]--;
            }
        }else if(list[2]==1 && list[3]==0){// 보 + 삭제
            int y = list[0];
            int x = list[1];
            // 보가이어져 있지 않은 경우 삭제
            if(Map[y-1][x]!=2 && Map[y+1][x]!=2){
                Map[y][x] = 0; // 기둥 삭제
                pos[make_pair(y,x)]--;
            }
        }
    }
    for(it=pos.begin();it!=pos.end();it++){
      vector<int> temp;
      if(it->second==1){
        int y = it->first.first;
        int x = it->first.second;
        temp.emplace_back(y);
        temp.emplace_back(x);
        if(Map[y][x]==1)
          temp.emplace_back(0);
        if(Map[y][x]==2)
          temp.emplace_back(1);
      }
      answer.emplace_back(temp);
    }
  
  return answer;
}

int main(){

  int map[101][101];
  memset(map,0,sizeof(map));
  int n = 5;
  vector<vector<int> > build_frame{
    {1,0,0,1},
    {1,1,1,1},
    {2,1,0,1},
    {2,2,1,1},
    {5,0,0,1},
    {5,1,0,1},
    {4,2,1,1},
    {3,2,1,1}
  };

  vector<vector<int> > ans;
  ans = solution(n,build_frame);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }

}
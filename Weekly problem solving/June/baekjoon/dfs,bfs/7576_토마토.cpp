#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

int col, row =0;
int box[1001][1001];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
bool visited[1001][1001]={false,};
queue<pair<int, int> > q;


void tom(){

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny>=row || ny<0 || nx>=col || nx<0){
                continue;
            }else{
                if(box[ny][nx]==0){
                    visited[ny][nx]=true;
                    box[ny][nx] = box[cy][cx] + 1;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}



int main(){
    std::cin.tie(0);
    ios_base::sync_with_stdio(false);
    int answer = 0;
    vector<pair<int,int> > one;
    std::cin >> col >> row;

    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        int tomato;
        std::cin >> box[i][j];
        if(box[i][j]==1){
            q.push(make_pair(i,j));
        }
        
      }
    };


    tom();

    /*
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            std::cout << box[i][j] << " ";
        };std::cout << '\n';
    }
    */

    int maxv = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(box[i][j]==0){
                answer = -1;
                std::cout << answer << endl;
                return 0;
            };
            maxv = maxv < box[i][j] ? box[i][j] : maxv;
        }
    };

    answer = maxv-1;

    std::cout << answer << endl;

    
    return 0;
    
}
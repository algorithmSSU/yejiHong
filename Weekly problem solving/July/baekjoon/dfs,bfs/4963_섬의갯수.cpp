#include <iostream>
#include <vector>
#include <memory.h>
#include <string>
using namespace std;

int w, h;
int map[51][51]={0,};
bool visited[51][51]={false,};
int dy[8]={0,0,-1,1,-1,1,-1,1};
int dx[8]={-1,1,0,0,-1,1,1,-1};

int land = 0;
int dfs(int y,int x){
    visited[y][x]=true;
    for(int i=0;i<8;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=0 && nx>=0 && ny<h && nx<w){
            if(map[ny][nx]==1 && !visited[ny][nx]){
                dfs(ny,nx);
            }
        }
    }
    return 1;
}


int main(){
    vector<int> answer;
    do{
        // initial
        for(int i=0;i<51;i++){
            memset(map[i],0,sizeof(int)*51);
            memset(visited[i],false,sizeof(bool)*51);
        }

        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }

        int temp = 0;
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j]!=0 && !visited[i][j]){
                    temp+=dfs(i,j);
                }
            }
        }
        answer.emplace_back(temp);

    }while(w!=0 && h!=0);
    

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }

}
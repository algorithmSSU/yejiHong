#include <iostream>
#include <vector>

using namespace std;

int M, N;
int dy[8]={0,0,-1,1,1,1,-1,-1};
int dx[8]={-1,1,0,0,-1,1,1,-1};
int map[251][251]={0,};
bool visited[251][251]={false,};


int dfs(int y,int x){
    visited[y][x]= true;
    for(int i=0;i<8;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>=0 && nx>=0 && ny<M && nx<N){
            if(map[ny][nx]==1 && !visited[ny][nx]){
                dfs(ny,nx);
            }
        }
    }
    return 1;
    

}

int main(){
    cin >> M >> N;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }


    int ch = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==1 && !visited[i][j]){
                ch+=dfs(i,j);
            }
        }
    };

    cout << ch << endl;



}
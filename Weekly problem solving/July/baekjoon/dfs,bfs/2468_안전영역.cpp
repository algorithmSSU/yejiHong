#include <iostream>
#include <vector>

using namespace std;


int N;
int map[101][101]={0,};
bool visited[101][101]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

void dfs(int y,int x){
    visited[y][x]= true;
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>=0 && nx>=0 && ny<N && nx<N){
            if(map[ny][nx]>N && !visited[ny][nx]){
                dfs(ny,nx);
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]>N && !visited[i][j]){ // N높이 넘는것들만 조사한다
               dfs(i,j);
               cnt++;
            }
        }
    };

    cout << cnt << '\n';
    


}
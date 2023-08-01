#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int h, w;
bool visited[501][501] = {false,};
int board[501][501]={0,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

int dfs(int y, int x){
    int cnt = 1;
    stack<pair<int,int> > s;
    s.push(make_pair(y,x));
    visited[y][x]=true;

    while(!s.empty()){
        int cy = s.top().first;
        int cx = s.top().second;
        //visited[cy][cx]=true;
        s.pop();

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny<0 || nx<0 || ny>=h || nx>=w){
                continue;
            }else{
                if(board[ny][nx]==1 && visited[ny][nx]==false){
                    cnt++;
                    visited[ny][nx]=true;
                    s.push(make_pair(ny,nx));
                }
            }
        }
    }
    return cnt;
}

int main(){


    cin >> h >> w;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> board[i][j];
        }
    }

    
    int image = 0;
    int im_size = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(board[i][j]==1 && visited[i][j]==false){
                image++;
                int temp = dfs(i,j);
                im_size = im_size <= temp ? temp : im_size;
            }
        }
    };

    cout <<image << '\n' << im_size << '\n';

}
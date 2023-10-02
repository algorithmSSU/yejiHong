#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

#define SIZE 51
int w, h;
int map[SIZE][SIZE]={0,};
int visited[SIZE][SIZE] ={0,};
//int**visited = new int*[h];
int dy[8]={-1,1,0,0,-1,-1,1,1};// 대각선까지 고려
int dx[8]={0,0,-1,1,-1,1,-1,1};// 대각선까지 고려


int bfs(int y,int x){
    
    queue< pair<int, int> > q;
    q.push(make_pair(y,x));
    visited[y][x]=1;


    while(!q.empty()){
        int cy,cx;
        cy = q.front().first;
        cx = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int ny,nx;
            ny = cy+dy[i];
            nx = cx+dx[i];
            if(ny <0|| ny >=h || nx<0|| nx>=w)
                continue;
            if(map[ny][nx]==1 && visited[ny][nx]==0){
                visited[ny][nx]=1;
                q.push(make_pair(ny,nx));
            }
        }

        
    }
    return 1;
    
};

void fill(int w,int h){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> map[i][j];
        }
    }
}
int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> ans;
    
    do{
        cin >> w >> h;

        if(w==0 && h==0){
            break;
        }

        // map init
        for(int i=0;i<h;i++){
            memset(map[i],0,sizeof(int)*w);
            memset(visited[i],0,sizeof(int)*w);
        };

        fill(w,h); // make map

        // visited init
        /*
        for(int i=0;i<h;i++){
            visited[i] = new int[w];
        };
        */

        // seek
        int c = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j]==1 && visited[i][j]==0){
                    c+=bfs(i,j);
                }
            }
        };
        ans.push_back(c);

    }while(w!=0 && h!=0);


    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }


    return 0;
}
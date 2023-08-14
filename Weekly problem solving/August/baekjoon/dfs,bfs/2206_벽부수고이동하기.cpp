#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>


/// 시간초과뜸 알아보자...


using namespace std;

long long int map[1001][1001]={0,};
long long int c_map[1001][1001]={0,};

int n, m;
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
bool visited[1001][1001]={false,};
bool one_visited[1001][1001] = {
    false,
};

void reset(){
    for(int i=0;i<1001;i++){
        memset(visited[i],false,sizeof(bool)*1001);
    }
}


void cross(int y,int x){
    int ty = y;
    int tx = x;
    while(ty<n && tx>=0){
        one_visited[ty++][tx--]=true;
    };
    while(ty>=0 && tx<m){
        one_visited[ty--][tx++]=true;
    };
}


void bfs(int y,int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    //map[y][x]=1;
    c_map[y][x]=1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        visited[cy][cx]=true;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny>=0 && nx>=0 && ny<n && nx<m){
                if(!visited[ny][nx]){
                    if(map[ny][nx]==0){
                        //map[ny][nx] = map[cy][cx] + 1;
                        c_map[ny][nx] = c_map[cy][cx] + 1;
                        visited[ny][nx]=true;
                        q.push(make_pair(ny,nx));
                    }
                }
            }
        }
    }

}

int main(){


    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    c_map[1000][1000] = 1e9;
    
    queue<pair<int,int> > one_pos;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string line;
        cin >> line;
        for(int l=0;l<line.length();l++){
            map[i][l]=line[l]-'0';
            if(map[i][l]==1){
                one_pos.push(make_pair(i,l));
            }

        }
    }

    
    int minumum = 1e9;
    
    while(!one_pos.empty()){
        int y = one_pos.front().first;
        int x= one_pos.front().second;
        one_pos.pop();
        if(!one_visited[y][x]){
            map[y][x] = 0;
            cross(y,x);
            bfs(0, 0);
            map[y][x] = 1;
            reset();
            if (c_map[n - 1][m - 1] != 0)
            {
                minumum = c_map[n - 1][m - 1] < minumum ? c_map[n - 1][m - 1] : minumum;
            }
        }
    }

    if(c_map[n-1][m-1]==0){
        cout << -1 << '\n';
    }else{
        cout << minumum << '\n';
    }


}
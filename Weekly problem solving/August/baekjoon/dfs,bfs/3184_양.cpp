#include <iostream>
#include <vector>
#include <queue>
using namespace std;


char map[251][251];
bool visited[251][251]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

int r,c;

int sheep = 0;
int wolf = 0;

void bfs(int y,int x){
    queue<pair<int,int> > q;
    int o = 0;
    int v = 0;

    q.push(make_pair(y,x));
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        visited[cy][cx]=true;

        if(map[cy][cx]=='o'){
            o++;
        }else if(map[cy][cx]=='v'){
            v++;
        }


        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny>=0 && nx>=0 && ny<r && nx<c){
                if(!visited[ny][nx] && map[ny][nx]!='#'){
                    visited[ny][nx]=true;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
    
    if(o<=v){
        wolf+=v;
    }else if(o>v){
        sheep+=o;
    }

    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    for(int i=0;i<r;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            map[i][j]=str[j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i][j]=='#' && !visited[i][j]){
                bfs(i,j);
            }
        }
    }


    cout << sheep << " " << wolf << '\n';



}
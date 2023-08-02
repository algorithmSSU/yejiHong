#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

int h,w;
int map[101][101]={0,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
bool visited[101][101]={false,};
 
void bfs(int y,int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    int howlong=0;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny>=0 && nx>=0 && ny<h && nx<w){
                if(map[ny][nx]==1 && visited[ny][nx]==false){
                    visited[ny][nx]=true;
                    howlong++;
                    q.push(make_pair(ny,nx));
                    map[ny][nx] = map[cy][cx]+1;

                }
            }
        }
    }

}

int main(){
    cin >> h >> w;

    for(int i=0;i<h;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            map[i][j]=str[j]-'0';
        }
    };
    

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j]==1){
                bfs(i,j);
            }
        }
    };

    cout << map[h-1][w-1] << '\n';



}
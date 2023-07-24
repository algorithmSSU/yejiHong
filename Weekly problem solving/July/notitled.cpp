#include <iostream>
#include <vector>

using namespace std;
int n;
int map[26][26];
int visited[26][26]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

int cnt=0;
int dfs(int y,int x,int cnt){
    visited[y][x]=true;

    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>=0 && nx>=0 && ny<n && nx<n){
            if(!visited[ny][nx] && map[ny][nx]==1){
                dfs(ny,nx,cnt++);
            }
        }
    }
    return cnt;

}

int main(){
    
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
           map[i][j] = str[j]-'0';
        }
    }



}
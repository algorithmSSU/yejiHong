#include <iostream>
#include <vector>
#include <math.h>


using namespace std;


char map[101][101]={0,};
int record[101][101]={0,};
bool visited[101][101]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int h,w;

int cnt=0;
int dfs(int y,int x,char target){
    visited[y][x]=true;
    cnt++;
    for(int i=0;i<4;i++){
        int ny= y+dy[i];
        int nx= x+dx[i];
        if(ny>=0&& nx>=0 && ny<h && nx<w){
            if(visited[ny][nx]==false && map[ny][nx]==target){
                dfs(ny,nx,target);
            }
        }
    };
    return cnt;
}

int main(){
    cin >> w >> h;

    for(int i=0;i<h;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            map[i][j]=str[j];
        }
    }

    int white=0;
    int blue = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(visited[i][j]!=true){
                cnt = 0;
                if(map[i][j]=='W'){
                    int w_temp;
                    w_temp = dfs(i,j,'W');
                    white+=pow(w_temp,2);

                }else if(map[i][j]=='B'){

                    int b_temp;
                    b_temp = dfs(i,j,'B');
                    blue+=pow(b_temp,2);

                }
            }
        }
    }

    cout << white << " " << blue << '\n';


    
}
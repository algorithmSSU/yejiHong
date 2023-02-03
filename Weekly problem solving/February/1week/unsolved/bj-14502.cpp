#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
int row, col;


int map[8][8];
int m[8][8];
int record[8][8];

void bfs(int x,int y){
    int temp[8][8];
    copy(&map[0][0],&map[0][0]+64,&temp[0][0]);
    int mx[4]={0,-1,0,1};
    int my[4]={-1,0,1,0};
    for(int i=0;i<4;i++){
        int nx = x+mx[i];
        int ny = y+my[i];
        if(map[nx][ny]==0 && map[nx][ny]!=1){
            map[nx][ny]=2;
            bfs(nx,ny);
        }
    }
};



int seek(int x,int y){
    int answer =0;
    int nx = x+1;
    int ny = y+1;

    int cnt =0;
    for(int i=nx;i<=row;i++){
        for(int j=ny;j<=col;j++){
            if(!map[i][j]&& map[i][j]==0){
                map[i][j]=1;
                cnt++;
            }
            if(cnt==2){
                break;
            }
        }
    };
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(map[i][j]==2){
                bfs(i,j);
            };
        };
    };

    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(map[i][j]==2){
                answer++;
            };
        };
    };
    


    return answer;
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> row >> col;
    row = row+1; // input size 보다 한칸크게
    col =  col+1; // input size 보다 한칸크게
    int total = row*col;

    // fill map
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cin >> map[i][j];
        };
    };

    // fill m
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            m[i][j]= map[i][j];
        };
    };
    
   
    // seek map
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            if(map[i][j]==0){
                copy(&m[0][0],&m[0][0]+total,&map[0][0]);
                memset(record,0,sizeof(int));
                map[i][j]=1;
                seek(i,j);
                map[i][j]=0;
                
            }
            
        }
    }


}



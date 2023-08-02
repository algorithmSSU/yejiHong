#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int const SIZE = 8;
int const dy[4]={-1,1,0,0};
int const dx[4]={0,0,-1,1};

int main_board[SIZE][SIZE];
int sub_board[SIZE][SIZE];
int row, col;
int answer =0;

void copy(int nb[SIZE][SIZE],int ob[SIZE][SIZE]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            nb[i][j]=ob[i][j];
        }
    }
};

// 바이러스 확산 시킨 후 안전범위(확산되지 않은 0공간) 카운팅
void bfs(){
    
    int virus[SIZE][SIZE];
    copy(virus,sub_board);


    queue< pair<int, int> > q;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(virus[i][j]==2){
                q.push(make_pair(i,j)); // 바이러스 위치 모두 queue에 담고
            }
        }
    }
    
    while(!q.empty()){ // 바이러스 담은 곳 모두 방문
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];

            if(ny<0||ny>=row||nx<0||nx>=col)
                continue;
            if(virus[ny][nx]==0){// 1:벽, 2:바이러스, 0:emprt place , 바이러스가 0공간 차지
                virus[ny][nx]=2; // 바이러스 전파
                q.push(make_pair(ny,nx)); 
            }
        }
    }

    // 바이러스 확신 시키고 나서 안전지역 카운팅-> 여전히 0인 공간 카운팅
    int cnt=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(virus[i][j]==0){ 
                cnt++;
            }
        }
    }
    answer = max(cnt,answer);

};


// 😖 너무 어려운 벽 세우기
// * 벽 3개를 세워야함
// * (0,0)부터 차례대로 0인 공간을 1로 채워주면서 3개 설치
// * 3개의 벽 설치
void wall(int w){
    if(w==3){// 세번째 돌 까지 밖에 못둠
        bfs(); //바이러스 전파 -> 오염안된 공간 체크
        return;
    }else{
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(sub_board[i][j]==0){
                    sub_board[i][j]=1;
                    wall(w+1);
                    sub_board[i][j]=0;
                }
            }
        }
    }
}



int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> row >> col;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> main_board[i][j];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(main_board[i][j]==0){
                copy(sub_board,main_board);
                sub_board[i][j]=1;
                wall(1);
                sub_board[i][j]=0;
            }
        }
    }
    cout << answer << endl;

}
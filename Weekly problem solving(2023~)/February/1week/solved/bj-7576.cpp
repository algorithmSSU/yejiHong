#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int before[1001][1001]={0,};
int after[1001][1001]={0,};
queue <pair<int,int> > q;
int row,col;

int my[4] = {-1,1,0,0};
int mx[4] = {0,0,-1,1};

void bfs(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int ny= y+my[i];
            int nx= x+mx[i];

            if(ny<0 || ny>=row || nx<0 || nx>=col)
                continue;
            if(before[ny][nx]==0 && after[ny][nx]==0){
                q.push(make_pair(ny,nx));
                after[ny][nx]=after[y][x]+1;
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int answer=0;

    // input size 
    cin >> col >> row;

    // input 2d array element
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> before[i][j];
        }
    }

    // 2d array seek (seek for element 1)
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(before[i][j]==1){
                // position q.push
                q.push(make_pair(i,j));
            }
        }
    };

    // breadth first search for q
    bfs();


    // before && after : remain 0 -> return -1 
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(before[i][j]==0 && after[i][j]==0){
                cout << -1 << endl;
                return 0;
            }
        }
    }


    // max value search in after
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            answer = max(answer,after[i][j]);
        }
    };
    cout << answer << endl; 




}
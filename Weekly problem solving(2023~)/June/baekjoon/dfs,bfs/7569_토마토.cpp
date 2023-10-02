#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int w, h, l;
int box[101][101][101];
bool visited[101][101][101]={false,};
int dy[6]={0,0,-1,1,0,0};
int dx[6]={-1,1,0,0,0,0};
int df[6]={0,0,0,0,-1,1};
queue<pair<pair<int,int>,int> > q;




void bfs(){
    
    while(!q.empty()){
        int cy,cx,cf;
        cf = q.front().first.first;
        cy = q.front().first.second;
        cx = q.front().second;
        q.pop();
        //visited[cy][cx][cf]=true;


        int ny,nx,nf = 0;
        for(int i=0;i<6;i++){
            ny = cy+dy[i];
            nx = cx+dx[i];
            nf = cf+df[i];
            if(nf>=l || nf<0 || ny>=h || ny<0 || nx>=w ||nx<0){
                continue;
            }else{
                if(box[nf][ny][nx]==0 && !visited[nf][ny][nx]){
                    visited[nf][ny][nx]=true;
                    box[nf][ny][nx]=box[cf][cy][cx]+1;
                    q.push(make_pair(make_pair(nf,ny),nx));
                }
            }
        }

    }

}


int main(){
    
    int answer = 0;
    std::cin >>w >> h >> l;

    for(int i=0;i<l;i++){
        for(int j=0;j<h;j++){
            for(int c=0;c<w;c++){
                std::cin >> box[i][j][c];
                if(box[i][j][c]==1){
                    q.push(make_pair(make_pair(i,j),c));
                    visited[i][j][c] = true;
                }
            }
        }
    };

    bfs();

    
    for(int i=0;i<l;i++){
        for(int j=0;j<h;j++){
            for(int c=0;c<w;c++){
                if(box[i][j][c]==0){
                    answer = -1;
                    std::cout << answer << endl;
                    return 0;
                }else{
                    answer = answer < box[i][j][c] ? box[i][j][c] : answer;
                }
            }
        }
    };

    std::cout << answer-1 << endl;


    return 0;

}
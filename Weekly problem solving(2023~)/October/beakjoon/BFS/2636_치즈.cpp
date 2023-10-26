#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;


int Map[101][101];
bool visited[101][101];
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int cheeze = 0;
queue<pair<int,int> > ch;
int r,c;

void bfs(int y,int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    visited[y][x]=true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny>=0 && nx>=0 && ny<r && nx<c){
                if(!visited[ny][nx] && Map[ny][nx]==0){
                    visited[ny][nx]=true;
                    q.push(make_pair(ny,nx));
                }else if(!visited[ny][nx] && Map[ny][nx]==1){
                    visited[ny][nx]=true;
                    ch.push(make_pair(ny,nx));
                }
            }
        }
    }
}


void init(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            visited[i][j]=false;
        }
    }
}
// 디버그용
void print(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << Map[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    
    vector<int> remain_cheeze;
    int time=0;
    


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> Map[i][j];
            if(Map[i][j]==1){
                cheeze++; // cheeze 갯수 카운팅
            }
        }
    }

    // 한번에 다 없어질 수도 있으니까 처음에 치즈 갯수 담아주기
    remain_cheeze.emplace_back(cheeze);
    


    while(1){
        
        // cheeze 가 하나도 없으면 종료
        if(cheeze==0){
            break;
        }

        time++;

        bfs(0,0);


        // cheeze 테두리 좌표 값 모두 0으로 삭제
        int remove_cheeze = 0;
        while(!ch.empty()){
            int cy = ch.front().first;
            int cx = ch.front().second;
            ch.pop();
            remove_cheeze++;
            Map[cy][cx]=0;
        }

        //cout << "============"<<endl;
        //print();
        

        cheeze-=remove_cheeze;

        // 0이 아닐때만 벡터에 넣기
        if(cheeze!=0){
            remain_cheeze.emplace_back(cheeze);
        }
        

        // 방문배열초기화
        init();

    }


    cout << time << '\n' << remain_cheeze[remain_cheeze.size()-1] << endl;

    





}
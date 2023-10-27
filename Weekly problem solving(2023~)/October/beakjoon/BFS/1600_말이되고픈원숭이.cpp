#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[201][201];
int visited[201][201][32];
int k, w, h;

int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int hy[8]={-1,-2,-2,-1,1,2,2,1};
int hx[8]={-2,-1,1,2,-2,-1,1,2};

void bfs(int y, int x, int move){
    // 좌표 값 (y,x) , 움직임 횟수, 동물조건(원숭이는 상관ㄴㄴ, 말은 횟수 제한 있기 때문)
    queue<pair<pair<int,int>, pair<int,int> > > q;
    q.push(make_pair(make_pair(y,x),make_pair(move,0)));


    // (0,0)지점에 능력 a 번 사용해서 왔습니다 겨우겨우!!!
    visited[0][0][0] = true;


    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cost = q.front().second.first; // 움직임 횟수
        int ability = q.front().second.second; // 원숭이가 말처럼 움직일 수 있는 능력 사용 횟수
        
        q.pop();

        // 만약 현재 오른쪽 맨끝에 있으면 이제까지 움직인 횟수를 출력하고 종료
        if(cy==h-1 && cx==w-1){
            cout << cost << endl;
            return;
        }
        
        
        // 문제에서는 K 번 사용가능
        // 능력 사용이 가능할 때
        // ability 값을 +1 해줘야함 능력을 사용했다고 가정하고 위치이동할때라
        if(ability<k){
            for(int i=0;i<8;i++){
                int ny = cy + hy[i];
                int nx = cx + hx[i];
                if(ny>=0 && nx>=0 && ny<h && nx<w){
                    if(!visited[ny][nx][ability+1] && map[ny][nx]==0){
                        q.push(make_pair(make_pair(ny,nx),make_pair(cost+1,ability+1)));
                        visited[ny][nx][ability+1] = true;
                    }
                }
            }
        }
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny>=0 && nx>=0 && ny < h && nx<w){
                if(!visited[ny][nx][ability] && map[ny][nx]==0){
                    q.push(make_pair(make_pair(ny,nx),make_pair(cost+1,ability)));
                    visited[ny][nx][ability] = true;
                }
            }
        }
    }

    // while loop 종료되었는데 살아있는거보니..도달할 수 없었군
    cout << -1 << endl;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k; // 🐒 가 🐴 능력을 사용할 수 있는 횟수
    cin >> w >> h; // map 의 가로, 세로 값

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> map[i][j];
        }
    }


    bfs(0,0,0); // goal 지점까지 원숭이가 움직인 최소 횟수를 구해야하기 때문에 BFS
    //cout << answer << endl;

}
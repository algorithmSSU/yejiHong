#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 22
int N;

// 상좌우하.....
int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};

int map[MAX][MAX];
int visited[MAX][MAX]={0,};

// 상어의 좌표
pair<int,int> shark;
// 상어의 크기
int sh_size= 2; // 처음에는 2 



int die_fish = 0; // 잡아먹은 물고기 갯수 카운팅
int total_time = 0; // 총 걸린 시간
bool eat = false; // 물고기 먹었는지 판별
bool stop = false; // 물고기 더 이상 먹은거 없는 지 판별

void input(){
    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                //상어시작위치좌표
                shark.first = i;
                shark.second = j;
                map[i][j] = 0;
            }
            
        }
    }
}

void init(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            visited[i][j] = 0;
        }
    }
}

void bfs(){
    queue<pair<int,pair<int,int>>>q;
    q.push(make_pair(0,make_pair(shark.first,shark.second)));
    visited[shark.first][shark.second]= true;
    int one = 0; // 한마리 먹는데 걸린 시간

    while(!q.empty()){
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        int go = q.front().first;

        // 가장 위쪽을 먼저 먹고 그 다음 왼쪽을 먹는 것을 고려
        // 방문순서에 맞게 가장 앞쪽에 왼쪽 좌표가 있을 것, 한마리 == 1초 턴
        if(map[cy][cx]> 0 && map[cy][cx]<sh_size && one==go){
            if((shark.first>cy)|| (shark.first==cy && shark.second > cx)){ // 위쪽 먹 -> 왼쪽 , 현재 위치서 왼쪽 
                shark.first = cy;
                shark.second = cx;
                continue;
            }
        }

        q.pop();

        for(int i=0;i<4;i++){
            int ny = dy[i]+cy;
            int nx = dx[i]+cx;

            if(ny>=0 && nx>=0 && ny<N && nx<N && !visited[ny][nx]){
                if(map[ny][nx]<=sh_size){ // 지나가거나 먹을 수 있는 경우
                    if(map[ny][nx]>0 && map[ny][nx]<sh_size && !eat){ // 물고기 크기가 작고, 상어가 아직 먹은 물고기가 없는 경우
                        eat = true; // 물고기 먹고
                        shark.first = ny;
                        shark.second = nx;
                        one = go+1; // 한 마리 먹는데 걸린 시간
                        total_time+=one; // 총 시간에 추가
                    }else{ // 물고기를 못 먹는 경우,이동은 하기 때문에 이동+1
                        q.push(make_pair(go+1,make_pair(ny,nx)));
                        visited[ny][nx] = true; // 방문체크.
                    }
                }
            }
        }
    }


}
int main(){

    input();

    while(!stop){
        init();
        bfs();
        if(eat){ // 먹었을 경우 
            eat= false;
            die_fish+=1;
            map[shark.first][shark.second] = 0; // 먹은 물고기 삭제 0
            if(die_fish == sh_size){
                sh_size+=1; // 먹은 물고기 수 == 상어의 크기 then 상어의 크기 + 1
                die_fish=0; // 먹은 물고기 수 초기화
            }
        }else{ // 한 마리도 먹지 못한 경우
            stop=true; //엄마 상어에게 도움 요청
        }
    }
    cout << total_time << '\n';
    return 0;



}
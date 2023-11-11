#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,K;
vector<pair<int,int>> cloud;
int map[1001][1001]={0,};
bool visited[1001][1001]={false,};
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};

void input(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int temp = 0;
            cin >> temp;
            if(temp==1){
                map[i][j]=-1;
                cloud.emplace_back(i,j);
            }
        }
    }
}

void bfs(int y,int x){
    for(int i=0;i<8;i++){
        int ny= y+dy[i];
        int nx= x+dx[i];
        if(ny>=0 && nx>=0 && ny<N && nx<N && map[ny][nx]!=-1){
            map[ny][nx]+=1;
        }
    }
}
int bfs_2(int y,int x){
    int answer = 0;
    for(int i=0;i<8;i++){
        int ny= y+dy[i];
        int nx= x+dx[i];
        if(ny>=0 && nx>=0 && ny<N && nx<N && !visited[ny][nx]){
            if(map[ny][nx]==K){
                visited[ny][nx]=true;
                answer++;
            }
        }
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    input();

    // 깃발값 저장
    for(auto pos : cloud){
        bfs(pos.first,pos.second);
    }

    // 찾으려는 깃발 넘버 카운팅
    for(auto pos : cloud){
        cnt+=bfs_2(pos.first,pos.second);
    }

    cout << cnt << endl;






}
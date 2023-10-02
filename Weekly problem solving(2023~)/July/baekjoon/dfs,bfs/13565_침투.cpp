#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int M,N;
int digiter[1001][1001]={1,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
bool visited[1001][1001]={false,};


bool flag = false;
void bfs(int y,int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        digiter[cy][cx] = 1;
        int m = M - 1;
        if(cy==m){
            flag = true;
        }
        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny>=0 && nx>=0 && ny<M && nx<N){
                if (digiter[ny][nx]!=1 && !visited[ny][nx])
                {
                    visited[ny][nx]=true;
                    digiter[ny][nx]=digiter[cy][cx]+1;
                    q.push(make_pair(ny,nx));
                
                }
            }
        }
    }

}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;

    for(int i=0;i<M;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            digiter[i][j]=str[j]-'0';
        }
    }

    // 맨위(바깥이라함) 에서 챡 (모든 열에) 물질흡수
    for(int i=0;i<N;i++){
        bfs(0,i);
    }

    
    int cnt=0;
    for(int i=0;i<M;i++){
        if(digiter[N-1][i]==0){
            cnt++;
        }
    };

    // 바닥에 닿은물질이 하나라도 있으면 통과
    if(flag){
        cout << "YES" << '\n';
    }else{
        cout << "NO" << '\n';
    }



}
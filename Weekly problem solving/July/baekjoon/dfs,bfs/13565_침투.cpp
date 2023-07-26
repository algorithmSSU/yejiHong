#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int M,N;
int digiter[1001][1001]={1,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
bool visited[1001][1001]={false,};

void bfs(int y,int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        digiter[cy][cx] = 1;
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

    bfs(0,0);

    
    bool flag = false;
    int cnt=0;
    for(int i=0;i<M;i++){
        if(digiter[N-1][i]==0){
            cnt++;
        }
    };

    if(cnt==M){
        cout<< "NO" << '\n';
    }else{
        cout << "YES" << '\n';
    }







}
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char map[251][251];

// #은 건너뜀
// 그외에 다 탐색
// wolf,sheep
bool visited[251][251]={false,};
int dy[4]={0,0,1,-1};
int dx[4]={-1,1,0,0};
int R, C;
pair<int,int> bfs(int y,int x){
    queue<pair<int,int> > q;
    pair<int,int> res;
    q.push(make_pair(y,x));
    int sheep = 0;
    int wolf = 0;
    
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        if(map[cy][cx]=='k'){
            sheep++;
        }else if(map[cy][cx]=='v'){
            wolf++;
        }
        q.pop();
        visited[cy][cx]=true;
        
        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];

            if(ny>=0 && nx>=0 && ny<R && nx<C){
                if(map[ny][nx]!='#' && !visited[ny][nx]){
                    visited[ny][nx]=true;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    };

    if(sheep<=wolf){
        res.first = wolf;
        res.second = 0;
    }else if(sheep>wolf){
        res.first = 0;
        res.second = sheep;
    };

    return res;
}


int main(){

    
    cin >> R >> C;

    int k=0;
    int v=0;

    for(int i=0;i<R;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            map[i][j]=str[j];
        }
    }


    vector<pair<int,int> > l;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]=='#' || visited[i][j]){
                continue;
            }else{
                pair<int,int> temp=bfs(i,j);
                l.emplace_back(temp);
            }
        }
    };

    for(int i=0;i<l.size();i++){
        v+=l[i].first;//wolf
        k+=l[i].second;//sheep
    };

    cout << k << " " << v << '\n';

}
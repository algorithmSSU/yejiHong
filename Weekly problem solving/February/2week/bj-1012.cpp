#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int map[51][51]={0,};
int w,h,c;

queue< pair<int, int> > q;
vector<int> v;
int visited[51][51]={0,};

int my[4]={-1,1,0,0};
int mx[4]={0,0,-1,1};

int bfs(){

    int count =1;

    while(!q.empty()){
        int oy,ox,ny,nx;
        oy = q.front().first;
        ox = q.front().second;
        q.pop();
        
        for(int i=0; i<4;i++){
            ny = oy+my[i];
            nx = ox+mx[i];
            if(ny<0 || ny>=w || nx<0 || nx>=h){
                continue;
            }
            if(map[ny][nx]==1 && visited[ny][nx]==0){
                visited[ny][nx]=1;
                q.push(make_pair(ny,nx));
            }
        };
    };
    
    return count;
};


int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;
    int temp = 0;
    for(int i=0;i<n;i++){
        cin >> w >> h >> c;
        for(int j=0;j<c;j++){
            int x,y;
            cin >> y >> x;
            map[y][x]=1;
            
        };
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                if(map[i][j]==1 && visited[i][j]==0){
                    q.push(make_pair(i,j));
                    temp+=bfs();
                }
            }
        }
        v.push_back(temp);

        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        temp =0;
    };

    for(int i=0;i<v.size();i++){
        cout << v[i] << "\n";
    };


    return 0;

}
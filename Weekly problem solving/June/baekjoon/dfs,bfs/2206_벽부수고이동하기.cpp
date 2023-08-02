#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int h, w;
int map[1001][1001];
bool visited[1001][1001]= {false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
queue<pair<int,int> > q;
int distmap[1001][1001]={0,};
vector<int> dist;

int bfs(int y,int x){
    // 거리기록배열 초기화
    memset(distmap,0,sizeof(int)*w);
    int answer = 0;
    queue<pair<int ,int> > bq;
    bq.push(make_pair(1,1));
    while(!bq.empty()){
        int cy = bq.front().first;
        int cx = bq.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny<0 || ny>=h || nx<0 || nx>=w){
                continue;
            }else{
                if(y==ny && x==nx){
                    visited[ny][nx] = true;
                    distmap[ny][nx]=distmap[cy][cx]+1;
                    bq.push(make_pair(ny, nx));
                }else if(!visited[ny][nx] && map[ny][nx]==0){
                    visited[ny][nx] = true;
                    distmap[ny][nx] = distmap[cy][cx] + 1;
                    bq.push(make_pair(ny,nx));
                }
            }
        }
    };

    int maxv = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            maxv = maxv < map[i][j]?map[i][j] : maxv;
        }
    };

    if(distmap[h-1][w-1]==0){
        answer=-1;
    }else{
        answer = maxv;
    };

    return answer;
}



int main(){
    
    int ans = 0;
    std::cin >> h >> w;

    for(int i=0;i<h;i++){
        string str;
        std::cin >> str;
        int size = str.length();
        for(int j=0;j<size;j++){
            map[i][j]=str[j];
            if(map[i][j]==1){
                q.push(make_pair(i,j)); // only 1
            }
        };
    };

    // 상하 또는 좌우 0으로 둘러싸인 좌표 뽑아내기
    vector<pair<int, int> > candidate;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();


        int td = 0;
        int lr = 0;
        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];

            if(ny<0 || ny>=h || nx<0 || nx>=w){
                continue;
            }else{
                if(i<=1 && map[ny][nx]==0){
                    lr++;
                }else if(i>1 && map[ny][nx]==0){
                    td++;
                };
            };
            if (lr >= 1 || td >= 1)
            {
                candidate.emplace_back(ny, nx);
            };
        }
    };

    // 네??? 왜 0이죠? 👿👿👿👿👿👿👿
    std::cout << candidate.size() << endl;

    if(candidate.size()==0){
        ans = -1;
        std::cout << ans << endl;
        return 0;
    }

    for(int i=0;i<candidate.size();i++){
        int res=bfs(candidate[i].first, candidate[i].second);
        if(res!=-1){
            dist.emplace_back(res);
        };
    };

    
    if(dist.size()==0){
        ans = -1;
    }else{
        sort(dist.begin(),dist.end());
        ans = dist.front();
    };

    std::cout << ans << endl;
    return 0;
}
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n;
int w, h, spot;
queue<pair<int,int> > q;
int arr_map[51][51]={0,};
bool visited[51][51]={false,};
vector<int> answer;

int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

void dfs(int y,int x){

    if(!visited[y][x]){
        visited[y][x]=true;
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny>=h || ny<0 || nx>=w || nx<0){
                continue;
            }else{
                if(arr_map[ny][nx]==1 && !visited[ny][nx]){
                    dfs(ny,nx);
                }
            }
        }
    }
    
};

int main(){

    
    std::cin >> n;

    for(int i=0;i<n;i++){
        std::cin >> w >> h >> spot;
        for(int j=0;j<spot;j++){
            int y,x;
            std::cin >> x >> y;
            arr_map[y][x]=1;
            q.push(make_pair(y,x));
        };

        int cnt = 0;
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if(!visited[y][x]){
                cnt++;
                dfs(y, x);
            }else{
                continue;
            }
        };
        answer.emplace_back(cnt);

        for(int i=0;i<h;i++){
            memset(arr_map[i],0,sizeof(arr_map[i]));
            memset(visited[i],0,sizeof(visited[i]));
        };
    };

    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i] << '\n';
    };
}
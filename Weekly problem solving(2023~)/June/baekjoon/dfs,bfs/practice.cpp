#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main(){

    int n;
    int w,h,spot;
    vector<int>answer ;
    std::cin >> n;

    int dy[4]={0,0,-1,1};
    int dx[4]={-1,1,0,0};

    for(int i=0;i<n;i++){
        queue<pair<int,int> > q;
        stack<pair<int,int> > s;
        int map[51][51]={0,};
        bool visited[51][51]={false,};
        std::cin >> w >> h >> spot;
        for(int j=0;j<spot;j++){
            int y,x;
            std::cin >> x >> y;
            map[y][x]=1;
            q.push(make_pair(y,x));
        };
        int cnt =0;
        while(!q.empty()){
            int cy,cx;
            cy = q.front().first;
            cx = q.front().second;
            q.pop();
            if(!visited[cy][cx]){
                cnt++;
                s.push(make_pair(cy, cx));
                visited[cy][cx]=true;
                while (!s.empty())
                {
                    int cur_y = s.top().first;
                    int cur_x = s.top().second;
                    s.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int ny, nx;
                        ny = cur_y + dy[i];
                        nx = cur_x + dx[i];

                        if (ny >= h || ny < 0 || nx >= w || nx < 0)
                        {
                            continue;
                        }
                        else
                        {
                            if (map[ny][nx] == 1 && !visited[ny][nx])
                            {
                                visited[ny][nx] = true;
                                s.push(make_pair(ny, nx));
                            };
                        };
                    };
                };
            }else{
                continue;
            }
        };
        answer.emplace_back(cnt);
    };

    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i] << '\n';
    }
}
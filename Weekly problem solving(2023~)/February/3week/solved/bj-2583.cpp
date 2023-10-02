#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int M,N,K;
int map[101][101] = {0,};
int visited[101][101]={0,};
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

struct info{
    int start_y, start_x, end_y, end_x=0;
    
};


void fill(info im){
    for(int i=im.start_y; i<im.end_y;i++){
        for(int j=im.start_x; j<im.end_x;j++){
            map[i][j]=1;
        }
    }
};

int bfs(int y,int x){
    int count=0;
    queue< pair<int,int> > q;
    q.push(make_pair(y,x));
    

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int ny= cy+dy[i];
            int nx= cx+dx[i];
            if(ny <0 || ny >=M || nx < 0 || nx >=N)
                continue;
            if(map[ny][nx]==0 && visited[ny][nx]!=1){
                count ++;
                visited[ny][nx] = 1;
                q.push(make_pair(ny,nx));
            }
        }
    }
    return count;
}


int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> M >> N >> K;

    vector<info> input;

    for(int i=0;i<K;i++){
        info information;
        cin >> information.start_x >> information.start_y >> information.end_x >> information.end_y;
        input.emplace_back(information);
    }

    // 색칠
    int input_size = input.size();
    for (int i = 0; i < input_size; i++)
    {
        fill(input[i]);
    };

    /*
        for(int i=0;i<M;i++){
            cout << "\n";
            for(int j=0; j<N;j++){
                cout << map[i][j];
            }
        }
    */
   int ans = 0;
   vector<int> res;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==0 && visited[i][j]==0){
                int temp= bfs(i,j);
                if(temp==0){
                    res.emplace_back(1);
                }else{
                    res.emplace_back(temp);
                };
                ans++;
            }
        }
    }
    sort(res.begin(),res.end());

    cout << ans << endl;
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }

    
    return 0;

    

}
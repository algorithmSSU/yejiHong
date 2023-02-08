// 테스트 3개 통과 못함..이유못찾음 
// 다시해보기
 
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using std::pair;

using namespace std;

int row,col;
int dist[2][1001][1001]={0,};
int**map=new int*[row];
int visited[2][1001][1001]={0,};
pair <int, int> y;
pair <int, int> k;
vector< pair<int,int> > msb;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int c = 0;

void bfs(int i,int j){
    queue <pair<int,int> > q;
    q.push(make_pair(i,j));
    visited[c][i][j]=1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0||ny>=row||nx<0||nx>=col)
                continue;

            if(map[ny][nx]!=1&&visited[c][ny][nx]==0){
                visited[c][ny][nx]=1;
                dist[c][ny][nx]=dist[c][y][x]+1;
                q.push(make_pair(ny,nx));
            }
        }
    }
    c++;
}


int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> col >> row;

    for(int i=0;i<row;i++){
        map[i]=new int[col];
    };


    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int temp;
            cin >> temp;
            map[i][j]=temp;
            
            if(temp==2){
                y.first = i;
                y.second =j;
            };
            if(temp==3){
                k.first =i;
                k.second=j;
            };
            if(temp==4){
                msb.push_back(make_pair(i,j));
            }
        }
    };

    bfs(y.first,y.second);
    bfs(k.first,k.second);
/*
    // predict
    cout << "=================================" << endl;

    // go영희
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << dist[0][i][j] << " ";
        }
        cout << "\n";
    };

    cout << "=================================" << endl;
    // go기사
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << dist[1][i][j] << " ";
        }
        cout << "\n";
    };
*/
    vector<int> ans;

    for(int i=0;i<msb.size();i++){
        int y= msb[i].first;
        int x= msb[i].second;

        int young,knight;
        young = dist[0][y][x];
        knight = dist[1][y][x];

        ans.push_back(young+knight);

    };

/*
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

*/

    sort(ans.begin(),ans.end());
    cout << ans[0] << endl; 


    
    return 0;
    
    
}
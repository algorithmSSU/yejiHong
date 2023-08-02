// Corrected by study feedback
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <memory.h>

    using std::pair;
using namespace std;

const int SIZE = 101;
int n;
char area[SIZE][SIZE]={0,};

int visited[SIZE][SIZE] ={0,};

vector< pair<int,int> > g;


int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void fill(int size){
    char a;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin >> area[i][j];
            if(area[i][j]=='G'){
                g.emplace_back(i,j);
            }
        }
    }
};

void bfs(int r,int c){
    queue< pair<int,int>> q;
    q.push(make_pair(r,c));
    visited[r][c]=1;

    while(!q.empty()){
        int y,x;
        y = q.front().first;
        x = q.front().second;
        char previous = area[y][x];

        q.pop();

        for(int i=0;i<4;i++){
            int ny,nx;
            ny = y+dy[i];
            nx = x+dx[i];
            if(ny <0 || ny>=n || nx <0 || nx>=n)
                continue;
            if (visited[ny][nx] != 1 && previous== area[ny][nx])
            {
                visited[ny][nx]=1;
                q.push(make_pair(ny,nx));
            }
        }
    }
}


void green_setting(){
    for (int i = 0; i < g.size(); i++)
    {
        int r, c;
        r = g[i].first;
        c = g[i].second;
        area[r][c] = 'R';
    };
}

int counting(){

    int count =0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (visited[i][j] != 1)
            {
                bfs(i,j);
                count++;
            }
        }
    }
    return count;
}



int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int normal_freq, weakness_freq = 0;

    cin >> n;

    fill(n);

    

    normal_freq = counting();

    green_setting();

    for (int i = 0; i < n; i++)
    {
        memset(visited[i], 0, sizeof(int) * n);
    };

    weakness_freq = counting();

    cout << normal_freq << " " << weakness_freq << endl;


    return 0;
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int h, w, line;
int hall[101][101]={0,};
bool visited[101][101]={false,};

int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

int mv=0;
int dfs(int y, int x){
    stack<pair<int,int> > s;
    s.push(make_pair(y,x));
    // count
    int food_size = 0;

    while(!s.empty()){
        food_size++;
        int cy = s.top().first;
        int cx = s.top().second;
        s.pop();
        visited[cy][cx]=true;
        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny <0 || nx < 0 || ny>=h || nx >=w){
                continue;
            }else{
                if(hall[ny][nx]==1 && visited[ny][nx]==false){
                    hall[ny][nx]=hall[cy][cx]+1;
                    s.push(make_pair(ny,nx));
                }
            }
        }
        //cout << hall[cy][cx] << endl;
    }
    //cout << hall[y][x] << endl;

    mv=mv<=food_size ? food_size : mv;
    return food_size;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    

    cin >> h>> w >> line;

    for(int i=0;i<line;i++){
        int y,x;
        cin >> y >> x;
        hall[y-1][x-1] = 1; 
    };



    int maxvalue = 0;
    int temp = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(hall[i][j]!=0 && visited[i][j]==false){
                dfs(i,j);
            }
        }
    };    
    
    cout << mv << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,K;
char MAP[203][203];
long long nmap[203][203]={0,};
vector<pair<int,int>> bomb;
int dy[5]={0,0,-1,1,0}; // 자기자신
int dx[5]={1,-1,0,0,0};
vector<pair<int,int>> check_list;


void input(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> MAP[i][j];
        }
    }

    for(int i=0;i<K;i++){
        int a, b;
        cin >> a >> b;
        bomb.emplace_back(a,b);
    }
}

void bfs(int y,int x){
    for(int i=0;i<5;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=1 && nx>=1 && ny<=N && nx<=N && MAP[ny][nx]!='#'){  
            if(!nmap[ny][nx]){
                check_list.emplace_back(ny,nx);
            }          
            if(MAP[ny][nx]=='@'){
                nmap[ny][nx]+=2;
            }else if(MAP[ny][nx]=='0'){
                nmap[ny][nx]+=1;
            }
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> bomb_after;

    input();

    for(auto it : bomb){
        bfs(it.first,it.second);
    }

    long long answer = 0;
    for(auto it : check_list){
        int cy = it.first;
        int cx = it.second;

        // char area = MAP[cy][cx];
        int temp = nmap[cy][cx];

        answer = answer < temp ? temp : answer;
    }
    cout << answer << '\n';
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
int click=0;
bool visited[1000001]={false,};
int m[2]={0,};

void bfs(int start,int target){
    queue<pair<int,int> > q;
    
    q.push(make_pair(start,0));

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        visited[now]=true;
        cout << "now: " << now << '\n';
        
        if(now==G){
            click = cost;
        }
        
        for(int i=0;i<2;i++){
            int next = now + m[i];
            if(F>=next && 0<next){
                if(!visited[next]){
                    visited[next]=true;
                    q.push(make_pair(next,cost+1));
                }
            }
        }
    }
}


int main(){

    cin >> F >> S >> G >> U >> D;
    int ans = 0;


    m[0]=U;
    m[1]=-D;

    bfs(S,G);

    if(!visited[G]){
        cout << "use the stairs" << '\n';
    }else{
        cout << click << '\n';
    }
}
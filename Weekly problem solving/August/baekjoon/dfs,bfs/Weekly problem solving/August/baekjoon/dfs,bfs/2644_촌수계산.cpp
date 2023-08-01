#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> v[101];
int visited[101]={0,};

void bfs(int start){
    queue<int> q;
    q.push(start);
    //visited[start]=0;
    while(!q.empty()){
        int cursor = q.front();
        q.pop();
        for (int i = 0; i < v[cursor].size(); i++)
        {
            int next = v[cursor][i];
            if(!visited[next]){
                q.push(next);
                visited[next]=visited[cursor]+1;

            }
        }
    }
}

int main(){
    int n;
    int p1, p2;
    int line;
    cin >> n;
    cin >> p1 >> p2;
    cin >> line;


    
    for(int i=0;i<line;i++){
        int a,b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);   
    }

    bfs(p1);

    if(visited[p2]==0){
        cout << -1 << '\n';
    }else{
        cout << visited[p2] << '\n';
    }

    

}
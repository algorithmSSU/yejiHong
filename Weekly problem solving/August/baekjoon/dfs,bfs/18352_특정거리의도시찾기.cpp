#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x;
vector<int> map[300001];
bool visited[300001]={false,};
int cost[300001]={0,};
vector<int> city;

void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int now = q.front();
        visited[now]=true;
        
        q.pop();

        if(cost[now]==k){
            city.emplace_back(now);
        }

        for(int i=0;i<map[now].size();i++){
            int next = map[now][i];
            if(!visited[next]){
                visited[next]=true;
                cost[next]= cost[now]+1;
                q.push(next);
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k >> x;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        map[a].emplace_back(b);
    }


    bfs(x);

    sort(city.begin(),city.end());
    if(city.size()==0){
        cout << -1 << '\n';
    }else{
        for (int i = 0; i < city.size(); i++)
        {
            cout << city[i] << '\n';
        }
    }
    

}
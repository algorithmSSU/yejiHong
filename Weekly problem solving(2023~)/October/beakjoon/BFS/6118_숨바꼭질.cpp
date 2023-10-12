#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> Map[100001];
bool visited[100001]={false,};
int sequence[100001];
int N,M;

void bfs(int start){
    queue<pair<int,int> > q;
    q.push(make_pair(start,0));
    
    
    int idx = 0;
    int walk = 0;
    visited[start]=true;
    sequence[start]=walk;


    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        sequence[cur]=cost;

        q.pop();

        for(int i=0;i<Map[cur].size();i++){
            int next = Map[cur][i];
            if(!visited[next]){
                visited[next]=true;
                q.push(make_pair(next,cost+1));
            }
        }
    }
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<M;i++){
        int from,to;
        cin >> from >> to;
        Map[from].emplace_back(to);
        Map[to].emplace_back(from);
    }

    bfs(1);//1 부터 시작


    // for(int i=1;i<=N;i++){
    //     cout << sequence[i] << " ";
    // }


    // Max disctance 찾자
    int Max_dist = -1;
    for(int i=1;i<=N;i++){
        Max_dist = max(Max_dist,sequence[i]);
    }

    // 거리가 같은 헛간이 여러개면 가장 작은 헛간 번호를 출력한다.
    // 헛간 개수를 세준다
    int h_num = 1e9;
    int cnt = 0;
    for(int i=1;i<=N;i++){
        if(Max_dist==sequence[i]){
            h_num = min(h_num,i);
            cnt++;
        }
    }


    // 헛간번호 / 거리 / 같은거리를 가지는 헛간의 개수
    cout << h_num << " " << Max_dist << " " << cnt << '\n';










}
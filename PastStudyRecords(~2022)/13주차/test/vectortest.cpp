#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int num);
bool visit[1000] = {false};
vector<vector<int>> v(1000); // 벡터를 1000칸 확보
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int temp = 6;

    for (int i = 0;i<temp;i++){
        int x, y;
        cin >> x>> y;

        v[x].push_back(y);
        v[y].push_back(x);
    };

    dfs(1);
};

void dfs(int num){
    queue<int> q;
    q.push(num);
    int cnt = 0;

    while(!q.empty()){
        int now = q.front();
        visit[now] = true;
        q.pop();

        for (int i = 0; i < v[now].size();i++){
            int next = v[now][i];

            if(!visit[next]){
                q.push(next);
                cnt++;
            };
        };
    };
    cout << cnt << endl;
};
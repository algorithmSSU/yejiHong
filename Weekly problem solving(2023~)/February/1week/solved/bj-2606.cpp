#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> arr[101];
int visited[101]={0,};
int cnt;
int dfs(int start){
    stack<int> s;
    cnt = 0;
    s.push(start);
    while(!s.empty()){
        int cur = s.top();
        s.pop();

        for(int i=0;i<arr[cur].size();i++){
            int next = arr[cur][i];
            if(visited[next]==0){
                visited[next]=1;
                s.push(next);
                cnt++;
            };

        }
    };

    return cnt;
    
    
}
int main(){

    int answer = 0;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;

    cin >> n;
    cin >> m;

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    };
    
    answer = dfs(1);

    cout << answer-1 << endl;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr[1001];
int visited[1001]={0,};
int cnt=1;

void dfs(int start){

    visited[start]=1;

    if(arr[start].size()==0){
        return;
    }
    
    for(int i=0;i<arr[start].size();i++){
        int next = arr[start][i];
        if(visited[next]!=1){
            visited[next]=1;
            dfs(next);
        }
    };
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);

    };

    vector<int> v;
    int freq = 0;
    for(int i=1;i<=n;i++){
        if(visited[i]!=1){
            dfs(i);
            freq++;
            //v.push_back(temp);
        };
    };


    cout << freq << endl;

/*
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    };
*/

    return 0;
    


}


/*

- 방문체크가 핵심
- 방문했는지 체크하고 방문안했으면,
 dfs 로 가지고 있는 정점을 방문해서 방문체크함
- input 으로 주어진 정점을 모두 돌면서 방문체크안한 갯수를 세면 되는 문제다.



*/
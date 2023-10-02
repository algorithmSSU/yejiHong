#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


bool comapare(int a, int b){
    if(a>b){
        return a>b;
    }else{
        return a<b;
    }
}

double vertex, e, start;
vector<int> v[100002];
bool visited[100002] = {
    false,
};
int com=1;
int record[100002]={0,};



void dfs(int start){
    visited[start]=true;
    record[start]=com++;
    for(int i=0;i<v[start].size();i++){
        int next = v[start][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}


int main(){
    
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> vertex >> e >> start;

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    };

    for(int i=0;i<=vertex;i++){
        sort(v[i].begin(),v[i].end(),greater<int>());
    };

    dfs(start);

    for(int i=1;i<=vertex;i++){
        cout << record[i] << '\n';
    }

}
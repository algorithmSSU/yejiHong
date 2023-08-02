#include <iostream>
#include <vector>


using namespace std;
vector<int> v[101];
bool visited[101] = {false,};
int cnt = 0;


void dfs(int start){
    visited[start]=true;
    for(int i=0;i<v[start].size();i++){
        int next = v[start][i];
        if (!visited[next]){
            cnt++;
            dfs(next);
        }
    }

}

int main(){
    int n;
    int line;

    cin >> n;
    cin >> line;


    for(int i=0;i<line;i++){
        int x,y;
        cin >> x >> y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    };

    dfs(1);
    cout << cnt << endl;
}
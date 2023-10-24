#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory.h>

using namespace std;

int arr[102];
int answer[102];
int idx= 0;
bool visited[102]={false,};
int n;

void dfs(int current, int start){
    if(visited[current]){
        if(current == start){
            answer[idx++]=current;
        }
    }else{
        visited[current]=true;
        dfs(arr[current],start);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    };

    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        dfs(i,i);
    }

    cout << idx << endl;
    for(int i=0;i<idx;i++){
        cout << answer[i] << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int N;
int arr[102];
bool visited[102];
vector<int> temp;
set<int> answer;

bool flag = false;


void dfs(int idx,int value){
    if(visited[value]){
        if(idx==value){
            flag=true;
            answer.insert(value);
        }
        return;
    }
    visited[value]=true;
    dfs(idx,arr[value]);
    if(flag){
        answer.insert(value);
        answer.insert(arr[value]);

    }


    
}


void init(){
    for(int i=1;i<103;i++){
        visited[i]=false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    for(int i=1;i<=N;i++){
        visited[i]=true;
        dfs(i,arr[i]);
        init();
        flag=false;
    }

    cout << answer.size() << '\n';
    for(auto it : answer){
        cout << it << '\n';
    }



}
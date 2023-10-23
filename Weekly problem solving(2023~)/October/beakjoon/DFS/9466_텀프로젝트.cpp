#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;

#define Max 100001


int T, n;
int arr[Max];
bool check[Max];
bool visited[Max]={false,};
int Cnt = 0;


void dfs(int start){
    visited[start] = true;
    int next = arr[start];

    if(!visited[next]){
        dfs(next);
    }else if(!check[next]){
        for(int i=next; i!=start; i=arr[i]){
            Cnt++;
        }
        Cnt++;
    }
    check[start]=true;
}

void init(){
    Cnt = 0;
    memset(visited,false,sizeof(visited));
    memset(check,false,sizeof(check));
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> answer;
    
    cin >> T;

    while(T--){
        cin>> n;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        for(int j=1;j<=n;j++){
            if(!visited[j]){
                dfs(j);
            }
        }
        answer.emplace_back(n-Cnt);
        init();

    }


    for(auto i : answer){
        cout << i << '\n';
    }
    return 0;
}
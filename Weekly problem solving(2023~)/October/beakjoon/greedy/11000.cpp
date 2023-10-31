#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


#define MAX 987654321
priority_queue<pair<int,int>> q;
vector<int> timelog[200001];
int visited[MAX]={false,};

int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;


    for(int i=0;i<N;i++){
        int start,end;
        cin >> start >> end;
        q.push(make_pair(end,start));
    }

    int prevend = q.top().first;
    int cnt = 1;
    q.pop();


    while(!q.empty()){
        int end = q.top().first;
        int start = q.top().second;
        q.pop();

        if(prevend<=start){
            if(!visited[end]){
                timelog[end].emplace_back(start);
                visited[end] = 1;
                cnt++;
            }
        }
        prevend = end;
    }

    
    // for(auto it : visited){
    //     if(it){
    //         cnt++;
    //     };
    // };


    cout << cnt << endl;


}
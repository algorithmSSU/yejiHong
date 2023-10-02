#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    deque<int> q;
    vector<int> v[1000];
    cin >> n;


    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        q.push_back(t);
    };

    int idx=0;
    while(n--){
        for(int i=0;i<n;i++){
            int next = q.front();
            v[idx].emplace_back(next);
            q.pop_front();
            q.push_back(next);
        };
        idx++;
        int next = q.front();
        q.pop_front();
        q.push_back(next);
    };


    
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        };
        cout << '\n';
    }





}
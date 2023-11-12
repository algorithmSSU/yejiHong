#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> times;
    for(int i=0;i<N;i++){
        int start,end;
        cin >> start >> end;
        times.emplace_back(end,start);
    }


    sort(times.begin(),times.end());

    // for(auto it : times){
    //     cout << it.first << " " << it.second << endl;
    // }


    int next = times.front().first;


    int cnt =1; // 하나는 이미 성공
    for(int i=1;i<times.size();i++){
        if(next <= times[i].second){
            cnt++;
            next = times[i].first;
        }
    }

    cout << cnt << '\n';
}
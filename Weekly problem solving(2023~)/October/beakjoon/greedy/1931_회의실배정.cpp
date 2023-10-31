#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<pair<int,int> > schedule;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for(int i=1;i<=N;i++){
        int start, end;
        cin >> start >> end;
        schedule.emplace_back(end,start);
    };

    sort(schedule.begin(), schedule.end());

    int time = schedule[0].first; // 종료시점 젤 작은 게
    int success = 1; // 종료시점이 젤 작은거 하나는 먹고 들어감
    for(int i=1;i<schedule.size();i++){
        if(time <= schedule[i].second){
            time = schedule[i].first;
            success++;
        }
    }
    cout << success << endl;


}
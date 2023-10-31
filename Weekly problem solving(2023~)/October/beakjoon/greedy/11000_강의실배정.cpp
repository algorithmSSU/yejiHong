#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



int N;
vector<pair<int,int> > v;
priority_queue<int,vector<int>,greater<int> > q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for(int i=0;i<N;i++){
        int start, end;
        cin >> start >> end;
        v.emplace_back(start,end);
    }

    // 시작 시간이 이른것부터 강의 정보 정렬
    sort(v.begin(),v.end());

    q.push(v[0].second);
    int cnt = 1;

    for(int i=1;i<v.size();i++){
        if(v[i].first >= q.top()){
            q.pop(); 
            // 그 다음 강의 시작 시간이 앞 시간의 강의 종료 시간보다 더 늦거나 같을경우
            // 강의실 추가 대여 필요없음 -> 어차피 끝났으니 이어서 쓰면 됨 -> 현재 강의 종료 시간 pop();
            q.push(v[i].second); // 그 다음 강의 종료시간을 담고
        }else if(v[i].first < q.top()){ // 그 다음 강의 시작 시간보다 앞 시간 강의 종료 시간이 늦을경우
            q.push(v[i].second);
            cnt++; // 강의실 하나 더 필요
        }
    }
    cout << cnt << '\n';


}
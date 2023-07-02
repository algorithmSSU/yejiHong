#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second < b.second;
    }else if(a.first > b.first){
        return a.first < b.first;
    };
    return a.second > b.second;
}

int solution(vector<vector<int> > jobs) {
    int answer = 0;
    vector<pair<int,int> > v;

    for(int i=0;i<jobs.size();i++){
        v.emplace_back(jobs[i][0],jobs[i][1]);
    };

    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    return answer;
} 







int main(){
    vector<vector<int> > v ={{0,3},{0,1},{1,9},{2,6}};
    int ans = 0;
    ans = solution(v);

}
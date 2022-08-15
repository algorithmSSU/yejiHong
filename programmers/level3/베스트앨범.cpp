#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using std::pair;
using namespace std;
struct compare
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        };
        return a.first < b.first;
    };
};
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, compare>> album;
    //map<string, priority_queue<pair<int,int>>> album;

    /*
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare

    이부분이 감점의 원인이었음
    이해가 안간다...
    
    */

    map<string, int> max_play;
    map<string, priority_queue<int>>::iterator ptr;
    map<string, int>::iterator p;
    for (int i = 0; i < genres.size();i++){
        album[genres[i]].push(make_pair(plays[i],i));
        max_play[genres[i]] += plays[i];
    };

    priority_queue<pair<int, string>> pq;
    vector<pair<int,int>> index;

    for (p = max_play.begin(); p!= max_play.end();p++)
    {
        pq.push(make_pair(p->second, p->first));
    };

    while(!pq.empty()){
        string cur = pq.top().second;
        for (auto a: album){
            if(a.first == cur){
                if(a.second.size()==1){
                    index.push_back(make_pair(a.second.top().first,a.second.top().second));
                }else{
                    for (int i = 0; i < 2;i++){
                        pair<int, int> temp;
                        temp = a.second.top();
                        index.push_back(temp);
                        a.second.pop();
                    };
                };
            };
        };
        pq.pop();
    };

    for (int i = 0; i < index.size();i++){
        answer.push_back(index[i].second);
    }

    return answer;
};

vector<string> geners={"classic", "pop", "classic", "classic", "pop"};
vector<int> plays = {500, 600, 150, 800, 2500};


int main(){
    vector<int> ans;

    ans = solution(geners, plays);

    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << endl;
    }
};

/*

idea
1. map<string, priority_queue<pair<int,int>>> m;

m 자료구조에 '곡이름': '플레이시간','인덱스' 를 저장

-> classic / pop
    500, 0 / 600, 1
    150, 2 / 2500, 0
    800, 3

2. 장르별 플레이시간 합산을 해서 priority_queue에 저장
-> 플레이시간을 first 인자로 두어서 정렬이 되게 끔

-> (back) classic,1450 / pop,3100 (Front)


3. 장르별 플레이 시간이 담겨 있는 queue에 원소가 없을 때 까지 반복
1번에 만들어주었던 m 에서 원소 두개씩 index 에 저장(m도 플레이 시간이 긴 거 부터 정렬되어 있음)


*/
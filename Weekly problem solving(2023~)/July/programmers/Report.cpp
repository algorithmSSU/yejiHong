#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <set>

using namespace std;
struct info{
    set<string>rlist;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    int answer[1024]={0,};
    vector<int> res;
    map<string,int> raw;
    map<string,info> record;
    map<string,info>::iterator p;
    map<string, int> report_count; // 신고 횟수 센 변수


    // 사용자 : 출력시 인덱스 저장
    for(int i=0;i<id_list.size();i++){
        report_count[id_list[i]] = 0;
        raw[id_list[i]]=i;
    };

    // 신고 건(신고자,신고대상) 중복 건 제거 -> 카운트 안함 (set에 담아서 중복제거)
    set<string> s;
    for(auto it : report){
        s.insert(it);
    };

    // 신고 건(신고자,신고대상) 중복 건 제거 -> 카운트 안함 (다시 vector 로 옮겨줌)
    vector<string> str;
    for(auto it : s){
        str.emplace_back(it);
    };

    // 신고 건을 보면서 신고자 : 신고대상 을 map에 담아줌
    // 그리고 신고 건수를 세준다
    for(int i=0;i<str.size();i++){
        istringstream ss(str[i]);
        vector<string> temp;
        string buf = "";
        while(getline(ss,buf,' ')){
            temp.emplace_back(buf);
        };;

        //temp[0] : 신고자
        //temp[1] : 신고대상
        record[temp[0]].rlist.insert(temp[1]); // 신고자:신고대상,신고대상...
        report_count[temp[1]]++; // 신고대상:++
    };



    // 신고대상 카운트 해준거 보면서 k 보다 크거나 같으면 정지 대상값으로 넣어줌
    vector<string> stop;
    map<string,int>::iterator it;
    for(it = report_count.begin();it!=report_count.end();it++){
        if(it!=report_count.end() && it->second >= k){
            stop.emplace_back(it->first);
        }
    };


    // [신고자:신고대상,신고대상..],[신고자:신고대상,신고대상,신고대상..],...] 을 돌면서
    // 정지 대상을 몇명 포함하고 있는지 갯수 카운팅
    int arr_temp[1024]={0,};
    for(p=record.begin();p!=record.end();p++){
        int cnt = 0;
        for(int i=0;i<stop.size();i++){
            auto it = p->second.rlist.find(stop[i]);
            if(it!=p->second.rlist.end()){
                cnt++;
                answer[raw[stop[i]]]+=cnt;
            };
        };
        // 출력은 최초 입력시 순서로 해줘야하기 때문에 아래와 같이
        arr_temp[raw[p->first]]=cnt;
    };

    for(int i=0;i<id_list.size();i++){
        res.emplace_back(arr_temp[i]);
    }

    return res;
};

int main(){

}
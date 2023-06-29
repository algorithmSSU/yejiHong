// retry~retry~retry~retry~retry~retry~retry~retry~retry~retry~retry~retry~retry~
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

map<string, int> call;
map<string, int>::iterator ptr;


// callings 정보: [mumu:2, kai:2] 
void make_call(vector<string> callings){
    for(int i=0;i<callings.size();i++){
        call[callings[i]]++;
    }
}


// 옮겨지는 위치 바로 옆에 원소를같이 데리고 다녀야함
// 옮겨지는 위치에 새로 옮겨진 원소부터 출력하고 기존의 원소를 좌르륵 출력하면 됨 (그 뒤에는 순서 동일)

vector<int> solution(vector<string> players, vector<string> callings)
{
    make_call(callings);
    vector<stack<string> > v[50001];
    vector<string> vs[50001];
    vector<string>::iterator v_ptr;

    for(int i=0;i<players.size();i++){
        //v[i].emplace_back.push(players[i]);
        vs[i].push_back(players[i]);
    };

    for(ptr=call.begin();ptr!=call.end();ptr++){
        v_ptr = find(players.begin(), players.end(),ptr->first);
        if(v_ptr!=players.end()){
            auto n_idx = v_ptr - ptr->second;
            //vs[v_ptr].pop_back();
        }

    }

}

int main(){


}
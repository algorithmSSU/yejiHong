#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solution(queue<int> q);
bool negative(queue<int> q);
bool zero_chek(queue<int> q);
bool abs_check(queue<int> q,int x);
int main(){

    int n;
    vector<int> v;
    queue<int> q;

    cin >> n;

    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    };


    sort(v.begin(), v.end());

    for (int i = 0; i < v.size();i++){
        q.push(v[i]);
    };
};
bool negative(queue<int> q){
    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur<0){
            return true;
        };
    };
    return false;
};

bool zero_check(queue<int> q){
    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur==0){
            return true;
        };
    };
};

bool abs_check(queue<int> q,int x){
    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(abs(cur)==abs(x)){
            return true;
        };
    };
    return false;
};


/*음수 체크, 0 체크, 절대값 체크*/

void solution(queue<int> q){
    int cur;
    if(negative(q)){ // 음수가 있을 때
        if(zero_check(q)){ // 0이 있을 때  
            

        }else if(!zero_check(q)){ // 0이 없을 때

        }


    };
    if(!negative(q)){


    };
}
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int N, M;
set<string> s;
set<string>::iterator iter;
vector<string> v;
int main(){
    cin >> N >> M;
    int count = 0;

    for (int i = 0; i < N;i++){
        string temp;
        cin >> temp;
        s.insert(temp);
    };

    for (int j = 0; j < M;j++){
        string temp;
        cin >> temp;
        iter = s.find(temp);
        if(iter!=s.end()){
            count++;
        }else{
            continue;
        };
    };

    cout << count << endl;
};


/*

c++ stl 만 알고 있으면 해결할 수 있는 간단한 문제
set container에서 find를 사용할 수 있다는 것을 기억하장



*/
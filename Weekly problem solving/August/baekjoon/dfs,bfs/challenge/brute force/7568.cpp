#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    vector<pair<int, int>> v;
    int n;
    int cnt = 1;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    };

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n; j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                cnt++;
            }
        };
        cout << cnt << endl;
        cnt = 1;
    }
}

/*

문제 파악이 제대로 안되서 생각보다 시간이 오래걸림
문제 파악을 제대로 하고 코드 짤 것


몸무게, 키 모두 큰 경우에 +1을 해주는 식으로 접근
-> 자기자신보다 (몸무게, 키) 모두 크지 않으면 초기값 1로 출력




*/
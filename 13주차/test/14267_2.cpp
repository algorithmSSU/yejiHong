#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::pair;
int N, M;
int mem[100000];
int m[100000];
vector<pair<int, int>> info;

void solution(vector<pair<int,int>> info){
    queue<int> q;
    for (int i = 0; i< info.size();i++){
        int first = info[i].first;
        int second = info[i].second;
        m[first] += second;
        for (int j = first; j < N;j++){
            m[j + 1] += second;
        };
    };

    for (int x = 1; x <= N;x++){
        cout << m[x] << " ";
    };
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        int temp;
        cin >> temp;
        mem[i] = temp;
    };

    for (int j = 0; j < M;j++){
        int i, w;
        cin >> i >> w;
        info.emplace_back(i, w);
    };

    solution(info);
};
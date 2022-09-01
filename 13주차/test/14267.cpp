#include <iostream>
#include <vector>

using namespace std;
using std::pair;

int N, M;
int member[100000];
vector<int> m(100000);
vector<pair<int, int>> info;

void solution(vector<pair<int, int>> info){
    for (int i = 0; i < info.size();i++){
        int first = info[i].first;
        int second = info[i].second;
        for (int j = first; j <= N;j++){
            m[j] += second;
        };
    };
    for (int x = 1; x <= N;x++){
        cout << m[x] << " ";
    };
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    //info = new pair[M];

    for (int i = 1;i<=N;i++){
        int temp;
        cin >> temp;
        member[i] = temp;
    };

    for (int j = 0; j < M;j++){
        int i, w;
        cin >> i >> w;
        info.emplace_back(i, w); // 템플릿대로 바로 받을 수 있는 가속기?
    };

    solution(info);
}
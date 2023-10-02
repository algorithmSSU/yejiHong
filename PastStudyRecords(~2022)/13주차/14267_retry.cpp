#include <iostream>
#include <vector>

using namespace std;
using std::pair;

int N,M;
vector<vector<int>> v;
vector<int> praise;
int new_arr[10000] ={0,};


void dfs(int mem);
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;


    // 공간 초기화?
    v.assign(N + 1, vector<int>(0, 0)); // 아 이중벡터니까
    praise.assign(N + 1, 0); // N+1 사이즈만큼, 0으로 초기화

    for (int i = 1; i <= N;i++)
    {
        int temp;
        cin >> temp;
        if(temp!=-1){
            v[temp].emplace_back(i);
        }
    }

    for (int j = 0; j < M;j++){
        int person, credit;
        cin >> person >> credit;
        praise[person] += credit;
    };

    dfs(1);

    for (int i = 1; i <= N;i++){
        cout << praise[i] << " ";
    }
};

void dfs(int mem){
    for (int i = 0; i < v[mem].size();i++){
        int next = v[mem][i];
        praise[next] += praise[mem]; // 부모가 받은 칭찬
        dfs(next);;
    };
};


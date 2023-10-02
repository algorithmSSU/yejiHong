#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using std::pair;

int N, M;
int s[100000];
vector<pair<int, int>> praise;
long long new_arr[100000] ={0,};
queue<int> q;
void dfs(int mem,int reward);
void dfs(int mem, int reward)
{
    
    new_arr[mem] += reward;

    for (int i = 1; i <= N;i++){
        int next = s[i];
        if(next == mem){
            //new_arr[i] += reward;
            q.push(i);
        };
    };
    if(!q.empty()){
        int temp = q.front();
        q.pop();
        //cout << "temp: " << temp << endl;
        dfs(temp, reward);
    }
    
};

int main(){

    cin >> N >> M;

   

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= N;i++){
        int temp;
        cin >> temp;
        s[i] = temp;
    };


    /*칭찬대상과 칭찬정도 입력받기*/
    for (int j = 0; j < M; j++){
        int m, r;
        cin >> m >> r;
        praise.emplace_back(m, r);
    };


    /*칭찬대상과 칭찬정도 입력받은걸로 직원에 적용*/
    for (int i = 0; i < praise.size();i++){
        int mem = praise[i].first;
        int reward = praise[i].second;
        dfs(mem, reward);
    };

    for (int i = 1; i <= N;i++){
        cout << new_arr[i] << " ";
    }
};




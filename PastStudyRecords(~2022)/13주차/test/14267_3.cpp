#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using std::pair;

struct node{
    int parent;
    int data = 0;
};


/*21% 시간초과*/

vector<int> graph[100000];
vector<pair<int, int>> info;
int N, M;
int new_arr[100000];
int visit[100000] = {false};
void solution(vector<pair<int, int>> info){
    queue<int> q;
    for (int i = 0; i < info.size();i++){
        int first = info[i].first;
        int second = info[i].second;
        q.push(first);


        while(!q.empty()){
            int now = q.front();
            q.pop();
            visit[now] = true;
            new_arr[now] += second;
            for (int j = 0; j < graph[now].size();j++){
                int next = graph[now][j];
                if(next!=1 && now<next){
                    q.push(next);
                }else{
                    continue;
                };
            };
        };
    };

    for (int j = 1; j <= N;j++){
        cout << new_arr[j] << " ";
    }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N;i++){
        int temp;
        cin >> temp;
        graph[i].push_back(temp);
        if(temp!=-1){
            graph[temp].push_back(i);
        }else{
            continue;
        }
    };

    for (int j = 0; j < M;j++){
        int i, w;
        cin >> i >> w;
        info.emplace_back(i, w);
    };

    solution(info);
};
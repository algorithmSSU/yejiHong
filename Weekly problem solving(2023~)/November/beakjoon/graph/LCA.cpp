#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
vector<int> v[100001];
int parent[100001][17]; // log2(100000) = 16.61 -> 17
int depth[100001];
int N,M;


// 노드의 깊이를 저장
void dfs(int cur){
    for(int i=0;i<v[cur].size();i++){
        int next = v[cur][i];
        if(depth[next] == -1){
            parent[next][0] = cur; //현재값이 다음 노드의 부모가된다
            depth[next] = depth[cur] + 1;
            dfs(next);
        }
    }
}

// 부모,조상 정보를 저장해준다.
void connect(){
    for(int k=1; k<17; k++){
        for(int cur =1; cur<=N; cur++){
            parent[cur][k] = parent[parent[cur][k-1]][k-1];
        }
    }
}

int LCA(int a, int b){
    // 더 낮은깊이를 가진 노드의 깊이로 맞춰주기
    if(depth[a] < depth[b]){
        int temp = a;
        a= b;
        b= temp;
    }

    // 깊이를 맞추기 위해 얼만큼 차이나는지 체크
    int diff = depth[a] - depth[b];


    // 깊이 맞추기
    for(int i = 0; diff!=0; i++){
        if(diff%2 == 1){
            a = parent[a][i];
        }
        diff /=2;
    }

    // 깊이가 같아졌으니 같은 크기로 뛰자
    if(a!=b){
        for(int i= 16; i>=0; i--){
            if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
                a= parent[a][i];
                b= parent[b][i];
            }            
        }
        a = parent[a][0]; // == parent[b][0]
    }
    return a;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b;
    cin >> N;
    fill(depth,depth+N+1,-1);
    depth[1] = 0; // root 노드

    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    dfs(1); // root node 부터 각 노드의 깊이 찾기
    

    cout << '\n' << endl;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << parent[i][j];
        }
        cout << '\n';
    }
    connect();

    cout << "\n"<< endl;
    for(int i=0;i<15;i++){
        for(int j=0;j<N;j++){
            cout << parent[i][j];
        }
        cout << '\n';
    }
    cout << "=====" << endl;

    cin >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        cout << LCA(a,b) << '\n';
    }




}


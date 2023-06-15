/*문제 이해가 오래걸렸던 문제*/
/*https://mygumi.tistory.com/108*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 50

int N;
int del;
int tree[MAX];

void leafcheck(int del);
void leafcheck(int del){

    queue<int> q;
    q.push(del);

    while(!q.empty()){
        int del = q.front();
        q.pop();
        tree[del] = -2;

        for (int i = 0; i < N;i++){
            int cur = tree[i];
            if(cur==del){
                tree[i] = -2;
                q.push(i);
            };
        };
    };


/*
    for (int i = 0; i < N;i++){
        cout << tree[i] << " ";
    };

    cout << "\n";
*/
    int count = 0;
    for (int i = 0; i < N;i++){
        if(tree[i]!=-2){
            int index = i;
            for (int j = 0; j < N;j++){
                if(tree[j]==index){
                    break;
                }else if(j==N-1 && tree[j]!=index){
                    count++;
                }
            };
        };
    };

    cout << count << endl;
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*노드의 갯수 받고*/
    cin>> N;
    for (int i = 0; i < N;i++){
        int node;
        cin >> node;
        tree[i] = node;
    };
    /*삭제할 노드 번호*/
    cin >> del;

    leafcheck(del);
};

/*


★ 노드정보를 입력 받을 때 인덱스와 value와의 관계가 중요 ★

예를 들어 -1 0 0 1 1 인 경우
index = 0 : -1 (부모가 없는 루트노드)
index = 1 : 0 (부모가 index 0)
index = 2 : 0 (부모가 index 0)
index = 3 : 1 (부모가 index 1)
index = 4 : 1 (부모가 index 1)

솔루션 핵심 -> 삭제하려는 노드가 1일 때 index 1, value가 1 이 같이 제거됨



삭제할 노드 (=del)


while (!q.empty())
q.push(del)

tree[del]= -2 (무시할 플래그)

i=0;i<N;i++
if(tree[i]==del)
    tree[i]=-2 (무시할 플래그)
    q.push(i); // 현재 노드에 연결된 노드가 있을 수 도 있으니 (해당 노드의 index 도 무시해야함)
    

*/
/*문제 이해가 오래걸렸던 문제*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 50

int N;
int tree[MAX];
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>> N;
    for (int i = 0; i < N;i++){
        int node;
        cin >> node;
        tree[i] = node;
    }
};
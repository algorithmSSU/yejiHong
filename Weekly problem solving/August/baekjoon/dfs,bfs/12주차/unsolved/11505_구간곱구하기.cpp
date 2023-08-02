#include <iostream>
#include <vector>
#include <cmath>


using namespace std;
int N, M, K;
vector<int> v;

// 트리 셋팅 -> 재귀 -> return int형
// 트리에서 값을 변경하는 함수

int tree_height(vector<int> arr){
    int size = arr.size();
    int i = 1;
    int ans = 0;
    while(1){
        ans = pow(i,2);
        if(ans >=size){
            return ans;
        };
        i++;
    };
    return ans;
};

int input_tree(int start, int end, int node, vector<int> tree){
    if(start==end){
        return tree[node] = v[start];
    };
    int mid = (start + end) / 2;
    return tree[node] = input_tree(arr, start, mid, node * 2,tree) * input_tree(arr, mid + 1, end, node * 2 + 1,tree);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    };

    int h = tree_height(v);
    vector<int> tree(h);

    input_tree(0, N, 1, tree);

    for (int i = 0; i < tree.size();i++){
        cout << tree[i] << "\n";
    }
};
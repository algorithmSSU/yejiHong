#include <iostream>
#include <vector>
#include <cmath>


/*


세크먼트 트리 개 어렵다
코드 보면서 흐름 이해


*/
#define endl "\n"

using namespace std;
using std::pair;

int N, M;
vector<int> Arr;
vector<int> segment_tree;
vector<pair<int, int>> cmd;

int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
};

/*서브트리를 계속나누는..start가 end일 때 (리프노드)까지*/

int make_segmenttree(int node, int start, int end){
    if(start==end){
        segment_tree[node] = Arr[start];
        return segment_tree[node];
    }

    int mid = (start + end) / 2;
    //왼쪽 나눠주기
    int left_result = make_segmenttree(node * 2, start, mid);
    // 오른쪽 나눠주기
    int right_result = make_segmenttree(node * 2 + 1, mid + 1, end);
    // 각 노드별로 구간의 최솟값?
    segment_tree[node] = min(left_result, right_result);

    return segment_tree[node];
};


int query(int node, int start, int end, int left, int right){
    /*범위에서 완전히 벗어나는 경우*/
    if(right < start || left > end){
        return 2e9; // 2e9 -> int 범위 내에서 무한대 값을 나타내기 위해 사용함.
    };
    /*범위안에 완전히 딱 맞아 떨어지는 경우 / start와 end 가 left right에 딱*/
    if(left <=start && end <= right){
        return segment_tree[node];
    };

    /*위의 두가지 상황 외 애매하게 걸치는 경우(애매하게 포함되는 경우)*/
    int mid = (start + end) / 2;
    int left_result = query(node * 2, start, mid, left, right);
    int right_result = query(node * 2 + 1, mid + 1, end, left, right);
    return min(left_result, right_result);
};

void solution(){
    int tree_height = ceil(log2(N)); // log2(N) -> 반올림해줌
    int tree_size = (1 << (tree_height + 1)); // 비트 단위연산자
    // 0001 -> (4칸이동)100000 : 32

    segment_tree.resize(tree_size); // 32칸으로 재설정

    make_segmenttree(1, 0, N - 1); // 시작 노드 1, 인덱스 0 부터, 끝까지
    for (int i = 0; i < cmd.size();i++){
        int index = cmd[i].first - 1;
        int index2 = cmd[i].second - 1;

        // 파라미터 순서 : 저장할 인덱스, 배열 시작 인덱스, 배열 끝 인덱스
        //
        cout << query(1, 0, N - 1, index, index2) << endl;
    };
};



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        Arr.push_back(a);
    }
    for (int i = 0; i < M;i++){
        int a, b;
        cin >> a >> b;
        cmd.push_back(make_pair(a, b));// a번째 정수부터 b번째 정수까지
    };

    solution();

    return 0;
};
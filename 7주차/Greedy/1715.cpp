#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/*
오름차순 정렬 후 
queue에 넣어준다.
앞에 원소부터 pop() 해서 값들을 더해주고 = temp
temp를 다시 queue에 집어넣는다.
이 작업을 queue에 원소가 아무것도 없을 때 까지만 반복하고,
아무것도 없으면 pop() 시킨 원소들을 더해준 값 temp를 
queue에 집어 넣지 않고, 종료시킨다.

a b c
a+b=d
c+d=f
=> d+f

*/


void cmp(vector<int> arr);
bool comp(int a,int b){
    return a > b;
}

int main(){

    int n;
    vector<int> a;

    cin >> n;

    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    };

    cmp(a);
};

void cmp(vector<int> arr){
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> nv;
    int cur, next, temp;
    int sum = 0;

    //sort(arr.begin(), arr.end(),comp);

    int size = arr.size();

    // queue insert
    for (int i = 0; i < size;i++){
        pq.push(arr[i]);
    };

    // queue research
    while(!pq.empty()){
        while(1){
            if(pq.size()>=2){
                cur = pq.top();
                pq.pop();
                next = pq.top();
                pq.pop();
                temp = cur + next;
                nv.push_back(temp);
            };
            if(pq.size()==0){
                break;
            };
            pq.push(temp);
        };
    };

    for (int i = 0; i < nv.size();i++){
        sum += nv[i];
    };

    cout << sum;
};


/*
따로 정리하기..

key point
- priority queue 사용
1.최초 정렬
2.새로운 연산의 결과도 정렬 시킨 후 계산하기

반례모두 확인했음..하지만 결과는 틀렸습니다임 왜지..
*/
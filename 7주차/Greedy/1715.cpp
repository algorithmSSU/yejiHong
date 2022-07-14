#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    queue<int> q;
    vector<int> nv;
    int cur, next, temp;
    long long sum = 0;

    sort(arr.begin(), arr.end());

    int size = arr.size();

    // queue insert
    for (int i = 0; i < size;i++){
        q.push(arr[i]);
    };

    // 
    while(!q.empty()){
        while(1){
            cur = q.front();
            q.pop();
            next = q.front();
            q.pop();
            temp = cur + next;
            nv.push_back(temp);
            if(q.size()==0){
                break;
            };
            q.push(temp);
        };
    };

    for (int i = 0; i < nv.size();i++){
        sum += nv[i];
    };

    cout << sum;
};


/*

제출 시 오류가 나는데 왜 나는지 이해가 안감



*/
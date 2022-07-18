#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solution(priority_queue<int> q);

int negative(priority_queue<int> q);

/*아직 다 못함..*/


int n;
int main(){
    vector<int> v;
    priority_queue<int> q;

    cin >> n;

    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    };


    sort(v.begin(), v.end());

    for (int i = 0; i < v.size();i++){
        q.push(v[i]);
    };

    solution(q);
};

int negative(priority_queue<int> q){
    int temp;
    int count;
    while(!q.empty()){
        temp = q.top();
        if(temp<0){
            count++;
            q.pop();
        }else{
            q.pop();
        };
    };

    return count;
};



void solution(priority_queue<int> q){
    int count = negative(q);
    int result = 0;
    if(count%2==0){//음수가 짝수 일 때.
        for (int i = 0;i<n/2;i++){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            result += a * b;
        };
    };

    if(count%2!=0){ //음수가 홀수 일 때.
        
    };
    cout << result << endl;
};
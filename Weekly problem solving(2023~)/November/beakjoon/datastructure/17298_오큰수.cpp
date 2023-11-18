#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int ori[1000009];
int answer[1000009];
int n;
int main(){
    cin >> n;
    stack<int> s;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        ori[i]=num;
        if(s.empty()){
            s.push(i);
        }else if(!s.empty()){
            while(!s.empty() && ori[s.top()]<num){
                answer[s.top()] = num;
                s.pop();
            }
            s.push(i);// 현재 인덱스를 넣는다.
        }
    }
    while(!s.empty()){
        answer[s.top()] = -1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout << answer[i] << " ";
    }
    cout << '\n';
    
}
#include <iostream>
#include <stack>

using namespace std;

int main(){

    int n;
    cin >> n;


    stack<int> s;

    while(n--){
        int temp;
        cin >> temp;
        s.push(temp);
    };

    int top = s.top();
    int cnt = 1;
    s.pop();
    while(!s.empty()){
        if(top<s.top()){
            cnt++;
            top=s.top();
        }
        s.pop();
    }

    cout << cnt << '\n';
}
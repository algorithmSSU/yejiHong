#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){


    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    stack<int> s;
    cin >> n;

    while(n--){
        int tmp;
        cin >> tmp;
        s.push(tmp);
    };

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    };
    cout << endl;

}
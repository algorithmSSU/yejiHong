#include <iostream>
#include <queue>

using namespace std;

int cardplay(int n);

int cardplay(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    };

    while(q.size()!=1){
        q.pop();
        int bottom = q.front();
        q.pop();
        q.push(bottom);
    };

    return q.front();
}

int main(){
    int num, last;
    cin >> num;
    last = cardplay(num);
    cout << last << endl;

    return 0;
}
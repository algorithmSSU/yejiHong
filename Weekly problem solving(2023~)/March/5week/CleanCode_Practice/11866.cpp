#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void josep(int n,int k){
    queue<int> q;
    queue<int> sq;
    vector<int> v;
    for(int i=1;i<=n;i++){
        q.push(i);
    };

// mainq 에서 뺀거를 바로 subq에 주고, subq는또 바로 mainq에 주고 => circle queue
    while(v.size()!=n){
        for(int i=0;i<k-1;i++){
            sq.push(q.front());
            q.pop();
            q.push(sq.front());
            sq.pop();
        };
        v.push_back(q.front());
        q.pop();
    };
    cout << "<";
    for(int i=0;i<v.size();i++){
        cout << v[i];
        if (i < v.size() - 1)
        {
            cout << ", ";
        }
    };
    cout << ">" << endl;
}



int main(){
    int n,k;
    cin >> n >> k;
    josep(n,k);
    return 0;
}
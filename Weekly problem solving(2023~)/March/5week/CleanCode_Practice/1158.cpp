#include <iostream>
#include <queue>

using namespace std;

void Josephus(int n, int k)
{
    queue<int> q;
    
    vector<int> ans;

    // fill queue
    for(int i=1;i<=n;i++){
        q.push(i);
    };

    // circle queue
    while(ans.size()!=n){
        queue<int> tq;
        for(int i=0;i<k;i++){
            if(i<k-1){
                tq.push(q.front());
                q.pop();
            }else{
                ans.push_back(q.front());
                q.pop();
            };

            while(!tq.empty()){
                q.push(tq.front());
                tq.pop();
            }
        };
    };

    // print
    cout << "<";
    for(int i=0;i<ans.size();i++){
        if(i<ans.size()-1){
            cout << ans[i] << ", ";
        }else{
            cout << ans[i] << ">" << endl;
        }
    }
};

int main(){
    int n, k;
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    Josephus(n, k);
}
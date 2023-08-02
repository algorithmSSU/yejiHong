#include <iostream>
using namespace std;

int main(){
    int num[100001];
    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> num[i];
    };

    // two pointer
    int startidx = 0;
    int endidx = 0;
    int sum = 0;
    int cnt = 0;

    while(endidx<=n){
        if(sum<m){
            sum+=num[endidx];
            endidx++;

        };
        if(sum>=m){
            if(sum==m){
                cnt++;
            }
            sum-=num[startidx];
            startidx++;
        }
    }

    cout << cnt << '\n';


}
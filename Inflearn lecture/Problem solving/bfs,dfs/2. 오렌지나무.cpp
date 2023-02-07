// 아직아직 다시다시

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int col,row,orange,h;

    int res = INT_MIN;

    vector<int> x,y;
    for(int i=0;i<orange;i++){
        int a,b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    for(int i=0;i<orange;i++){
        for(int j=0; j<orange;j++){
            int cnt =0;
            for(int k=0;k<orange;k++){
                if(x[k]>=x[i]&&x[k]<=x[i]+h){
                    if(y[k]>=y[j]&&y[k]<=y[j]+h){
                        cnt++;
                    }
                }      
            }
            res = max(res,cnt);
        }
    }

    cout << res << endl;
    return 0;
}
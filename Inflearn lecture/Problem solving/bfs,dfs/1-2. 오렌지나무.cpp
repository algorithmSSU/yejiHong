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
    for(int i=0;i<orange;i++){ // 주어진 해당 x 축을 기준으로 모든 y축을 탐색
        for(int j=0; j<orange;j++){ 
            int cnt =0;
            for(int k=0;k<orange;k++){ // 오렌지 나무 정점을 기준 +h 까지 유효한가?
                if(x[k]>=x[i]&&x[k]<=x[i]+h){
                    if(y[k]>=y[j]&&y[k]<=y[j]+h){
                        cnt++; // y축, x축 모두 유효하면 오렌지 나무가 있다는 거
                               // 처음부터 오렌지 나무가 있는 축들만을 기준으로 돌고있음 -> 그 안에서 오렌지 나무 위치를 기준으로 탐색
                               // 전체 map을 따로 만들지 않고, 전체를 대상으로 돌지 않아도 된다.
                    }
                }      
            }
            res = max(res,cnt);
        }
    }

    cout << res << endl;
    return 0;
}
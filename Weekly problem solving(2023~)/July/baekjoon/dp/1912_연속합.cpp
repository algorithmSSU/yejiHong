#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    int arr[100001]={0,};
    int layer_sum[100001]={0,};
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    };

    int max=0;

    for(int i=1;i<=n;i++){
        if(layer_sum[i-1]+arr[i]<=arr[i]){
            layer_sum[i]=arr[i];
        }else if(layer_sum[i-1]+arr[i]>=arr[i]){
            layer_sum[i]=layer_sum[i-1]+arr[i];
        }
    }

    int ans=-1e9;
    for(int i=1;i<=n;i++){
        ans = layer_sum[i] > ans ? layer_sum[i] : ans;
    }

    cout << ans << '\n';

    return 0;

}
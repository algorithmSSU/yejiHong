#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;


int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int*arr;
    int n;
    int ans[1000][1000];
    cin >> n;

    arr= new int[n];

    for(int i=0;i<n;i++){

        cin >> arr[i];
    };

    for(int j=0;j<n;j++){
        int start =j;
        for(int k=0;k<n;k++){
            int idx = j+k;
            if(idx<=n-1){
                ans[j][k] = arr[idx];
            }else{
                ans[j][k]=arr[idx-n];
            }

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    
    


}
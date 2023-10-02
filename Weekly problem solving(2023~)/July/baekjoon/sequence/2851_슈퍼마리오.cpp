#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main(){
    int arr[11]={0,};
    for(int i=1;i<=10;i++){
        cin >> arr[i];
    };

    int sum[11]={0,};
    int pick = 1e9;
    int find = 0;
    for(int i=1;i<=10;i++){
        sum[i]=sum[i-1]+arr[i];

        int temp = abs(100 - sum[i]);
        if(pick>=temp){
            pick = temp;
            find = sum[i];
        }
    };

    cout << find << '\n';

}

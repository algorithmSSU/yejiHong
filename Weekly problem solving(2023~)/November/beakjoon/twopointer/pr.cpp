#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N;
int arr[100001];
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);

    int left = 0;
    int right = N-1;
    //int minn = 200000001;
    int minn = 2000000001;

    int finalLeft;
    int finalRight;

    while(left<right){
        int sum = arr[left] + arr[right];
        if(abs(sum) < minn){
            minn = abs(sum);
            finalLeft = arr[left];
            finalRight = arr[right];
        }
        if(sum>0){
            right--;
        }else{
            left--;
        }
    }

    cout << finalLeft << " " << finalRight << endl;


    return 0;
}
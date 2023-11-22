#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[100001];
int sum[100001]={0,};
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);


    int MaxV = 2000000001;
    int left = 0;
    int right = n-1;


    int finalL,finalR;
    int sum = 0;
    while(left<right){
        sum = arr[left] + arr[right];
        if(abs(sum)<MaxV){
            MaxV = abs(sum);
            finalL = arr[left];
            finalR = arr[right];
        }
        if(sum>0){
            right--;
        }else{
            left++;
        }
    }

    cout << finalL << " " << finalR << endl;
    return 0;
}
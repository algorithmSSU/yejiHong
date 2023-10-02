#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 왼쪽값과 계속 비교후 저장 -> O(n^2)
// 퀵 정렬로 다시
void s(int *arr,int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int *arr;
    int n;
    arr = new int[n];
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr[i]=(temp);
    }

    for(int i=1;i<n;i++){
        int j=i-1;
        while(j>=0){
            if(arr[i]<arr[j]){
                s(arr,i,j);
                i=j;
            };
            j--;
        };
        
        if (arr[i] < arr[j])
        {
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
        
    };

    print(arr,n);
}
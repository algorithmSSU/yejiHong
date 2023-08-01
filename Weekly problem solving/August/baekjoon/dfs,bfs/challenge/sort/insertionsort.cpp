
/*알고리즘 1week 옮기기*/


#include <iostream>
#include <vector>
using namespace std;

void insertion(int arr[],int size);
int main(){

    int arr [8]= {4, 7, 3, 1, 2, 9, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    insertion(arr,size);

    // 배열크기: cout << sizeof(arr) / sizeof(int) << endl;

    for (int i = 0; i < size;i++){
        cout << arr[i] << " ";
    };
};

void insertion(int arr[],int size){
    for (int i = 1; i < size;i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j]>temp){
            arr[j + 1] = arr[j];
            j--;
        };
        arr[j+1] = temp;
    };
}
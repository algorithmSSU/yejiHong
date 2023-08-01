#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int *num_arr;

void bubblesort(int a[], int size);
void swap(int a[], int idx, int idx2);
int main(){
    string number;
    

    cin >> number;
    int len = number.length();
    int *num_arr = new int[len];

    for (int i = 0; i < number.length();i++){
        num_arr[i] = number[i] - '0';
    };

    bubblesort(num_arr, len);

    for (int i = 0; i < len;i++){
        cout << num_arr[i];
    }
};

void swap(int a[], int idx1, int idx2)
{
    char temp;
    temp = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = temp;
};

void bubblesort(int a[], int size)
{
    for (int i = 0; i < size;i++){
        for (int j = 0; j < size - 1;j++){
            if(a[j]<a[j+1]){
                swap(a, j, j + 1);
            }
        }
    }
}

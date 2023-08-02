#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    priority_queue<int,vector<int>,greater<int> > q;
    string text;
    string *arr;
    
    cin >> text;
    int size = text.length();
    arr = new string[size];
    char * ptr = &text[0];

    for (int i = 0; i < text.length(); i++)
    {
        arr[i] = ptr+i;
    };

    // sort 함수 이용시 배열정렬
    // 배열명, 배열+배열크기
    sort(arr,arr+size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
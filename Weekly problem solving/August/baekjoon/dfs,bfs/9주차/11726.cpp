#include <iostream>


/* 2*n 타일링 */
using namespace std;
int arr[1001];
int main(){

    int sum;

    int n;
    cin >> n;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3;i<=n;i++){
        arr[i] = (arr[i - 1] + arr[i - 2])%10007;
    };
    
    
    cout << arr[n] % 10007 << endl;
};



/*

dp는 규칙을 찾는게 중요!!

가로로 눕혀놓으면 2
세로로 세워놓으면 1

1: 1
2: 2 (세로로두개, 가로로 두개)
3: 3 (세로로세개, (가로로 두개+세로로한개)*2 )
4: 5 (세로로네개, 가로로네개,
      옆으로가로두개세로두개, 옆으로세로두개가로두개
      쌓기가로두개새로두개)

*/
#include <iostream>
#include <string.h>

using namespace std;


int main(){
    int n;
    cin >>n;

    for(int i=0;i<n;i++){ // 세로줄
        for(int j=0;j<n-i-1;j++){ // 공백
            cout << " ";
        };
        for(int j=0;j<2*i+1;j++){ // 별
            cout << "*";
        }
        cout << '\n';// 줄 바꿔주고
    }
    return 0;

}
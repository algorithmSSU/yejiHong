#include <iostream>

using namespace std;


int fiboData[100]={0,};
int fibo(int n);
int main(){

    cout << fibo(11) << endl;
};


int fibo(int n){
    if(n<=2){
        return 1;
    };
    if(fiboData[n]==0){ // 해당 인덱스에 연산 값이 없으면 새로 연산해서 저장
        fiboData[n] = fibo(n - 1) + fibo(n - 2);
    };
    return fiboData[n];
};


// 일반적인 재귀와는 다르게 중복되는 연산이 사라진다.

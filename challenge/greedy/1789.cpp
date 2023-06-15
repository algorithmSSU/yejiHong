#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long n;
    cin >> n;
    long long temp = 0;
    long long i = 0;
    for (i;;i++){
        temp += i;
        if(n<temp){
            cout << i-1 << endl;
            break;
        };
    };
};
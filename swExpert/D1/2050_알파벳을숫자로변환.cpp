#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    for(auto it : str){
        int num = it - '0';
        cout << num-16 << " ";
    }
}
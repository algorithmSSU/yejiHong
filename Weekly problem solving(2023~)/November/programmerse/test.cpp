#include <iostream>
#include <string>
using namespace std;

int main(){

    string str = "ABCDEFGHIJK";

    str.erase(2,4); // 2번쨰 인덱스부터 4개
    cout << str << endl;
}
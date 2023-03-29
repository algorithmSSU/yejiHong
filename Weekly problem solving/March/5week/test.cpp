#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void input(){
    string text;
    while (getline(cin, text))
    {
        cout << text << endl;
    };
};

int main(){
    input();
    return 0;
};
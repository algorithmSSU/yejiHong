#include <iostream>
#include <string>

using namespace std;

int main(){

    string text;

    cin >> text;

    for (int i = 0; i < text.length();i++){
        if(i!=0 && i%10==0){
            cout << "\n";
        };
        cout << text[i];
    };
};


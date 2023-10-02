#include <iostream>
#include <string.h>

using namespace std;

int main(){

    string input;
    cin >> input;
    int count =1;
    for(int i=0;i<input.length();i++){
        if(input[i]==','){
            count++;
        };
    };

    cout << count << endl;
}
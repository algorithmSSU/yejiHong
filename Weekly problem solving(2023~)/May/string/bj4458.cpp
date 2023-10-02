#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    cin.ignore();

    vector<string> v;
    for(int i=0;i<n;i++){
        string input;
        getline(cin, input);
        input[0] >= 97 ? input[0] -= 32 : input[0];
        cout << input << '\n';
    };
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> str;
int main(){

    string text;

    while(text!="."){
        getline(cin, text);
        
        str.push_back(text);
    };

    for (int i = 0; i < str.size();i++){
        cout << str[i] << endl;
    }
};
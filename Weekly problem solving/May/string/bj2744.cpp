#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    string input="";
    vector<char> v;
    cin >> input;

    for(int i=0;i<input.length();i++){
        char itoc;
        // a=97, A=65
        if(input[i]<'a'){
            itoc = (input[i] + 32);
            v.push_back(itoc);
        }else if(input[i]>='a'){
            itoc = (input[i] - 32);
            v.push_back(itoc);
        }
    };

    for(int i=0;i<v.size();i++){
        cout << v[i];
    };
    cout << endl;

    return 0;
}
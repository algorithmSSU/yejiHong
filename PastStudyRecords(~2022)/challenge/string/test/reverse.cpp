#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    string text;
    cin >> text;
    vector<int> v;

    for (int i = 0; i < text.length();i++){
        char temp;
        int tonum;

        tonum = text[i] - '0';
        v.push_back(tonum);
    };

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size();i++){
        cout << v[i];
    };
    cout << "\n";
};
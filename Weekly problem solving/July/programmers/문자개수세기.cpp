#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    map<char,int> words;
    map<char,int>::iterator p;
    char a;
    for(int i=65;i<=90;i++){
        words[i] = 0;
    };

    for(int i=97;i<=122;i++){
        words[i] = 0;
    };

    string my_string = "Programmers";

    for(int i=0;i<my_string.length();i++){
        words[my_string[i]]++;
    };
    for(p = words.begin();p!=words.end();p++){
        cout << p->second << " ";
    }
}
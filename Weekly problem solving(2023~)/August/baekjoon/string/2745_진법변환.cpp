#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    unsigned long long int answer = 0;

    string str;
    int number;
    cin >> str >> number;

    map<char,int> dict;
    map<char,int>::iterator p;

    //dict 생성
    int start = 97;
    for(int i=10;i<36;i++){
        dict[start]=i;
        start++;
    };


    for(int i=0;i<str.length();i++){
        answer+= (unsigned long long int)dict[str[i]]*(pow(number,i));
    };

    cout << answer << '\n';


    



}
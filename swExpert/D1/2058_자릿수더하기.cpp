#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    string number;
    cin >> number;

    int answer = 0;

    for(auto it : number){
        answer += it-'0';
    }


    cout << answer << endl;

}
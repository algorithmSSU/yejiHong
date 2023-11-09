#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        char target = s[s.length()-1];
        int num = target -'0';

        if(num%2 == 0){
            cout << "even" << endl;
        }else{
            cout << "odd" << endl;
        }
    }
}
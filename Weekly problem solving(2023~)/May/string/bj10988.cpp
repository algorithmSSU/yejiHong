#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int check(string s){
    int idx =0;
    for(int i=s.length()-1;i>0;i--){
        if(s[i]==s[idx]){
            if(idx<s.length()){
                idx++;
            }
        }else{
            return idx;
        }
    };
    return idx;
}


int main(){
    string s;
    int idx;
    cin >> s;

    idx = check(s);

    if(idx>=s.length()/2){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }

}
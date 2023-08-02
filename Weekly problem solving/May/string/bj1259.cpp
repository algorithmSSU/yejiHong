#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int check(string s){
    int idx= 0;
    for(int i=s.length()-1;i>0;i--){
        if(s[idx]==s[i]){
            idx++;
        }else{
            return idx;
        }
    }
    return idx;
}


int main(){

    string s;
    vector<string> v;
    do{
        int val;
        cin >> s;
        if(s=="0"){
            break;
        }
        val = check(s);
        if(val>=s.length()/2){
            v.push_back("yes");
        }else{
            v.push_back("no");
        };
    }while(s!="0");

    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }

}
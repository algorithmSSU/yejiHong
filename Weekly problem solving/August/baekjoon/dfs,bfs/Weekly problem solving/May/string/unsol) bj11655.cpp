#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string input, ans;
    cin >> input;
    vector<char> v;
    
    for(int i=0;i<input.length();i++){
        int t;
        char c;
        t = input[i]-'0';
        if(65<=t || t<=77){
            t+=13;
            c = t+'0';
            cout << c;
        }else if(t>77 || t<97){
            t+=13+6;
            c = t-'0';
            cout<< c;
        }else{
            cout << t << endl;
        }
        
    }
    int z = 'O';
    cout << z << endl;

}
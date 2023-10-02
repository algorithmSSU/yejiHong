#include <iostream>
#include <vector>
using namespace std;

int main(){
    

    string input;
    cin >> input;

    vector<string> v;
    
    for(int i=0;i<input.length();i++){
        if(input[i]=='0'){
            v.push_back("000");
        }
        if(input[i]=='1'){
            if(i==0){
                v.emplace_back("1");
            }else{
                v.emplace_back("001");
            }
        }else if(input[i]=='2'){
            if(i==0){
                v.emplace_back("10");
            }else{
                v.emplace_back("010");
            }
        }else if(input[i]=='3'){
            if(i==0){
                v.emplace_back("11");
            }else{
                v.emplace_back("011");
            }
        }else if(input[i]=='4'){
            v.push_back("100");
        }else if(input[i]=='5'){
            v.push_back("101");
        }else if(input[i]=='6'){
            v.push_back("110");
        }else if(input[i]=='7'){
            v.push_back("111");
        }
    };


    for(int i=0;i<v.size();i++){
        cout << v[i];
    }
    cout <<'\n';



};
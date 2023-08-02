#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int n;
    string p;
    vector<string> ans;
    char first, second;
    cin >> n;
    cin >> p;
    

    first = p[0];
    second = p[2];


    int flag =0;
    for(int i=0;i<n;i++){
        string input;
        int a =0;
        int b= 0;
        cin >> input;

        if(input.find(first)==string::npos || input.find(second)==string::npos){
            ans.emplace_back("NE");
        }else{
            a = input.find(first);
            b = input.find(second);
            if(a<b){
            ans.emplace_back("DA");
            }else{
            ans.emplace_back("NE");
            }
        };

        
    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}
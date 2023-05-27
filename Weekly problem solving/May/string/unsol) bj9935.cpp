#include <iostream>
#include <string.h>
#include <queue>
#include <set>
#include <stack>
using namespace std;



// 홍예지 이해 안가지?
// 무조건 씹어먹고간다 이해해라



int main()
{
    string input, bomb;
    string text;

    cin >> input;
    cin >> bomb;

    for(int i=0;i<input.length();i++){
        text+=input[i];
        if(text.length()>=bomb.length()){
            bool flag = true;
            for(int j=0;j<bomb.length();j++){
                if(text[text.length()-bomb.length()+j]!=bomb[j]){
                    flag=false;
                    break;
                };
            };
            if(flag){
                text.erase(text.end()-bomb.length(),text.end());
            };
        };
    };

    if(text.length()==0){
        cout << "FARLU" << endl;
    }else{
        cout << text << endl;
    }


    
    return 0;
}

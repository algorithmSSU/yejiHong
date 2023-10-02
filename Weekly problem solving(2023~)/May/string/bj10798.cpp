#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string text;
    char arr[6][15]={0,}; // 혹시 모르니 초기화는 꼭..
    vector<string> v;

    int maxsize= 0;
    for(int i=0;i<5;i++){
        string str;
        cin >> str;
        maxsize = maxsize<str.length()?str.length():maxsize;
        for(int j=0;j<str.length();j++){
            arr[i][j]=str[j];
        };
    };


    for(int i=0;i<maxsize;i++){
        string tmp;
        for(int j=0;j<5;j++){
            if(arr[j][i]!=0){
                tmp += arr[j][i];
            }
        }
        v.emplace_back(tmp);
    };
    for(int i=0;i<v.size();i++){
        text+=v[i];
    };

    cout << text << endl;

    
}
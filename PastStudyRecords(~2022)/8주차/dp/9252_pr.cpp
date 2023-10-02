#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str1, str2;

int main(){

    int lcs[51][51];

    string st1, st2;
    cin >> st1;
    cin >> st2;

    str1 = "0" + st1;
    str2 = "0" + st2;

    int len1 = str1.length();
    int len2 = str2.length();

    for (int i = 0; i < len1;i++){
        for (int j = 0; j < len2;j++){
            if(i==0 || j==0){
                lcs[i][j] = 0;
                continue;
            };
            if(str1[i]==str2[j]){
                lcs[i][j] = lcs[i - 1][j-1]+1;
            }else{
                if(lcs[i-1][j]<lcs[i][j-1]){
                    lcs[i][j] = lcs[i][j - 1];
                }else{
                    lcs[i][j] = lcs[i - 1][j];
                };
            };
        };
    };

    int i = len1 - 1;
    int j = len2 - 1;

    stack<int> st;
    while(lcs[i][j]!=0){
        if(lcs[i][j]==lcs[i-1][j]){
            i--;
        }else if(lcs[i][j]==lcs[i][j-1]){
            j--;
        }else if(lcs[i][j]-1==lcs[i-1][j-1]){
            st.push(i);
            i--;
            j--;
            
        };
    };

    // 길이 출력
    cout << lcs[len1 - 1][len2 - 1] << endl;

    // 단어 출력
    while(!st.empty()){
        cout << str1[st.top()];
        st.pop();
    };
};
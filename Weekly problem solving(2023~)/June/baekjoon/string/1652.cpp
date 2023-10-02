#include <iostream>
#include <string.h>

using namespace std;

int main(){

    char map[101][101];

    int n;
    int row=0;
    int col=0;
    cin >> n;

    string input;
    for(int i=0;i<n;i++){
        cin >> input;
        int cnt=0;
        bool flag= true;
        for(int j=0;j<input.length();j++){
            map[i][j]=input[j];
            if(input[j]=='.'){
                cnt++;
            }else if(input[j]=='X'){
                flag = false;
                if(cnt>=2){
                    row+=2;
                }
                cnt=0;
            };
        };
        if(flag){
            row+=1;
        }
    };

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(map[j][i]=='.'){
                cnt++;
            }else if(map[j][i]=='X'){
                cnt = 0;
            }
            if(cnt>=2){
                break;
            }
        };
        if(cnt>=2){
            col++;
        }
    };
    cout << row << " " << col << endl;

}
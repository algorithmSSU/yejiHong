#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int box[7][7];
string nbox[3][3];
void init(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            box[i][j] = 0;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            nbox[i][j] = "";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        int n;
        init();
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> box[i][j];
            }
        }
        for(int i=0;i<n;i++){
            string str;
            for(int j=n-1;j>=0;j--){
                str+=box[j][i]+'0';
            }
            nbox[i][0] = str;
        }
        int idx = 0;
        for(int i=n-1;i>=0;i--){
            string str;
            for(int j=n-1;j>=0;j--){
                str+=box[i][j]+'0';
            }
            nbox[idx++][1] = str;
        }
        idx = n-1;
        for(int i=0;i<n;i++){
            string str;
            for(int j=0;j<n;j++){
                str+=box[j][i]+'0';
            }
            nbox[idx--][2] = str;
        }
        cout << "#" << t << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cout << nbox[i][j] << " ";
            }
            cout << '\n';
        }
        
    }
}
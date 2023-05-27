#include <iostream>
#include <string.h>



// 공백을 없애야 한다고? 하 다시 생각해보자
using namespace std;
char map[200][200]={0,};
int n=0;
void tl(int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=n-i-1;j--){
            map[i][j]='*';
            //0,4 1,4 1,3
        };
    };
};

void tr(int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j<n+i;j++){
            map[i][j]='*';
        };
    };
};

void br(int n){
    int k=0;
    for(int i=n-1;i<n*2-1;i++){
        for(int j=n-1;j<2*n-1-k;j++){
            map[i][j]='*';
        };
        k++;
    }

};
void bl(int n){
    int k = 0;
    for(int i=n-1;i<n*2-1;i++){ // 5 6 7
        for(int j=n-1;j>=k;j--){
            map[i][j]='*';
        };
        k++;
    }

};

void print(char arr[][200],int col,int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==0){
                cout << " ";
            }
            cout << arr[i][j];
        };
        cout << '\n';
    }
}
int main(){

    cin >> n;

    int check = 2*n-1;

    tl(n);
    tr(n);
    br(n);
    bl(n);
    print(map, check, check);
}
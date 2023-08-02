#include <iostream>
#include <vector>

using namespace std;
int A[51][51]={0};
int B[51][51]={0,};

int main(){
    
    int r,c;
    cin >> r >> c;


    // A
    for(int i=0;i<r;i++){
        string str;
        cin >> str;
        for(int c=0;c<str.length();c++){
            A[i][c] = str[c];
        };
    }
    // B
    for(int i=0;i<r;i++){
        string str;
        cin >> str;
        for(int c=0;c<str.length();c++){
            B[i][c] = str[c];
        };
    }



    int iterrow = r - 3 + 1;
    int itercol = c - 3 + 1;

    int sy= 0;
    int sx= 0;

    while(sy<=iterrow && sx<=itercol){
        for(int i=sy;i<r;i++){
            for(int j=sx;j<c;j++){
                if(A[i][j]%2==B[i][j]%2){
                    
                }
            }
        }        
    }

    


    

}
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

/*

이어져 있지 않고, 띄엄띄엄있더라도 
⭐️문자 등장 순서는 같아야 함⭐️

*/

#define SIZE 100
int lcs[SIZE][SIZE];

int solution(string text,string pat){
    int t = text.length();
    int p = pat.length();

    for(int i=0;i<t;i++){
        for(int j=0;j<p;j++){
            if(i==0 || j==0){
                lcs[i][j] = 0;
            }else if(text[i]==pat[j]){
                // 대각선 위 + 1
                lcs[i][j] = lcs[i-1][j-1]+1;
            }else{
                // max(바로왼쪽,바로위)
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }

    int maxsame = -1e9;
    for(int i=0;i<t;i++){
        for(int j=0;j<p;j++){
            maxsame = max(maxsame,lcs[i][j]);
        }
    }

    return maxsame;
}
int main(){
    string text;
    string pat;
    int answer = 0;

    cin >> text;
    cin >> pat;

    answer = solution(text,pat);
    cout << answer << endl;

    



}
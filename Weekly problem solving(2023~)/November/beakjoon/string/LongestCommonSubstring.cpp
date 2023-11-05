#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


/*

이어져있어야함, 패턴과 동일하게 
⭐️문자 등장 순서는 같아야 함⭐️

*/

#define SIZE 100
int lcs[SIZE][SIZE];

int solution(string text, string pat){
    int p = pat.length();
    int t = text.length();

    for(int i=0;i<p;i++){
        for(int j=0;j<t;j++){
            if(i == 0 || j == 0){
                lcs[i][j]=0;
            }else if(pat[i] == text[j]){
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
        }
    }
    
    int maxsame = -1e9;
    for(int i=0;i<p;i++){
        for(int j=0;j<t;j++){
            maxsame = max(lcs[i][j], maxsame);
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1001
int LCS[MAX][MAX]={0,};

int solution(string A, string B){
    
    // padding 부분
    string a = " " + A;
    string b = " " + B;

    int A_len = a.length();
    int B_len = b.length();

    

    int maxSameLen = -1e9;
    for(int i=0;i<A_len;i++){
        for(int j=0;j<B_len;j++){
            if(i == 0 || j == 0){
                LCS[i][j]=0; // padding
            }else if(a[i] == b[j]){
                LCS[i][j] = LCS[i-1][j-1]+1;
            }else{
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
            maxSameLen = max(maxSameLen,LCS[i][j]);
        }
    }

    return LCS[A_len-1][B_len-1];
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string A;
    string B;

    cin >> A >> B;


    int answer=  solution(A,B);
    cout << answer << endl;


}
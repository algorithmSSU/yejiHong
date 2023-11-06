#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 컴파일에러 ??


#define MAX 1000001
int LCS[MAX][MAX];

int endIdx = 0;

int solution(string text, string pat){

    int ts = text.length();
    int ps = pat.length();

    int ps_ = pat.length() - 1;

    for(int i=0; i<ts; i++){
        for(int j=0; j<ps; j++){
            if(i==0 || j==0){
                LCS[i][j] = 0;
            }else if(text[i]==pat[j]){
                LCS[i][j] = LCS[i-1][j-1]+1;
                if(LCS[i][j] == ps_){
                    endIdx = i;
                    //cout << "endIdx" << i << endl;
                }
            }
        }
    }

    int maxcnt = -1e9;
    for(int i=0; i<ts; i++){
        for(int j=0;j<ps; j++){
            maxcnt = max(maxcnt, LCS[i][j]);
        }
    }

    return maxcnt;

    
}

int main(){
    string T;
    string P;
    getline(cin,T);
    cin.ignore();// buffer 비워주기

    cin >> P;


    int P_s = P.length() - 1;
    int cnt = 0;
    int start_idx = 0;

    

    cnt = solution(T,P);
    cnt = cnt / P_s;
    
    start_idx = endIdx - P_s; //패턴 문자열 길이 - 원본에서 패턴길이만큼 맞았을 떄 인덱스

    cout << cnt << '\n' << start_idx << endl;






}
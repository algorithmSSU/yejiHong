#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str1, str2;
int lcs[1001][1001];

int main(){
    string tmp1, tmp2;

    cin >> tmp1;
    cin >> tmp2;
    // LCS 알고리즘을 위해 앞에 '0'을 붙여준다.
    str1 = "0" + tmp1;
    str2 = "0" + tmp2;

    int len1 = str1.length();
    int len2 = str2.length();

    for (int i = 0; i < len1;i++){
        for (int j = 0; j < len2; j++){
            if(i==0 || j==0){
                lcs[i][j] = 0;
                continue;
            }
            // 현재 비교하는 값이 서로 같다면, LCS는 +1
            // 즉, 현재 위치에서 뒤로가서 위로간 값 + 1
            // 초기에는 0으로 되어 있을 테니 1 이 저장
            if(str1[i]==str2[j]){
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }else{ // 서로 다르다면 LCS 값을 왼쪽 혹은 위에서 가져온다. 
                // 왼쪽, 위 중 더 큰 값으로
                if(lcs[i-1][j]>lcs[i][j-1]){
                    lcs[i][j] = lcs[i - 1][j];
                }else{
                    lcs[i][j] = lcs[i][j - 1];
                };
            };
        };
    };

    int i = len1 - 1;
    int j = len2 - 1;
    stack<int> st; // 거꾸로 담기는 것을 활용

    while(lcs[i][j]!=0){
        // 테이블이 같은 넘버링이라면

        // 왼쪽 값과 같다면 왼쪽으로
        if(lcs[i][j]==lcs[i][j-1]){
            j--;
        }else if(lcs[i][j] == lcs[i-1][j]){
        // 위 값과 같다면 위쪽으로
            i--;
        }else if(lcs[i][j]-1==lcs[i-1][j-1]){
        // 왼쪽, 위쪽 모두 다른 넘버링이라면 대각선 방향으로 이동
            st.push(i); // 최대 4개 까지 시퀀스가 있다면 담기는 순서 : 
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
    return 0;
};

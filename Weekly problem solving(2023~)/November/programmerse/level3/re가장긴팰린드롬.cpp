#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int solution(string s){
    

    int answer = 0;


    int len = s.length();

    for(int i=0;i<len;i++){
        int left = i-1;
        int right = i+1;
        bool flagA = false;
        bool flagB = false;
        int count_1 = 0;
        int count_2 = 1;
        while(left >=0 && right<len){

            if(s[left] == s[right-1]){
               count_1+=2;
            }else{
                flagA = true;
            }
            if(s[left--] == s[right++]){
                count_2+=2;
            }else{
                flagB = true;
            }

            if(flagA && flagB){
                //짝수 비교법 홀수 비교법해도 모두 틀림
                break;
            }
        }
        int result = (count_1 > count_2) ? count_1 : count_2;
        answer = result>answer ? result : answer;
    }
    return answer;
    
}


int main(){
    string str = "abcdcba";
    
    int ans = solution(str);
    cout << ans << endl;
}
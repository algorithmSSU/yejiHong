#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
int solution(string s){
    int answer = 1;
    s.push_back(1); // 문자열 맨 뒤에 1을 ?

    for(int i=1;i<s.size();i++){
        int left = i - 1;
        int right = i + 1;
        int count_1 = 0;
        int count_2 = 1;

        bool f1 = false;
        bool f2 = false;

        while(left >= 0 && right<s.size()){
        // left 가 0보다 크고 , right가 글자크기보다 작을 때
            if(s[left] == s[right-1]){
                count_1+=2;
            }else{
                f1 = true;
            }
            if(s[left--] == s[right++]){
                count_2+=2;
            }else{
                f2 = true;
            }
            if(f1 && f2){
                break;
            }
        }
        int result = (count_1>count_2) ? count_1 : count_2;
        answer = result > answer ? result : answer;
    }
    return answer;
}


int main(){

    string str = "abcdcba";
    int ans = solution(str);
    cout << ans << endl;

}
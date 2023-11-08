#include <iostream>
#include <string>
using namespace std;



int solution(string s)
{
    int answer = 0;
    int length = s.length();

    // 왼쪽 커서
    // 오른쪽 커서

    for(int i=0;i<length;i++){
        for(int j=length;j>answer;j--){
            int left = i;
            int right = left + j - 1;
            while(left < right && s[left] == s[right]){
                // 왼쪽 커서 오른쪽 커서 조정
                left++;
                right--;
            }
            if(left >= right && answer < j){
                answer = j;
                break;
            }
        }
    }

    return answer;
}

int main(){

    string str;
    str = "abcdcba";

    int answer=0;
    answer = solution(str);
    cout << answer << endl;
}
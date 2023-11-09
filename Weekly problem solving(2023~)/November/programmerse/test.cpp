#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(string s){
    int len = s.length();
    int front = 0;
    int tail = len - 1;

    while(front < tail && s[front] == s[tail]){
        front ++;
        tail --;
    }




    return result;
}





int main(){
    string str = "abcdcba";
    
    int answer = solutioin(str);
    cout << answer << endl;
}
#include <iostream>
#include <string.h>

using namespace std;


int solution(string s){
    int answer = 0;

    int size = s.length();
    int i,j;
    for(i=0;i<size;i++){
        char cur= s[i];
        int my_count = 0;
        int not_count = 0;
        for(j=i;j<size;j++){
            if(s[j]==cur){
                my_count++;
            }else{
                not_count++;
            };
            if(my_count==not_count){
                break;
            }
        };
        i=j;
        answer++;
    }
    return answer;
}
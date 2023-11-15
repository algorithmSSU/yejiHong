#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name){
    int ans;

    // 상하
    for(auto c : name){
        ans+=min(c-'A','Z'-c+1);
    }

    int len = name.length() -1;
    int move = len - 1; // 최대로 이동해줘야 하는 커서 횟수
    // 좌우
    for(int i=0;i<len;i++){
        
        int next = i+1;
        while(next<len && name[next]=='A'){
            next++;
        }
        move = min(move,i+(len-next)+min(i,len-next));
    }
    ans+= move;
    return ans;
}








int main(){
    string name = "JEROEN";
    int result = 0;
    result = solution(name);
    cout << result << endl;
}
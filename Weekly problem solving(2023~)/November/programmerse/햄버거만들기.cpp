#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string str;
    for(int i=0;i<ingredient.size();i++){
        str+=ingredient[i] + '0';
    };

    int pos = 0;
    while(true){
        size_t ret = str.find("1231",pos);
        if(ret==string::npos){
            break;
        }else{
            str.erase(ret,4);
        };
        if(ret>2){
            pos=ret-3;
        };
        answer++;
    }
    
    return answer;
}
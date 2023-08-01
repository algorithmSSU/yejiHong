#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int k, int m, vector<int> sc){
    int answer = 0;

    sort(sc.begin(),sc.end());
    reverse(sc.begin(),sc.end());
    

    int bmin = k+1;
    for(int i=0;i<sc.size();i++){
        bmin = bmin<sc[i]?bmin:sc[i];
        if((i+1)%m==0){
            answer+=bmin*m;
            bmin = k+1;
        }
    };

    
    return answer;
}
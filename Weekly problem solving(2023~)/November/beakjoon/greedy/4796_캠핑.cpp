#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int L, P, V;
    vector<int> answer;

    
    while(1){
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0){
            
            break;
        }

        int closed= P-L;// 사용안됨
        int valid = V/P; // 몫
        int remain = V%P; // 나머지

        int temp = valid * P - (valid * closed);
        if( L < remain){
            remain = L;
        }
        int res= temp + remain;
        answer.emplace_back(res);
    }

    int flag = 1;
    for(auto it :answer){
        cout << "Case " << flag++<< ": "<< it << endl;
    }
    


}